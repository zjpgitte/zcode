
#include "ThreadCache.h"
#include "common.h"
#include "CentralCache.h"


// STL的空间配置器是有 8 字节对齐 [8, 128]
// 最小申请8字节，最多128字节。大于128字节的直接malloc
// STL的空间配置器主要是给容器使用的，容器的每个元素一般不超过128字节。

// 算出size大小内存块在freeList中的位置
// freeList的映射关系是这样的
// 申请                   对应位置               对齐数(bytes)
// [1, 128]               [0, 16)                    8           16
// [129, 1024]            [16, 72)                   16          72
// [1025,8*1024]          [72,128)                   128         128
// [8*1024+1,64*1024]     [128,184)                  1024         
// 意图是控制内存的浪费不超过 12%
// 如果只按8字节对齐，每个线程光存储freeList表就要占用很大一部分空间。
// 如果对齐数较大，则申请小块内存时空间浪费大。因此根据申请内存的大小不同，
// 采用不同的对齐数，但是保证内存浪费率不超过12%
size_t ThreadCache::Index(size_t size){ // size是已经对齐过的数
	assert(size > 0);
	// 对齐数 8    16   128   1024
	//        16   72   128   184
	if (size <= 128) {
		return ((size >> 3) - 1);
	}
	else if (size <= 1024) {
		return 16 + (((size - 128) >> 4) - 1);
	}
	else if (size <= 8 * 1024) {
		return 72 + (((size - 1024) >> 7) - 1);
	}
	else if (size <= 64 * 1024) {
		return 128 + (((size - 8 * 1024) >> 10) - 1);
	}
	else {
		assert(false);
		return -1;
	}	
}



// 申请内存
// 先算出size大小内存挂在freeList中的位置
// 若该位置已经挂了内存直接返回一块，否则从CentralCache取若干个内存块。
void* ThreadCache::Allocate(size_t size){
	size_t i = Index(size); // 算出size内存在freeLsit表的位置

	if (_freeList[i].Empty()) { // freeList[i]中没有内存
		// 找centralcache取若干内存块
		return FetchFromCentralCache(size);
	}
	else {
		return _freeList[i].PopFront();
	}
}


// 从centralcache中取一批内存块
void* ThreadCache::FetchFromCentralCache(size_t size){
	size_t i = Index(size); // size大小的块在CentralCache中的位置

	// 计算本次从CentralCache取内存的个数
	int num = _freeList[i].GetNextSize();
	if (num > SizeClass::MaxSize(size)) { // 大于阈值
		num = SizeClass::MaxSize(size);
	}
	
	// Central中取出多个内存块，用链表链接起来,start,end是链表头尾
	void *start;
	void *end;
	CentralCache::GetInstance()->FetchObjs(start, end, num, size);

	
	void* obj = start; // 记录下第一个

	start = FreeList::NextObj(start);

	_freeList[i].PushRange(start, end);

	// 慢启动增长
	if (_freeList[i].GetNextSize() < SizeClass::MaxSize(size)) {
		_freeList[i].SetNextSize(_freeList[i].GetNextSize() + 1);
	}

	return obj;

}




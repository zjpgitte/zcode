
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
size_t SizeClass::Index(size_t size){ // size是已经对齐过的数
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
	size_t i = SizeClass::Index(size); // 算出size内存在freeLsit表的位置

	if (_freeList[i].Empty()) { // freeList[i]中没有内存
		// 找centralcache取若干内存块
		return FetchFromCentralCache(size);
	}
	else {
		return _freeList[i].PopFront();
	}
}


// 从centralcache中若干个内存对象
void* ThreadCache::FetchFromCentralCache(size_t size){
	size_t i = SizeClass::Index(size); // size大小的块在CentralCache中的位置


	// 从CentralCache取n个对象。
	// n 的大小根据不同场景取不同值。
	// 可以采用慢启动的方式n动态变化，也可以用其它策略。
	int n = _freeList[i].GetNextSize();


	// 从CentralCache取出来 n 个size大小的对象。
	// 输出型参数start,end将这n个对象取出。返回实际取出的个数
	void *start = nullptr, *end = nullptr;
	size_t realN = CentralCache::GetInstance()->FetchObjs(n, size, start, end);
	assert(realN >= 1); 


	// 取来的内存挂到freeList中，并返回第一个
	_freeList[i].PushRange(start, end, realN);
	_freeList[i].UpdateNextSize(size); //慢启动增长
	return _freeList[i].PopFront();
}


void ThreadCache::DeAllocate(void* ptr, size_t size) {
	size_t i = SizeClass::Index(size);

	// 释放内存给_freeList
	_freeList[i].PushFront(ptr);

	// 判断链表是否过长
	JudgeListTooLong(ptr, size);
}

void ThreadCache::JudgeListTooLong(void* ptr, size_t size) {
	size_t i = SizeClass::Index(size);
	FreeList& list = _freeList[i];
	
	//链表过长
	if (list.Size() >= list.GetNextSize()) {
		size_t n = list.GetNextSize();
		// 取出n个对象
		void* start;
		list.PopRange(start, n);

		// 释放给CentralCache
		CentralCache::GetInstance()->ReleaseToSpans(start, n, size);
	}
}


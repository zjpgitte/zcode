
#include "ThreadCache.h"
#include "common.h"

// STL的空间配置器是有 8 字节对齐 [8, 128]
// 最小申请8字节，最多128字节。大于128字节的直接malloc
// STL的空间配置器主要是给容器使用的，容器的每个元素一般不超过128字节。

// 算出size大小内存块在freeList中的位置
// freeList的映射关系是这样的
// 申请                   对应位置               对齐数(bytes)
// [1, 128]               [0, 16)                       8 
// [129, 1024]            [16, 72)                   16 
// [1025,8*1024]          [72,128)                   128
// [8*1024+1,64*1024]     [128,184)                  1024 
// 意图是控制内存的浪费不超过 12%
// 如果只按8字节对齐，每个线程光存储表就要占用很大一部分空间。
// 如果对齐数较大，则申请小块内存时空间浪费大。因此根据申请内存的大小不同，采用不同的
// 对齐数，但是保证内存浪费率不超过12%
size_t ThreadCache::Index(size_t size){
	assert(size > 0);
	
	if (size <= 128) {
		return
	}
	else if (size <= 1024) {
		return ;
	}
	else if (size <= 8 * 1024) {
		return 
	}
	else if (size <= 64 * 1024) {

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

	
	if (freeList[i].Empty()) { // freeList[i]中没有内存
		// 找centralcache取若干内存块
		return FetchFromCentralCache(size);
	}
	else {
		return freeList[i].PopFront();
	}
}





#include "common.h"
#include "ThreadCache.h"

void* tcmalloc(size_t size) {

	if (size <= MAX_SIZE) { //小于64k到threadcache要

		// 每个线程都创建一个私有的threadCache。
		ThreadCache* threadCache = new ThreadCache; //可以用对象池或VirtualAllocate()申请内存
		return threadCache->Allocate(size);

		// 线程池可以用thread local storage.
	}
	else { // 大于64k到pagecache要
		// pache alloc
	}
}
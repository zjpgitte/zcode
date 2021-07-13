
#include "common.h"
#include "ThreadCache.h"
#include "PageCache.h"

void* tcmalloc(size_t sizes) {
	size_t size = SizeClass::RoundUp(sizes);
	if (size <= MAX_SIZE) { //小于64k到threadcache要
		if (tls_threadcache == nullptr) {
			tls_threadcache = new ThreadCache; //可以用对象池或VirtualAllocate()申请内存
		}
		return tls_threadcache->Allocate(size);

		// 线程池可以用thread local storage.
	}
	else { // 大于64k到pagecache要
		Span* span = PageCache::GetInstance()->NewSpan(size >> PAGE_SHIFT);
		return (void*)(span->_pageId << PAGE_SHIFT);
	}
}

void tcfree(void* ptr, size_t size) {
	if (size > MAX_SIZE) {
		// 释放内存到PageCache
		return;
	}

	// 释放内存到ThreadCache
	assert(tls_threadcache);

	tls_threadcache->DeAllocate(ptr, size);
}
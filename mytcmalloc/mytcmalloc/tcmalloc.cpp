
#include "common.h"
#include "ThreadCache.h"
#include "PageCache.h"

void* tcmalloc(size_t sizes) {
	size_t size = SizeClass::RoundUp(sizes);
	if (size <= MAX_SIZE) { //С��64k��threadcacheҪ
		if (tls_threadcache == nullptr) {
			tls_threadcache = new ThreadCache; //�����ö���ػ�VirtualAllocate()�����ڴ�
		}
		return tls_threadcache->Allocate(size);

		// �̳߳ؿ�����thread local storage.
	}
	else { // ����64k��pagecacheҪ
		Span* span = PageCache::GetInstance()->NewSpan(size >> PAGE_SHIFT);
		return (void*)(span->_pageId << PAGE_SHIFT);
	}
}

void tcfree(void* ptr, size_t size) {
	if (size > MAX_SIZE) {
		// �ͷ��ڴ浽PageCache
		return;
	}

	// �ͷ��ڴ浽ThreadCache
	assert(tls_threadcache);

	tls_threadcache->DeAllocate(ptr, size);
}
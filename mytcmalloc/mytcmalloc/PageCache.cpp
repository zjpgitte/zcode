
#include "PageCache.h"

PageCache PageCache::_instance;

Span* PageCache::NewSpan(int k) {
	// 有内存
	if (!_spanList[k].Empty()) {
		return _spanList[k].PopFront();
	}

	//没有内存
	// 到[k + 1, 128]找 m 页
	// 找到 切成 k 页 和 m - k挂到 _spanList[k] 和 _spanList[m - k]上
	for (int i = k + 1; i <= NPAGES; i++) {
		if (!_spanList[i].Empty()) {
			//切成k页和 i - k页
			Span* span = _spanList[i].PopFront();
			span->_n = k;
			Span* splitSpan = new Span;
			splitSpan->_pageId = span->_pageId + span->_n;
			splitSpan->_n = i - k;
			_spanList[k].PushFront(span);
			_spanList[i - k].PushFront(splitSpan);
			return _spanList[k].PopFront();
		}
	}

	// 没找到 SystemAllocate()
	void* mem = SystemAllocate(NPAGES);
	Span* newSpan = new Span;
	newSpan->_pageId = (PageID)mem >> PAGE_SHIFT;
	newSpan->_n = NPAGES;
	_spanList[newSpan->_n].PushFront(newSpan);

	return NewSpan(k);
}


void* PageCache::SystemAllocate(size_t k) {
	return ::SystemAlloc(k);
}

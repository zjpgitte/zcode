
#include "PageCache.h"

PageCache PageCache::_instance;

Span* PageCache::NewSpan(int k) {
	// ���ڴ�
	if (!_spanList[k].Empty()) {
		return _spanList[k].PopFront();
	}

	//û���ڴ�
	// ��[k + 1, 128]�� m ҳ
	// �ҵ� �г� k ҳ �� m - k�ҵ� _spanList[k] �� _spanList[m - k]��
	for (int i = k + 1; i <= NPAGES; i++) {
		if (!_spanList[i].Empty()) {
			//�г�kҳ�� i - kҳ
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

	// û�ҵ� SystemAllocate()
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

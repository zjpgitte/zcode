
#include "PageCache.h"

std::map<PageID, Span*> PageCache::_idSpanMap; // ����ҳ�ź�span��ӳ���ϵ�ı�

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

			//span��ǰk��pageId��span��ӳ���ϵ����.��i-k��pageIdӳ�䵽splitSpan
			for (size_t j = 0; j < splitSpan->_n; j++) {
				_idSpanMap[splitSpan->_pageId + j] = splitSpan; // ��splitSpan������ҳ�ŵ���ӳ������
			}

			_spanList[k].PushFront(span);
			_spanList[i - k].PushFront(splitSpan);
			return _spanList[k].PopFront();
		}
	}

	// ��ϵͳ���롣SystemAllocate()
	void* mem = SystemAllocate(NPAGES);
	Span* newSpan = new Span;
	newSpan->_pageId = (PageID)mem >> PAGE_SHIFT;
	newSpan->_n = NPAGES;

	//����n��ҳ�ź�newSpan��ӳ���ϵ��
	for (size_t i = 0; i < newSpan->_n; i++) {
		_idSpanMap[newSpan->_pageId + i] = newSpan;
	}

	// newSpan�嵽spanList[n]�С�
	_spanList[newSpan->_n].PushFront(newSpan);

	return NewSpan(k);
}


void* PageCache::SystemAllocate(size_t k) {
	return ::SystemAlloc(k);
}


//span�ͷŸ�PageCache
void PageCache::ReleaseSpanToPageCache(Span* span) {
	
	// ǰ�ϲ�
	while (1) {
		PageID preId = span->_pageId - 1;
		std::map<PageID, Span*>::iterator ret = _idSpanMap.find(preId);
		if (ret == _idSpanMap.end()) {//û��ǰҳ
			break;
		}

		Span* preSpan = ret->second;
		if (preSpan->_useCount != 0) {// ���ǿ���ҳ
			break;
		}

		//���Ժϲ�
		// ǰҳȡ����
		_spanList[preSpan->_n].Erase(preSpan);

		span->_pageId = preSpan->_pageId;
		span->_n += preSpan->_n;
		
		// �ı�ӳ���ϵ
		for (size_t i = 0; i < preSpan->_n; i++) {
			_idSpanMap[preSpan->_pageId + i] = span;
		}

		//delete preSpan;
	}

	// ��ϲ�
	while (1) {
		PageID nextId = span->_pageId + span->_n;
		std::map<PageID, Span*>::iterator ret = _idSpanMap.find(nextId);
		if (ret == _idSpanMap.end()) {
			break;
		}

		Span* nextSpan = ret->second;
		if (nextSpan->_useCount != 0) {
			break;
		}

		span->_n += nextSpan->_n;
		for (size_t i = 0; i < nextSpan->_n; i++) {
			_idSpanMap[nextSpan->_pageId + i] = span;
		}

		//delete nextSpan;
	}

	// �жϺϲ���Ĵ�С
	if (span->_n >= NPAGES) {
		// ɾ��ӳ���ϵ
		for (size_t i = 0; i < span->_n; i++) {
			_idSpanMap.erase(span->_pageId + i);
		}
		void* ptr = (void*)(span->_pageId << PAGE_SHIFT);
		// �黹��ϵͳ
		SystemFree(ptr);
		//delete span;
	}
	else { //�ҵ���Ӧ����ĺ���
		_spanList[span->_n].PushFront(span);
	}
}

void PageCache::SystemFree(void* ptr) {
	::SystemFree(ptr);
}


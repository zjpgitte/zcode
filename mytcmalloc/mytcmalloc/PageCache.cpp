
#include "PageCache.h"

std::map<PageID, Span*> PageCache::_idSpanMap; // 建立页号和span的映射关系的表

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

			//span的前k个pageId和span的映射关系不变.后i-k个pageId映射到splitSpan
			for (size_t j = 0; j < splitSpan->_n; j++) {
				_idSpanMap[splitSpan->_pageId + j] = splitSpan; // 把splitSpan的所有页号的它映射起来
			}

			_spanList[k].PushFront(span);
			_spanList[i - k].PushFront(splitSpan);
			return _spanList[k].PopFront();
		}
	}

	// 向系统申请。SystemAllocate()
	void* mem = SystemAllocate(NPAGES);
	Span* newSpan = new Span;
	newSpan->_pageId = (PageID)mem >> PAGE_SHIFT;
	newSpan->_n = NPAGES;

	//建立n个页号和newSpan的映射关系。
	for (size_t i = 0; i < newSpan->_n; i++) {
		_idSpanMap[newSpan->_pageId + i] = newSpan;
	}

	// newSpan插到spanList[n]中。
	_spanList[newSpan->_n].PushFront(newSpan);

	return NewSpan(k);
}


void* PageCache::SystemAllocate(size_t k) {
	return ::SystemAlloc(k);
}


//span释放给PageCache
void PageCache::ReleaseSpanToPageCache(Span* span) {
	
	// 前合并
	while (1) {
		PageID preId = span->_pageId - 1;
		std::map<PageID, Span*>::iterator ret = _idSpanMap.find(preId);
		if (ret == _idSpanMap.end()) {//没有前页
			break;
		}

		Span* preSpan = ret->second;
		if (preSpan->_useCount != 0) {// 不是空闲页
			break;
		}

		//可以合并
		// 前页取下来
		_spanList[preSpan->_n].Erase(preSpan);

		span->_pageId = preSpan->_pageId;
		span->_n += preSpan->_n;
		
		// 改变映射关系
		for (size_t i = 0; i < preSpan->_n; i++) {
			_idSpanMap[preSpan->_pageId + i] = span;
		}

		//delete preSpan;
	}

	// 后合并
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

	// 判断合并后的大小
	if (span->_n >= NPAGES) {
		// 删除映射关系
		for (size_t i = 0; i < span->_n; i++) {
			_idSpanMap.erase(span->_pageId + i);
		}
		void* ptr = (void*)(span->_pageId << PAGE_SHIFT);
		// 归还给系统
		SystemFree(ptr);
		//delete span;
	}
	else { //挂到对应链表的后面
		_spanList[span->_n].PushFront(span);
	}
}

void PageCache::SystemFree(void* ptr) {
	::SystemFree(ptr);
}



#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_instance; // ����static���ͱ���

// ��spanList[i]��һ�����ڴ��span���أ���û����pageCacheҪһ��
Span* CentralCache::GetOneSpan(SpanList& list, size_t size){

	// �ҵ�һ�����ڴ��spanֱ�ӷ���
	Span* it = list.Begin();
	while (it != list.End()) {
		if (it->_list != nullptr)  return it; 

		it = it->_next;
	}

	// ��ʱû��һ�����ڴ��span��
	// ��PageCacheҪ k ҳ��span��
	int k = ((SizeClass::MaxSize(size) * size) >> 10) + 1;
	Span* span = PageCache::GetInstance()->NewSpan(k);
	span->_objSize = size;
	//��������span�г�size��С�Ķ�������������span��
	DivideSpan(span, size);

	list.PushFront(span);
	return list.Begin();
}

//��CentralCache��ȡn��size��С������������������ʵ��ȡ���Ĵ�С
size_t CentralCache::FetchObjs(size_t n, size_t size, void*& start, void*& end){
	size_t i = SizeClass::Index(size);

	// ��spanList[i]��ȡһ�����ڴ��span
	Span* span = GetOneSpan(_spanList[i], size);
	assert(span->_list);


	// ȡ��n��size��С���ڴ档start,end��¼ͷβ��
	void* cur = span->_list;
	void* pre = cur;
	start = cur;
	size_t j = 0;
	while (cur != nullptr && j < n) {
		pre = cur;
		cur = FreeList::NextObj(cur);
		j++;
	}
	end = pre;
	FreeList::NextObj(end) = nullptr;
	span->_list = cur;

	span->_useCount += j; // ���ü�������
	return j;
}

void CentralCache::DivideSpan(Span* span, size_t size) {
	char* end = (char*)((span->_pageId + span->_n) << PAGE_SHIFT);
	char* cur = (char*)(span->_pageId << PAGE_SHIFT);
	char* next = cur + size;
	while (next + size <= end) {
		FreeList::NextObj(cur) = next;
		cur = next;
		next += size;
	}
	FreeList::NextObj(cur) = nullptr;
	span->_list = (void*)(span->_pageId << PAGE_SHIFT);
}




void CentralCache::ReleaseToSpans(void* ptr, size_t n, size_t size) {
	size_t i = SizeClass::Index(size);

	void *next = FreeList::NextObj(ptr);
	while (ptr != nullptr) {
		void *next = FreeList::NextObj(ptr);
		// �ҵ�ptr�����Ӧ��span
		Span* span = MapObjToSpan(ptr);
		// ͷ��
		FreeList::NextObj(ptr) = span->_list;
		span->_list = ptr;
		span->_useCount--;

	    // span�Ķ��󶼻�����
		if (span->_useCount == 0) {
			_spanList[i].Erase(span);
			span->_list = nullptr; // listֻ��CentralCache��ʹ��
			// �ͷŸ�PageCache
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}

		ptr = next;
	}
}


// ���ݵ�ַ���span
Span* CentralCache::MapObjToSpan(void* ptr) {
	assert(ptr);

	// ͬһ��ҳ�ڵĲ�ͬ��ַҳ����ͬ��
	PageID id = (PageID)ptr >> 12;

	auto ret = PageCache::_idSpanMap.find(id);

	return ret->second;
}


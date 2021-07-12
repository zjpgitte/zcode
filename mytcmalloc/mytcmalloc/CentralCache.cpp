
#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"

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
	size_t i = 0;
	while (cur != nullptr && i < n) {
		pre = cur;
		cur = FreeList::NextObj(cur);
		i++;
	}
	end = pre;
	FreeList::NextObj(end) = nullptr;
	span->_list = cur;

	span->_useCount += i; // ���ü�������
	return i;
}

void CentralCache::DivideSpan(Span* span, size_t size) {
	char *end = (char*)((span->_pageId + span->_n) << 12);
	char* cur = (char*)span->_list;
	char* next = cur + size;
	while (next + size <= end) {
		FreeList::NextObj(cur) = next;
		cur = next;
		next += size;
	}
	FreeList::NextObj(cur) = nullptr;
}

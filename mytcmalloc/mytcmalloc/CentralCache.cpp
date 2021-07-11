
#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"

// ��spanList[i]��һ�����ڴ��span���أ���û����pageCacheҪһ��
Span* CentralCache::GetOneSpan(SpanList& list, size_t size){

	Span* span = list.Begin();
	while (span != list.End()) {
		if (span->_list) return span; //span���ڴ�ֱ�ӷ���

		span = span->_next;
	}

	// �ߵ���˵��centralCacheû�����ڴ��span��Ӧ����pageCaheҪһ����������ҳ��span

	// ����Ҫ����ҳ
	int n = SizeClass::MaxSize(size) * size / 1024;
	Span* span = PageCache::GetInstance()->NewSpan(n);

	// �õ����span������С�ҵ�list��
	list.PushFront(span); // �ȹҵ�list��
	//���з�
	char* start = (char*)span->_list;
	char* cur = start;
	for (int i = size; i < (n << 10) - size; i += size){
		char* next = start + i;
		FreeList::NextObj(cur) = next;
		cur = next;
	}
	FreeList::NextObj(cur) = nullptr;

	return span;
}

// ��CentralCacheȡnum��size��С�Ķ��󣬲��õ�������������������ͷ��
void CentralCache::FetchObjs(void*& start, void*& end, int num, size_t size){
	size_t i = ThreadCache::Index(size);

	// ��spanList[i]��ȡһ�����ڴ��span
	Span* span = GetOneSpan(_spanList[i], size);
	assert(span->_list);

	// ��spanȡ��num��.����num���ж��ٸ�ȡ���ٸ�
	start = span->_list;
	end = start;
	void* pre = end;

	while (end && num > 0){
		pre = end;
		end = FreeList::NextObj(end);
		num--;
	}

	span->_list = end;
	if (pre) {
		FreeList::NextObj(pre) = nullptr;
	}
	end = pre;
}
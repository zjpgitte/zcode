#pragma once
#include "Common.h"

class PageCache
{
public:
	// ��ϵͳ����kҳ�ڴ�ҵ���������
	void* SystemAllocPage(size_t k);

	Span* NewSpan(size_t k);

private:
	SpanList _spanList[NPAGES];	// ��ҳ��ӳ��

	std::map<PageID, Span*> _idSpanMap;
};

static PageCache pageCache;

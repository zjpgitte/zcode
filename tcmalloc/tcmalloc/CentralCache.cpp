#include "CentralCache.h"
#include "PageCache.h"

Span* CentralCache::GetOneSpan(SpanList& list, size_t size)
{
	// ����spanlist��ȥ�һ����ڴ��span
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->_list)
		{
			return it;
		}

		it = it->_next;
	}

	// �ߵ����������span��û���ڴ��ˣ�ֻ����pagecache
	Span* span = pageCache.NewSpan(SizeClass::NumMovePage(size));
	// �зֺù���list��

	return span;
}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t size)
{
	size_t i = SizeClass::Index(size);
	Span* span = GetOneSpan(_spanLists[i], size);

	// �ҵ�һ���ж����span���ж��ٸ�����
	size_t j = 1;
	start = span->_list;
	void* cur = start;
	void* prev = start;
	while (j <= n && cur != nullptr)
	{
		prev = cur;
		cur = NextObj(cur);
		++j;
		span->_usecount++;
	}

	span->_list = cur;
	end = prev;
	NextObj(prev) = nullptr;

	return j-1;
}

void ReleaseListToSpans(void* start, size_t byte_size)
{
	while (start)
	{

	}
}

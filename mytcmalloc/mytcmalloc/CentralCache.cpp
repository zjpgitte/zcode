
#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"

// 从spanList[i]找一块有内存的span返回，若没有找pageCache要一块
Span* CentralCache::GetOneSpan(SpanList& list, size_t size){

	// 找到一块有内存的span直接返回
	Span* it = list.Begin();
	while (it != list.End()) {
		if (it->_list != nullptr)  return it; 

		it = it->_next;
	}

	// 此时没有一个有内存的span。
	// 找PageCache要 k 页的span。
	int k = ((SizeClass::MaxSize(size) * size) >> 10) + 1;
	Span* span = PageCache::GetInstance()->NewSpan(k);

	//将连续的span切成size大小的对象链接起来的span。
	DivideSpan(span, size);

	list.PushFront(span);
	return list.Begin();
}

//从CentralCache中取n个size大小对象链接起来，返回实际取出的大小
size_t CentralCache::FetchObjs(size_t n, size_t size, void*& start, void*& end){
	size_t i = SizeClass::Index(size);

	// 从spanList[i]获取一个有内存的span
	Span* span = GetOneSpan(_spanList[i], size);
	assert(span->_list);


	// 取出n个size大小的内存。start,end记录头尾。
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

	span->_useCount += i; // 引用计数增加
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

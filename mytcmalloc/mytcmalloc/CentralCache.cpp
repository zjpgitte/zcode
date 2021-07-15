
#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_instance; // 定义static类型变量

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
	span->_objSize = size;
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
	size_t j = 0;
	while (cur != nullptr && j < n) {
		pre = cur;
		cur = FreeList::NextObj(cur);
		j++;
	}
	end = pre;
	FreeList::NextObj(end) = nullptr;
	span->_list = cur;

	span->_useCount += j; // 引用计数增加
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
		// 找到ptr对象对应的span
		Span* span = MapObjToSpan(ptr);
		// 头插
		FreeList::NextObj(ptr) = span->_list;
		span->_list = ptr;
		span->_useCount--;

	    // span的对象都回来了
		if (span->_useCount == 0) {
			_spanList[i].Erase(span);
			span->_list = nullptr; // list只在CentralCache中使用
			// 释放给PageCache
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}

		ptr = next;
	}
}


// 根据地址求出span
Span* CentralCache::MapObjToSpan(void* ptr) {
	assert(ptr);

	// 同一个页内的不同地址页号相同。
	PageID id = (PageID)ptr >> 12;

	auto ret = PageCache::_idSpanMap.find(id);

	return ret->second;
}


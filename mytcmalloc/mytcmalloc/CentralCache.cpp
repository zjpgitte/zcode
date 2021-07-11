
#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"

// 从spanList[i]找一块有内存的span返回，若没有找pageCache要一块
Span* CentralCache::GetOneSpan(SpanList& list, size_t size){

	Span* span = list.Begin();
	while (span != list.End()) {
		if (span->_list) return span; //span有内存直接返回

		span = span->_next;
	}

	// 走到这说明centralCache没有有内存的span，应该找pageCahe要一个包含若干页的span

	// 计算要多少页
	int n = SizeClass::MaxSize(size) * size / 1024;
	Span* span = PageCache::GetInstance()->NewSpan(n);

	// 拿到大块span后再切小挂到list中
	list.PushFront(span); // 先挂到list上
	//再切分
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

// 从CentralCache取num个size大小的对象，并用单链表链接起来。返回头。
void CentralCache::FetchObjs(void*& start, void*& end, int num, size_t size){
	size_t i = ThreadCache::Index(size);

	// 从spanList[i]获取一个有内存的span
	Span* span = GetOneSpan(_spanList[i], size);
	assert(span->_list);

	// 从span取出num个.不足num个有多少个取多少个
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
#pragma once
#include "common.h"

// central中Span管理若干个页的内存
// 这些内存被切分成不同大小的内存，以单链表的形式链接起来
class Span{
public:
	PageID _pageId;
	size_t _n = 0;
	size_t _useCount = 0;

	void* _list = nullptr;

	Span* _prev = nullptr;
	Span* _next = nullptr;
};

//spanList是一个带头双向循环链表。
//
class SpanList{
public:
	SpanList(){
		_head = new Span; //new换成对象池或virtualAllocate
		_head->_next = _head;
		_head->_prev = _head;
	}
	bool Empty() {
		return _head->_next == _head;
	}

	// 链表头和尾
	Span* Begin(){
		return _head->_next;
	}
	Span* End(){
		return _head;
	}

	// 链表的操作
	// 头插
	void PushFront(Span* s){
		Span* next = _head->_next;
		s->_next = next;
		next->_prev = s;
		s->_prev = _head;
		_head->_next = s;
	}

	// 头删
	Span* PopFront(){
		Span* first = _head->_next;
		Span* second = first->_next;
		_head->_next = second;
		second->_prev = _head;

		first->_next = nullptr;
		first->_prev = nullptr;
		return first;
	}


private:
	Span* _head;
};

// 设计成单例模式,将构造函数和拷贝构造封死,程序中不可能再出现其它对象
class CentralCache{
public:
	static CentralCache* GetInstance(){

		return &_instance;
	}

	// 从CentralCache获取n个size大小的对象
	//  start，end是n个size内存块链接的头和尾。
	size_t FetchObjs(size_t n, size_t size, void*& start, void*& end);

	// 从list中取有对象的span
	Span* GetOneSpan(SpanList& list, size_t size);

	// 切分span
	void DivideSpan(Span* span, size_t size);

	void ReleaseToSpans(void* ptr, size_t n, size_t size);

private:
	SpanList _spanList[NFREELISTS];

private:
	static CentralCache _instance;
	CentralCache(){};
	CentralCache(const CentralCache& c) = delete;
};


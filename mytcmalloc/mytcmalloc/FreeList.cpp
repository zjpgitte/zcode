
#include "common.h"

//取内存的前4或8字节（取决于机器是64位还是32位）
void*& FreeList::NextObj(void* obj){
	return *((void**)obj);
}

bool FreeList::Empty(){
	return _head == nullptr;
}


void FreeList::PushFront(void* obj){ // 头插  obj的大小是确定的
	NextObj(obj) = _head;
	_head = obj;
	_n += 1;
}

void* FreeList::PopFront(){ // 头删
	void* temp = _head;
	_head = NextObj(_head);
	NextObj(temp) = nullptr;
	_n -= 1;
	return temp;
}

// 头插
void FreeList::PushRange(void* start, void* end, size_t n){
	NextObj(end) = _head;
	_head = start;
	_n += n;
}

// 弹出n个对象
void FreeList::PopRange(void*& start, size_t n) {
	start = _head;
	void* cur = _head;
	for (size_t i = 0; i < n - 1; i++) {
		cur = NextObj(cur);
	}
	_head = NextObj(cur);
	NextObj(cur) = nullptr;
	_n -= n;
}





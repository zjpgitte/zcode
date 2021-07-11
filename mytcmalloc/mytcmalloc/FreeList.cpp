
#include "common.h"

//取内存的前4或8字节（取决于机器是64位还是32位）
void*& FreeList::NextObj(void* obj){
	return *((void**)obj);
}

bool FreeList::Empty(){
	return _head == nullptr;
}

void FreeList::PushFront(void* obj){ // 头插
	NextObj(obj) = _head;
	_head = obj;
}

void* FreeList::PopFront(){ // 头删
	void* temp = _head;
	_head = NextObj(_head);
	return temp;
}

// 头插
void FreeList::PushRange(void* start, void* end){
	NextObj(end) = _head;
	_head = start;
}


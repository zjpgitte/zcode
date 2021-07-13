
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
	_size += 1;
}

void* FreeList::PopFront(){ // 头删
	void* temp = _head;
	_head = NextObj(_head);
	_size -= 1;
	return temp;
}

// 头插
void FreeList::PushRange(void* start, void* end, size_t n){
	NextObj(end) = _head;
	_head = start;
	_size += n;
}

// 弹出size个对象
void FreeList::PopRange(void*& start, size_t size) {
	start = _head;
	void* cur = _head;
	for (int i = 0; i < size - 1; i++) {
		cur = NextObj(cur);
	}
	_head = NextObj(cur);
	NextObj(cur) = nullptr;

}





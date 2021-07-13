
#include "common.h"

//ȡ�ڴ��ǰ4��8�ֽڣ�ȡ���ڻ�����64λ����32λ��
void*& FreeList::NextObj(void* obj){
	return *((void**)obj);
}

bool FreeList::Empty(){
	return _head == nullptr;
}

void FreeList::PushFront(void* obj){ // ͷ��
	NextObj(obj) = _head;
	_head = obj;
	_size += 1;
}

void* FreeList::PopFront(){ // ͷɾ
	void* temp = _head;
	_head = NextObj(_head);
	_size -= 1;
	return temp;
}

// ͷ��
void FreeList::PushRange(void* start, void* end, size_t n){
	NextObj(end) = _head;
	_head = start;
	_size += n;
}

// ����size������
void FreeList::PopRange(void*& start, size_t size) {
	start = _head;
	void* cur = _head;
	for (int i = 0; i < size - 1; i++) {
		cur = NextObj(cur);
	}
	_head = NextObj(cur);
	NextObj(cur) = nullptr;

}






#include "common.h"

//ȡ�ڴ��ǰ4��8�ֽڣ�ȡ���ڻ�����64λ����32λ��
void*& FreeList::NextObj(void* obj){
	return *((void**)obj);
}

bool FreeList::Empty(){
	return _head;
}

void FreeList::PushFront(void* obj){ // ͷ��
	NextObj(obj) = _head;
	_head = obj;
}

void* FreeList::PopFront(){ // ͷɾ
	void* temp = _head;
	_head = NextObj(_head);
	return temp;
}


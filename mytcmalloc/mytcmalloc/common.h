#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

const int MAX_SIZE = 64 * 1024;

class FreeList{
public:
	void*& NextObj(void* obj);

	bool Empty();

	// ͷ���ڴ��
	void PushFront(void* obj);

	// ͷɾ�ڴ��
	void* PopFront();

private:
	void* _head = nullptr;
};
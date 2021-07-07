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

	// 头插内存块
	void PushFront(void* obj);

	// 头删内存块
	void* PopFront();

private:
	void* _head = nullptr;
};

#pragma once

#include "common.h"

class ThreadCache{
public:
	// ���ݴ�С���λ�á� ��СΪsize���ڴ��ӳ�䵽FreeList���е�λ��
	static size_t Index(size_t size);

	// threadcache�����ڴ档����Ĵ�СҪ���ֽڶ��롣
	void* Allocate(size_t size); 

	// ��centralcache��ȥ�ڴ�
	void* FetchFromCentralCache(size_t size);

private:
	FreeList freeList[16];
};
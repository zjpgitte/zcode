
#pragma once
#pragma once

#include "common.h"

class ThreadCache{
public:

	// threadcache�����ڴ档����Ĵ�СҪ���ֽڶ��롣
	void* Allocate(size_t size); 

	//��CentralCacheҪ�ڴ�
	void* FetchFromCentralCache(size_t size);

private:
	FreeList _freeList[NFREELISTS];
};
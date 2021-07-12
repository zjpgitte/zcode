
#pragma once
#pragma once

#include "common.h"

class ThreadCache{
public:

	// threadcache申请内存。申请的大小要按字节对齐。
	void* Allocate(size_t size); 

	//向CentralCache要内存
	void* FetchFromCentralCache(size_t size);

private:
	FreeList _freeList[NFREELISTS];
};
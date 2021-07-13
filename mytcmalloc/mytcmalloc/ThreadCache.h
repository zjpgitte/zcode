
#pragma once
#pragma once

#include "common.h"

class ThreadCache{
public:

	// threadcache申请内存。申请的大小要按字节对齐。
	void* Allocate(size_t size); 

	//向CentralCache要内存
	void* FetchFromCentralCache(size_t size);

	// 释放内存到ThreadCache
	void DeAllocate(void* ptr, size_t size);

	void JudgeListTooLong(void* ptr, size_t size);

private:
	FreeList _freeList[NFREELISTS];
};

static __declspec(thread) ThreadCache* tls_threadcache = nullptr;

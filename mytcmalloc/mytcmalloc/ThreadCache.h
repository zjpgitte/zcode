
#pragma once
#pragma once

#include "common.h"

class ThreadCache{
public:

	// threadcache�����ڴ档����Ĵ�СҪ���ֽڶ��롣
	void* Allocate(size_t size); 

	//��CentralCacheҪ�ڴ�
	void* FetchFromCentralCache(size_t size);

	// �ͷ��ڴ浽ThreadCache
	void DeAllocate(void* ptr, size_t size);

	void JudgeListTooLong(void* ptr, size_t size);

private:
	FreeList _freeList[NFREELISTS];
};

static __declspec(thread) ThreadCache* tls_threadcache = nullptr;


#pragma once

#include "common.h"

class ThreadCache{
public:
	// 根据大小算出位置。 大小为size的内存块映射到FreeList表中的位置
	static size_t Index(size_t size);

	// threadcache申请内存。申请的大小要按字节对齐。
	void* Allocate(size_t size); 

	// 从centralcache中去内存
	void* FetchFromCentralCache(size_t size);

private:
	FreeList freeList[16];
};
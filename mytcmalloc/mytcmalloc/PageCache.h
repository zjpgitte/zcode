#pragma once

#include "common.h"
#include "CentralCache.h"


// PageCache也要设计成单例模式。整个进程只有一个PageCache
class PageCache{
public:
	static PageCache* GetInstance(){
		return &_instance;
	}

	// pageCache取n页大小的span
	Span* NewSpan(int n); 

private:
	SpanList _spanList[NPAGES];

private:
	static PageCache _instance;
	PageCache(){};
	PageCache(const PageCache& p) = delete;
};

PageCache PageCache::_instance;

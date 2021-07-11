#pragma once

#include "common.h"
#include "CentralCache.h"


// PageCacheҲҪ��Ƴɵ���ģʽ����������ֻ��һ��PageCache
class PageCache{
public:
	static PageCache* GetInstance(){
		return &_instance;
	}

	// pageCacheȡnҳ��С��span
	Span* NewSpan(int n); 

private:
	SpanList _spanList[NPAGES];

private:
	static PageCache _instance;
	PageCache(){};
	PageCache(const PageCache& p) = delete;
};

PageCache PageCache::_instance;

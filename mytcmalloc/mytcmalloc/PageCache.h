#pragma once
#include "common.h"
#include "CentralCache.h"


// PageCache也要设计成单例模式。整个进程只有一个PageCache
class PageCache{
public:
	static PageCache* GetInstance(){
		return &_instance;
	}

	// 向PageCache取k页大小的span
	Span* NewSpan(int k); 

	// 向系统要K页
	void* SystemAllocate(size_t k);

	// 想系统释放
	void SystemFree(void* ptr);

	//span释放给PageCache
	void ReleaseSpanToPageCache(Span* span);

public:
	static std::map<PageID, Span*> _idSpanMap; // 建立页号和span的映射关系的表
private:
	SpanList _spanList[NPAGES + 1];

private:
	static PageCache _instance;
	PageCache(){};
	PageCache(const PageCache& p) = delete;
};


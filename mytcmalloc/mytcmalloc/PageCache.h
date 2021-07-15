#pragma once
#include "common.h"
#include "CentralCache.h"


// PageCacheҲҪ��Ƴɵ���ģʽ����������ֻ��һ��PageCache
class PageCache{
public:
	static PageCache* GetInstance(){
		return &_instance;
	}

	// ��PageCacheȡkҳ��С��span
	Span* NewSpan(int k); 

	// ��ϵͳҪKҳ
	void* SystemAllocate(size_t k);

	// ��ϵͳ�ͷ�
	void SystemFree(void* ptr);

	//span�ͷŸ�PageCache
	void ReleaseSpanToPageCache(Span* span);

public:
	static std::map<PageID, Span*> _idSpanMap; // ����ҳ�ź�span��ӳ���ϵ�ı�
private:
	SpanList _spanList[NPAGES + 1];

private:
	static PageCache _instance;
	PageCache(){};
	PageCache(const PageCache& p) = delete;
};


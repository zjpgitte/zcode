
#include "PageCache.h"


Span* PageCache::NewSpan(int k) {
	// 有内存
	if (!_spanList[k].Empty()) {

	}

	//没有内存
	// 到[k + 1, 128]找 m 页
	// 找到 切成 k 页 和 m - k挂到 _spanList[k] 和 _spanList[m - k]上

	// 没找到 SystemAllocate()
}

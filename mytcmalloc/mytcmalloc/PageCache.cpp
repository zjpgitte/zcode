
#include "PageCache.h"


Span* PageCache::NewSpan(int k) {
	// ���ڴ�
	if (!_spanList[k].Empty()) {

	}

	//û���ڴ�
	// ��[k + 1, 128]�� m ҳ
	// �ҵ� �г� k ҳ �� m - k�ҵ� _spanList[k] �� _spanList[m - k]��

	// û�ҵ� SystemAllocate()
}

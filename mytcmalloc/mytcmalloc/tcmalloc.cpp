
#include "common.h"
#include "ThreadCache.h"

void* tcmalloc(size_t size) {

	if (size <= MAX_SIZE) { //С��64k��threadcacheҪ

		// ÿ���̶߳�����һ��˽�е�threadCache��
		ThreadCache* threadCache = new ThreadCache; //�����ö���ػ�VirtualAllocate()�����ڴ�
		return threadCache->Allocate(size);

		// �̳߳ؿ�����thread local storage.
	}
	else { // ����64k��pagecacheҪ
		// pache alloc
	}
}
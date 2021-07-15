
#include "ThreadCache.h"
#include "common.h"
#include "CentralCache.h"

// STL�Ŀռ����������� 8 �ֽڶ��� [8, 128]
// ��С����8�ֽڣ����128�ֽڡ�����128�ֽڵ�ֱ��malloc
// STL�Ŀռ���������Ҫ�Ǹ�����ʹ�õģ�������ÿ��Ԫ��һ�㲻����128�ֽڡ�

// ���size��С�ڴ����freeList�е�λ��
// freeList��ӳ���ϵ��������
// ����                   ��Ӧλ��               ������(bytes)
// [1, 128]               [0, 16)                    8           16
// [129, 1024]            [16, 72)                   16          72
// [1025,8*1024]          [72,128)                   128         128
// [8*1024+1,64*1024]     [128,184)                  1024         
// ��ͼ�ǿ����ڴ���˷Ѳ����� 12%
// ���ֻ��8�ֽڶ��룬ÿ���̹߳�洢freeList���Ҫռ�úܴ�һ���ֿռ䡣
// ����������ϴ�������С���ڴ�ʱ�ռ��˷Ѵ���˸��������ڴ�Ĵ�С��ͬ��
// ���ò�ͬ�Ķ����������Ǳ�֤�ڴ��˷��ʲ�����12%
size_t SizeClass::Index(size_t size){ // size���Ѿ����������
	assert(size > 0);
	// ������ 8    16   128   1024
	//        16   72   128   184
	if (size <= 128) {
		return ((size >> 3) - 1);
	}
	else if (size <= 1024) {
		return 16 + (((size - 128) >> 4) - 1);
	}
	else if (size <= 8 * 1024) {
		return 72 + (((size - 1024) >> 7) - 1);
	}
	else if (size <= 64 * 1024) {
		return 128 + (((size - 8 * 1024) >> 10) - 1);
	}
	else {
		assert(false);
		return -1;
	}	
}



// �����ڴ�
// �����size��С�ڴ����freeList�е�λ��
// ����λ���Ѿ������ڴ�ֱ�ӷ���һ�飬�����CentralCacheȡ���ɸ��ڴ�顣
void* ThreadCache::Allocate(size_t size){
	size_t i = SizeClass::Index(size); // ���size�ڴ���freeLsit���λ��

	if (_freeList[i].Empty()) { // freeList[i]��û���ڴ�
		// ��centralcacheȡ�����ڴ��
		return FetchFromCentralCache(size);
	}
	else {
		return _freeList[i].PopFront();
	}
}


// ��centralcache�����ɸ��ڴ����
void* ThreadCache::FetchFromCentralCache(size_t size){
	size_t i = SizeClass::Index(size); // size��С�Ŀ���CentralCache�е�λ��


	// ��CentralCacheȡn������
	// n �Ĵ�С���ݲ�ͬ����ȡ��ֵͬ��
	// ���Բ����������ķ�ʽn��̬�仯��Ҳ�������������ԡ�
	int n = _freeList[i].GetNextSize();


	// ��CentralCacheȡ���� n ��size��С�Ķ���
	// ����Ͳ���start,end����n������ȡ��������ʵ��ȡ���ĸ���
	void *start = nullptr, *end = nullptr;
	size_t realN = CentralCache::GetInstance()->FetchObjs(n, size, start, end);
	assert(realN >= 1); 


	// ȡ�����ڴ�ҵ�freeList�У������ص�һ��
	_freeList[i].PushRange(start, end, realN);
	_freeList[i].UpdateNextSize(size); //����������
	return _freeList[i].PopFront();
}


void ThreadCache::DeAllocate(void* ptr, size_t size) {
	size_t i = SizeClass::Index(size);

	// �ͷ��ڴ��_freeList
	_freeList[i].PushFront(ptr);

	// �ж������Ƿ����
	JudgeListTooLong(ptr, size);
}

void ThreadCache::JudgeListTooLong(void* ptr, size_t size) {
	size_t i = SizeClass::Index(size);
	FreeList& list = _freeList[i];
	
	//�������
	if (list.Size() >= list.GetNextSize()) {
		size_t n = list.GetNextSize();
		// ȡ��n������
		void* start;
		list.PopRange(start, n);

		// �ͷŸ�CentralCache
		CentralCache::GetInstance()->ReleaseToSpans(start, n, size);
	}
}


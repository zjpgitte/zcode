
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
size_t ThreadCache::Index(size_t size){ // size���Ѿ����������
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
	size_t i = Index(size); // ���size�ڴ���freeLsit���λ��

	if (_freeList[i].Empty()) { // freeList[i]��û���ڴ�
		// ��centralcacheȡ�����ڴ��
		return FetchFromCentralCache(size);
	}
	else {
		return _freeList[i].PopFront();
	}
}


// ��centralcache��ȡһ���ڴ��
void* ThreadCache::FetchFromCentralCache(size_t size){
	size_t i = Index(size); // size��С�Ŀ���CentralCache�е�λ��

	// ���㱾�δ�CentralCacheȡ�ڴ�ĸ���
	int num = _freeList[i].GetNextSize();
	if (num > SizeClass::MaxSize(size)) { // ������ֵ
		num = SizeClass::MaxSize(size);
	}
	
	// Central��ȡ������ڴ�飬��������������,start,end������ͷβ
	void *start;
	void *end;
	CentralCache::GetInstance()->FetchObjs(start, end, num, size);

	
	void* obj = start; // ��¼�µ�һ��

	start = FreeList::NextObj(start);

	_freeList[i].PushRange(start, end);

	// ����������
	if (_freeList[i].GetNextSize() < SizeClass::MaxSize(size)) {
		_freeList[i].SetNextSize(_freeList[i].GetNextSize() + 1);
	}

	return obj;

}




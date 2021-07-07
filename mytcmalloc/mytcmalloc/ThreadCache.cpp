
#include "ThreadCache.h"
#include "common.h"

// STL�Ŀռ����������� 8 �ֽڶ��� [8, 128]
// ��С����8�ֽڣ����128�ֽڡ�����128�ֽڵ�ֱ��malloc
// STL�Ŀռ���������Ҫ�Ǹ�����ʹ�õģ�������ÿ��Ԫ��һ�㲻����128�ֽڡ�

// ���size��С�ڴ����freeList�е�λ��
// freeList��ӳ���ϵ��������
// ����                   ��Ӧλ��               ������(bytes)
// [1, 128]               [0, 16)                       8 
// [129, 1024]            [16, 72)                   16 
// [1025,8*1024]          [72,128)                   128
// [8*1024+1,64*1024]     [128,184)                  1024 
// ��ͼ�ǿ����ڴ���˷Ѳ����� 12%
// ���ֻ��8�ֽڶ��룬ÿ���̹߳�洢���Ҫռ�úܴ�һ���ֿռ䡣
// ����������ϴ�������С���ڴ�ʱ�ռ��˷Ѵ���˸��������ڴ�Ĵ�С��ͬ�����ò�ͬ��
// �����������Ǳ�֤�ڴ��˷��ʲ�����12%
size_t ThreadCache::Index(size_t size){
	assert(size > 0);
	
	if (size <= 128) {
		return
	}
	else if (size <= 1024) {
		return ;
	}
	else if (size <= 8 * 1024) {
		return 
	}
	else if (size <= 64 * 1024) {

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

	
	if (freeList[i].Empty()) { // freeList[i]��û���ڴ�
		// ��centralcacheȡ�����ڴ��
		return FetchFromCentralCache(size);
	}
	else {
		return freeList[i].PopFront();
	}
}




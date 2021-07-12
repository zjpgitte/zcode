#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

typedef size_t PageID;


const int MAX_SIZE = 64 * 1024;
const int NFREELISTS = 184; //threadCache��freeList��centralcache��spanList����һ��184
const int NPAGES = 128; //  pageCache�ĳ�����128

class SizeClass{
public:
	// ����size��С���ڴ��ӳ�䵽��λ��
	// ThreadCache�е�freeList����CentralCache�е�spanList����
	// ʹ�õĶ���������ӳ�䷽ʽ��
	static size_t Index(size_t size);

public:
	// ���㲻ͬ��С�ڴ����������ֵ
	static int MaxSize(size_t size){
		int num = MAX_SIZE / size;

		// ����ÿ��ȡ�ĸ���[2, 512]
		if (num < 2) num = 2;   

		if (num > 512) num = 512;   // С��128һ��������512��

		return num;
	}
public:
	// ���ֽ�������
	static size_t RoundUp(size_t size){
		// ������ 8    16   128   1024
		//        16   72   128   184
		if (size <= 128) {
			return (((size >> 3) + 1) << 3);
		}
		else if (size <= 1024) {
			return (((size >> 4) + 1) << 4);
		}
		else if (size <= 8 * 1024) {
			return (((size >> 7) + 1) << 7);
		}
		else if (size <= 64 * 1024) {
			return (((size >> 10) + 1) << 10);
		}
		else {
			assert(false);
			return -1;
		}
	}
};


// FreeList�Ҷ����С��ͬ���ڴ��
class FreeList{
public:
	//��������غ�����

	// ��ȡҪȡ���ڴ����
	int GetNextSize(){
		return _nextSize;
	}

	// ���ô�ȡ���ڴ����
	void UpdateNextSize(size_t size){
		if (_nextSize < SizeClass::MaxSize(size)) _nextSize += 1;
	}


public:
	static void*& NextObj(void* obj);

	bool Empty();

	// ͷ���ڴ��
	void PushFront(void* obj);

	// ͷɾ�ڴ��
	void* PopFront();

	// ����start��ʼ�ĵ�����
	void PushRange(void* start, void* end);

private:
	void* _head = nullptr;
	int _nextSize = 1; // ��¼�´�Ӧ�ô�CentralCacheȡ�ڴ�ĸ�������������ء�
};
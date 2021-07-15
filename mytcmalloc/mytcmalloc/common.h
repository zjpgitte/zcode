#pragma once
#include <iostream>
#include <assert.h>
#include <windows.h>
#include <map>

using std::cout;
using std::endl;

typedef size_t PageID;


const int MAX_SIZE = 64 * 1024;
const int NFREELISTS = 184; //threadCache��freeList��centralcache��spanList����һ��184
const int NPAGES = 128; //  pageCache�ĳ�����128
const int PAGE_SHIFT = 12;

class SizeClass{
public:
	// ����size��С���ڴ��ӳ�䵽��λ��
	// ThreadCache�е�freeList���CentralCache�е�spanList����
	// ʹ�õĶ���������ӳ�䷽ʽ��
	static size_t Index(size_t size);

public:
	// ���㲻ͬ��С�ڴ����������ֵ
	static size_t MaxSize(size_t size){
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
			return ((size + 7) >> 3) << 3;
		}
		else if (size <= 1024) {
			return ((size + 15) >> 4) << 4;
		}
		else if (size <= 8 * 1024) {
			return ((size + 127) >> 7) << 7;
		}
		else if (size <= 64 * 1024) {
			return ((size + 1023) >> 10) << 10;
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
	size_t GetNextSize(){
		return _nextSize;
	}

	// ���ô�ȡ���ڴ����
	void UpdateNextSize(size_t size){
		if (_nextSize < SizeClass::MaxSize(size)) _nextSize += 1;
	}


public:
	size_t Size() {
		return _n;
	}

	static void*& NextObj(void* obj);

	bool Empty();

	// ͷ���ڴ��
	void PushFront(void* obj);

	// ͷɾ�ڴ��
	void* PopFront();

	// ����start��ʼ�ĵ�����
	void PushRange(void* start, void* end, size_t n);

	// ����size�������start
	void PopRange(void*& start, size_t size);

private:
	void* _head = nullptr;
	size_t _nextSize = 1; // ��¼�´�Ӧ�ô�CentralCacheȡ�ڴ�ĸ�������������ء�
	size_t _n = 0; // ��ǰ�������
};


// ϵͳ���ýӿ�
//��ϵͳҪkpageҳ�ڴ�
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap��
#endif

	if (ptr == nullptr)
		throw std::bad_alloc();

	return ptr;
}


inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
	// sbrk unmmap��
#endif
}
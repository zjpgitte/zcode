#pragma once
#include <iostream>
#include <assert.h>
#include <windows.h>
#include <map>

using std::cout;
using std::endl;

typedef size_t PageID;


const int MAX_SIZE = 64 * 1024;
const int NFREELISTS = 184; //threadCache的freeList和centralcache的spanList长度一样184
const int NPAGES = 128; //  pageCache的长度是128
const int PAGE_SHIFT = 12;

class SizeClass{
public:
	// 计算size大小的内存块映射到的位置
	// ThreadCache中的freeList表和CentralCache中的spanList表是
	// 使用的都是这样的映射方式。
	static size_t Index(size_t size);

public:
	// 计算不同大小内存块慢启动阈值
	static size_t MaxSize(size_t size){
		int num = MAX_SIZE / size;

		// 控制每次取的个数[2, 512]
		if (num < 2) num = 2;   

		if (num > 512) num = 512;   // 小于128一次最多分配512个

		return num;
	}
public:
	// 将字节数对齐
	static size_t RoundUp(size_t size){
		// 对齐数 8    16   128   1024
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


// FreeList挂多个大小相同的内存块
class FreeList{
public:
	//慢启动相关函数。
	// 获取要取的内存个数
	size_t GetNextSize(){
		return _nextSize;
	}

	// 设置待取的内存个数
	void UpdateNextSize(size_t size){
		if (_nextSize < SizeClass::MaxSize(size)) _nextSize += 1;
	}


public:
	size_t Size() {
		return _n;
	}

	static void*& NextObj(void* obj);

	bool Empty();

	// 头插内存块
	void PushFront(void* obj);

	// 头删内存块
	void* PopFront();

	// 插入start开始的单链表
	void PushRange(void* start, void* end, size_t n);

	// 弹出size个对象给start
	void PopRange(void*& start, size_t size);

private:
	void* _head = nullptr;
	size_t _nextSize = 1; // 记录下次应该从CentralCache取内存的个数与慢启动相关。
	size_t _n = 0; // 当前对象个数
};


// 系统调用接口
//向系统要kpage页内存
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap等
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
	// sbrk unmmap等
#endif
}
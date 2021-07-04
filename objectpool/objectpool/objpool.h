#pragma once 

#include <iostream>

using std::cout; 
using std::endl;


template <class T> 
class ObjPool {
public:
	void*& NextObj(void* obj) {
		return *((void**)obj);
	}
	T* New() {
		T* obj = nullptr;
		if (_freeList != nullptr) { // freeList挂有对象先从freeList中取
			// 头删
			obj = (T*)_freeList;
			_freeList = NextObj(_freeList);
			return obj;
		}
		else {
			if (_remainSize < sizeof(T)) { // _memery 剩余内存不能存放一个T类型 
				_remainSize = 100 * 1024;
				_memery = (char*)malloc(_remainSize);  // 给_memery重新申请一大块内存
			}
			obj = (T*)_memery;
			(char*)_memery += (sizeof(T));
			_remainSize -= sizeof(T);
			return obj;
		}
	}

	void Delete(T *obj) {
		//向freeList头插
		NextObj(obj) = _freeList;
		_freeList = obj;
	}

private:
	char *_memery = nullptr; //指向从系统申请来的内存
	size_t _remainSize = 0; // _memery的剩余大小
	void *_freeList = nullptr; // 指向由obj大小内存块组成的链表,释放内存时把obj内存块挂到freeList上。
					 // 下次去内存时先到freeList中取。
};
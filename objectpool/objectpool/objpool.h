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
		if (_freeList != nullptr) { // freeList���ж����ȴ�freeList��ȡ
			// ͷɾ
			obj = (T*)_freeList;
			_freeList = NextObj(_freeList);
			return obj;
		}
		else {
			if (_remainSize < sizeof(T)) { // _memery ʣ���ڴ治�ܴ��һ��T���� 
				_remainSize = 100 * 1024;
				_memery = (char*)malloc(_remainSize);  // ��_memery��������һ����ڴ�
			}
			obj = (T*)_memery;
			(char*)_memery += (sizeof(T));
			_remainSize -= sizeof(T);
			return obj;
		}
	}

	void Delete(T *obj) {
		//��freeListͷ��
		NextObj(obj) = _freeList;
		_freeList = obj;
	}

private:
	char *_memery = nullptr; //ָ���ϵͳ���������ڴ�
	size_t _remainSize = 0; // _memery��ʣ���С
	void *_freeList = nullptr; // ָ����obj��С�ڴ����ɵ�����,�ͷ��ڴ�ʱ��obj�ڴ��ҵ�freeList�ϡ�
					 // �´�ȥ�ڴ�ʱ�ȵ�freeList��ȡ��
};

#pragma once
#include "common.h"



// central��Span�������ɸ�ҳ���ڴ�
// ��Щ�ڴ汻�зֳɲ�ͬ��С���ڴ棬�Ե��������ʽ��������
class Span{
public:
	void* _list = nullptr;
	Span* _prev = nullptr;
	Span* _next = nullptr;
};

//spanList��һ����ͷ˫��ѭ������
//
class SpanList{
public:
	SpanList(){
		Span* newSpan = new Span; //new���ɶ���ػ�virtualAllocate
		newSpan->_next = newSpan;
		newSpan->_prev = newSpan;
	}

	// ����ͷ��β
	Span* Begin(){
		return _head->_next;
	}
	Span* End(){
		return _head;
	}

	// ����Ĳ���
	// ͷ��
	void PushFront(Span* s){
		Span* next = _head->_next;
		s->_next = next;
		next->_prev = s;
		s->_prev = _head;
		_head->_next = s;
	}
	// ͷɾ
	Span* PopFront(){
		Span* first = _head->_next;
		Span* second = first->_next;
		_head->_next = second;
		second->_prev = _head;

		first->_next = nullptr;
		first->_prev = nullptr;
		return first;
	}

private:
	Span* _head;
};

// ��Ƴɵ���ģʽ,�����캯���Ϳ����������,�����в������ٳ�����������
class CentralCache{
public:
	static CentralCache* GetInstance(){
		return &_instance;
	}

	// ThreadCache��CentralCache��ȡһ������start��end�ֱ��������ͷ��β
	void FetchObjs(void*& start, void*& end, int num, size_t size);

	// ��list��ȡ�ж����span
	Span* GetOneSpan(SpanList& list, size_t size);

private:
	SpanList _spanList[NFREELISTS];

private:
	static CentralCache _instance;
	CentralCache(){};
	CentralCache(const CentralCache& c) = delete;
};

CentralCache CentralCache::_instance; // ����static���ͱ���
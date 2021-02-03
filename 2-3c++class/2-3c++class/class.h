#pragma once

#include <iostream>

using namespace std;

//class time
//{
//public:
//	time()
//	{
//		_year = 2000;
//		_month = 1;
//		_day = 1;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
class Date
{
	//һ����˵��Ա�����ǹ��е������ⲿ���øú���
public:
	//Date(/*Date *this,*/)
	//{
	//	_year = 2000;
	//	_month = 1;
	//	_day = 1;
	//}
	Date(/*Date *this,*/int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Date d1 = d2; //Date d1(d2);
	Date(/*Date *this,*/const Date& d) //���������Լ��Ŀ������캯���������������������ǳ����
	{								   //����������Ŀ�����Ҫ���ٿռ��ٿ��������ǲ��еģ����ֿ����ǽ������
		this->_year = d._year;          
		this->_month = d._month;
		this->_day = d._day;
	}
	//  d1 == d2
	bool operator == (/*Date *this,*/ const Date& d)
	{
		return this->_year == d._year &&
			this->_month == d._month &&
			this->_day == d._day;
	}

	//d1 = d2
	const Date& operator = (/*Date *this,*/const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;

		return d; 
	}
	void Print(/*Date *this,*/);


	//һ����˵����Ա���������ó���˽�еĲ�����ֱ�ӷ���
private:
	int _year;
	int _month;
	int _day;
	//time a;
};

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		free(_a);
//		_size = 0;
//		_capacity = 0;
//	}
//private:
//	int *_a;
//	int _size;
//	int _capacity;
//};


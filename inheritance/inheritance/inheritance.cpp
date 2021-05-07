#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Person
//{
//public:
//	Person(const char *str )
//		:_name(str)
//	{
//	}
//	void PrintName()
//	{
//		cout << _name << endl;
//	}
//
//protected:
//	string _name;  // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* str = "", int num = 0)
//		:Person(str)
//		,_num(num)
//	{}
//
//	//继承了Person的Print成员函数
//
//private:
//	int _num; // 学号  学生是人可以将人的姓名继承下来
//};
//
//int main()
//{
//	Person p("小明");
//	Student s("小红");
//
//	p = s; // 正确，切片拷贝，只将派生类中属于基类的那一部分拷贝给子类
//	
//	//s = p; // 编译错误, 派生类中属于基类的那部分成员可以被基类拷贝，而自己本身的无法被赋值
//	
//	Person *pp = &p;
//	Student *sp = &s;
//
//	pp = sp;  //正确，对pp解引用可以访问student中属于Person那部分成员
//	//sp = pp;   // 编译错误 , 对sp解引用后student有的成员Person没有
//
//	Person& infp = p;
//	Student& infs = s;
//
//	p = s; //正确
//	//s = p;  //编译错误
//
//	system("pause");
//	return 0;
//}


class A
{
public:
	int _a;
	char _str;
};

class B1 : virtual public A
{
public:
	int _b1;
};

class B2 : virtual public A
{
public:
	int _b2;
};

class C : public B1, public B2
{
public:
	int _c;
};

int main()
{

	C c1;
	c1.B1::_a = 1;
	c1.B1::_str = 'a';
	c1._b1 = 2;
	c1.B2::_a = 1;
	c1.B2::_str = 'c';
	c1._b2 = 3;
	c1._c = 4;


	cout << sizeof(C) << endl;

	return 0;
}
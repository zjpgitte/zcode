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
//	string _name;  // ����
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
//	//�̳���Person��Print��Ա����
//
//private:
//	int _num; // ѧ��  ѧ�����˿��Խ��˵������̳�����
//};
//
//int main()
//{
//	Person p("С��");
//	Student s("С��");
//
//	p = s; // ��ȷ����Ƭ������ֻ�������������ڻ������һ���ֿ���������
//	
//	//s = p; // �������, �����������ڻ�����ǲ��ֳ�Ա���Ա����࿽�������Լ�������޷�����ֵ
//	
//	Person *pp = &p;
//	Student *sp = &s;
//
//	pp = sp;  //��ȷ����pp�����ÿ��Է���student������Person�ǲ��ֳ�Ա
//	//sp = pp;   // ������� , ��sp�����ú�student�еĳ�ԱPersonû��
//
//	Person& infp = p;
//	Student& infs = s;
//
//	p = s; //��ȷ
//	//s = p;  //�������
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
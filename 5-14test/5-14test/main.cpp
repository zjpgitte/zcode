#include <iostream>
#include <string>
#include <vector>
using namespace std;
//
//class A
//{
//private:
//	int _a;
//	
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}
//
//	A(const A& a)
//	{
//		_a = a._a;
//		cout << "A(const A&)" << endl;
//		_count++;
//	}
//
//	int getA()
//	{
//		return _a;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	static int _count;
//};
//int A::_count = 0;
//
//A func(A a)
//{
//	return a;
//}
//
//int main()
//{
//
//	//int a = A(1).getA();  //构造函数形式的匿名对象，直接调用该构造函数初始化
//
//	A a;
//	
//	A b = func(a);
//
//	cout << A::_count << endl;
//		
//	system("pause");
//	return 0;
//}

struct A
{
	double a;
	char c;
};

struct B
{
	A a;
	char c;
};

int main()
{
	cout << sizeof(B) << endl;
	system("pause");
}
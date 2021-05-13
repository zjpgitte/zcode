#include <iostream>
#include <string>
#include <vector>
using namespace std;

//static int a = 1;
//void fun()
//{
//	static int a = 0;
//	static int a = 2;
//	cout << &a << endl;
//}
//
//class A
//{
//public:
//	void func()
//	{
//		delete this;
//	}
//};
//
//void func()
//{
//	A *a = new A;
//	a->func();
//}
//
//int main()
//{
//	/*cout << &a << endl;
//	cout << a << endl;
//
//	fun();
//	
//
//	cout << a << endl;*/
//		
//	func();
//
//
//	system("pause");
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//class C : public A, public B
//{
//public:
//	C()
//	{
//		cout << "C()" << endl;
//	}
//
//	~C()
//	{
//		cout << "~C()" << endl;
//	}
//};
//
//int main()
//{
//	C *c = new C;
//	delete c;
//
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	int *pa = (int*)&a;
//	*pa = 20;
//	cout << a << endl;
//	cout << *pa << endl;
//
//	//int a = 0;
//	//int *p = &a;
//
//	//int b = a;
//
//	//int c = a;
//	//cout << b << " " << a << endl;
//	system("pause");
//}

//struct Test
//{
//	Test(int)
//	{}
//	Test()
//	{
//	}
//	void func()
//	{
//	}
//};
//
//int main()
//{
//	Test a(1);
//	a.func();
//	Test b;
//	b.func();
//
//	return 0;
//}

class A
{
public:
	A()
		:_a(0)
	{}
	A(A& a)
	{
		_a = 10;
		cout << "¿½±´¹¹Ôì" << endl;
		count++;
	}
	static int count;
	int _a;
};

int A::count = 0;

A func(A a)
{
	A b(a);
	A c = a;
	return a;
}

int main()
{
	/*A a;
	A c = func(a);

	A b = func(func(a));

	cout << A::count << endl;*/

	A a = A();
	int b = a._a;

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

//int main()
//{
//	int *pa = new int;
//	int *pb = new int[10];
//	
//
//	system("pause");
//	return 0;
//}
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
//int main()
//{
//	Date *pa = new Date;//这样定义前提是有默认构造函数
//	Date *pb = new Date();//这样前提是有默认构造函数
//	Date *pc = new Date(2020,2,2);//三种定义方式都是可以的
//
//	delete pa;
//	delete pb;
//	delete pc;
//
//	
//	//定义多个对象
//	Date *pd = new Date[10]; //只能有这一种定义方式，
//							//且定义多个对象时，类必须要有默认构造函数（不需要传参数）
//	delete[] pd; //释放多个指向多个对象空间指针时必须加[]。
//
//}

//int main()
//{
//	Date *pd = (Date*)malloc(sizeof(Date));
//	new(pd)Date(2020, 2, 2);
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//
//	}
//	class B
//	{
//	public:
//		B()
//		{
//			A a;
//			cout << a._a << endl;
//		}
//	};
//private:
//	int _a;
//};

//class A
//{
//public:
//
//private:
//	static 
//};

int main()
{
	int y1, m1, d1;
	int y2, m2, d2;
	cin >> y1 >> m1 >> d1;
	cin >> y2 >> m2 >> d2;


	return 0;
}
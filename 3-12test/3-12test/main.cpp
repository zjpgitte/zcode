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
//	Date *pa = new Date;//��������ǰ������Ĭ�Ϲ��캯��
//	Date *pb = new Date();//����ǰ������Ĭ�Ϲ��캯��
//	Date *pc = new Date(2020,2,2);//���ֶ��巽ʽ���ǿ��Ե�
//
//	delete pa;
//	delete pb;
//	delete pc;
//
//	
//	//����������
//	Date *pd = new Date[10]; //ֻ������һ�ֶ��巽ʽ��
//							//�Ҷ���������ʱ�������Ҫ��Ĭ�Ϲ��캯��������Ҫ��������
//	delete[] pd; //�ͷŶ��ָ��������ռ�ָ��ʱ�����[]��
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
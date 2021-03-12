//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//	friend ostream& operator << (ostream& out, Date& d);
//	//ostream& operator << (ostream& out, Date& d);
//public:
//	Date(int year = 2000)
//		: _year(year)
//	{}
//private:
//	int _year;
//};
//
////cout << d << endl;
//ostream& operator << (ostream& out, Date& d)
//{
//	cout << d._year;
//	return out;
//}
//
//int main()
//{
//	
//	//cout << sizeof(nullptr) << endl;
//	////cout << sizeof((void*)0) << end;
//	//printf("%d\n", sizeof((void*)0));
//
//	Date d1;
//	Date d2(2);
//	cout << d1 << d2 << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>

using namespace std;

int main()
{
	int a[] = { 1, 2, 8, 3, 8, 2, 2, 6, 8, 1, 2, 9, 3, 4, 3, 6, 7, 6, 7};
	int n = sizeof(a) / sizeof(a[0]);

	int pairsNum[10][10] = { 0 };
	for (int i = 0; i < n - 1; i++)
	{
		int pI = a[i], pJ = a[i + 1];
		pairsNum[pI][pJ]++;
	}

	for (int i = 0; i < 10;i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (i != j && pairsNum[i][j] > 0 && pairsNum[j][i] > 0)
			{
				printf("(%d,%d)=%d, (%d,%d)=%d\n", i, j, pairsNum[i][j], j, i, pairsNum[j][i]);
			}
		}
	}

	system("pause");
	return 0;

}
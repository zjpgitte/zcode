#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	//��¼ĳ��ĩ����һ������
	int monthDay[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	while (cin >> year >> month >> day)
	{
		int outDay = monthDay[month - 1] + day;
		if (year % 4 == 0 && year % 100 != 100 || year % 400 == 0)
		{
			outDay += 1;
		}
		cout << outDay << endl;
		//Date d1(year, month, day);
		//Date d2(year, 1, 1);
		//int countDay = d1 - d2 + 1; 
	}

	return 0;
}
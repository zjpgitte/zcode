#include <iostream>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//输入两个整数
	int maxD, minD;
	cin >> maxD;
	cin >> minD;
	if (minD > maxD)
	{
		Swap(minD, maxD);
	}

	//将输入的整数日期转化
	int maxYear, maxMonth, maxDay;
	int minYear, minMonth, minDay;
	maxDay = maxD % 100;
	minDay = minD % 100;
	maxD /= 100;
	minD /= 100;
	maxMonth = maxD % 100;
	minMonth = minD % 100;
	maxD /= 100;
	minD /= 100;
	maxYear = maxD;
	minYear = minD;

	//把年和月的天数全部累加到天上
	while (maxYear != minYear || maxMonth != minMonth)
	{
		//先把前一个月累加到天数上
		if (maxMonth == 1)
		{
			//修正月
			maxYear -= 1;
			maxMonth = 13;
		}
		//判断是否是闰年，修正monthDay
		if ((maxYear % 4 == 0 && maxYear % 100 != 0 || maxYear % 400 == 0))
		{
			monthDay[2] = 29;
		}
		else
		{
			monthDay[2] = 28;
		}

		//将前一个月的天数累加到天上
		maxDay += monthDay[--maxMonth];
	}

	//求天数差
	int gap = maxDay - minDay + 1;
	cout << gap << endl;

	return 0;
}
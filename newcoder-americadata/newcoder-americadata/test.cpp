// write your code here cpp
#include <iostream>

using namespace std;

int main()
{

	int year;
	while (cin >> year){
		// 求这一年的第一天是周几
		int firstDay = 3;

		int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			dayOfMonth[2] += 1;
		}
		int firstMondayOfMonth[13]; // 记录每个月的第一个周一在几号

		printf("%d-%02d-%02d\n", year, 1, 1);

		for (int i = 1; i < 13; i++){
			// 求1月的第一个星期一是几号
			if (firstDay == 1){
				firstMondayOfMonth[1] = 1;
			}
			else{
				firstMondayOfMonth[1] = 1 + 7 - firstDay + 1;
			}

			// 求i月第一个星期一是几号
			if (firstMondayOfMonth[i - 1] == 1){
				firstMondayOfMonth[i] = firstMondayOfMonth[i - 1] + 35 - dayOfMonth[i - 1];
			}
			else{
				firstMondayOfMonth[i] = firstMondayOfMonth[i - 1] + 28 - dayOfMonth[i - 1];
			}
		}

		// 1月第三个星期一 = 第一个星期一 + 2 * 7
		printf("%d-%02d-%02d\n", year, 1, firstMondayOfMonth[1] + 2 * 7);

		// 2月的第三个星期一 = 第一个星期一 + 2 * 7 
		printf("%d-%02d-%02d\n", year, 2, firstMondayOfMonth[2] + 2 * 7);

		//5月的最后一个星期一：阵亡将士纪念日
		int day;
		if (firstMondayOfMonth[5] == 1)
		{
			day = firstMondayOfMonth[5] + 28;
		}
		else
		{
			day = firstMondayOfMonth[5] + 21;
		}
		printf("%d-%02d-%02d\n", year, 5, day);

		//* 7月4日：美国国庆
		printf("%d-%02d-%02d\n", year, 7, 4);

		//* 9月的第一个星期一：劳动节
		day = firstMondayOfMonth[9];
		printf("%d-%02d-%02d\n", year, 9, day);

		//* 11月的第四个星期四：感恩节
		day = firstMondayOfMonth[11] + 3 * 7 + 3;
		if (day > dayOfMonth[11])
		{
			day -= dayOfMonth[11];
		}
		printf("%d-%02d-%02d\n", year, 11, day);

		//* 12月25日：圣诞节
		printf("%d-%02d-%02d\n", year, 12, 25);

	}

	return 0;
}
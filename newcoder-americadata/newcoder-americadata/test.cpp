// write your code here cpp
#include <iostream>

using namespace std;

int main()
{

	int year;
	while (cin >> year){
		// ����һ��ĵ�һ�����ܼ�
		int firstDay = 3;

		int dayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			dayOfMonth[2] += 1;
		}
		int firstMondayOfMonth[13]; // ��¼ÿ���µĵ�һ����һ�ڼ���

		printf("%d-%02d-%02d\n", year, 1, 1);

		for (int i = 1; i < 13; i++){
			// ��1�µĵ�һ������һ�Ǽ���
			if (firstDay == 1){
				firstMondayOfMonth[1] = 1;
			}
			else{
				firstMondayOfMonth[1] = 1 + 7 - firstDay + 1;
			}

			// ��i�µ�һ������һ�Ǽ���
			if (firstMondayOfMonth[i - 1] == 1){
				firstMondayOfMonth[i] = firstMondayOfMonth[i - 1] + 35 - dayOfMonth[i - 1];
			}
			else{
				firstMondayOfMonth[i] = firstMondayOfMonth[i - 1] + 28 - dayOfMonth[i - 1];
			}
		}

		// 1�µ���������һ = ��һ������һ + 2 * 7
		printf("%d-%02d-%02d\n", year, 1, firstMondayOfMonth[1] + 2 * 7);

		// 2�µĵ���������һ = ��һ������һ + 2 * 7 
		printf("%d-%02d-%02d\n", year, 2, firstMondayOfMonth[2] + 2 * 7);

		//5�µ����һ������һ��������ʿ������
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

		//* 7��4�գ���������
		printf("%d-%02d-%02d\n", year, 7, 4);

		//* 9�µĵ�һ������һ���Ͷ���
		day = firstMondayOfMonth[9];
		printf("%d-%02d-%02d\n", year, 9, day);

		//* 11�µĵ��ĸ������ģ��ж���
		day = firstMondayOfMonth[11] + 3 * 7 + 3;
		if (day > dayOfMonth[11])
		{
			day -= dayOfMonth[11];
		}
		printf("%d-%02d-%02d\n", year, 11, day);

		//* 12��25�գ�ʥ����
		printf("%d-%02d-%02d\n", year, 12, 25);

	}

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int y, n;
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int monthDayToBegin[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	while (cin >> y >> n)
	{
		int year = y, month, day;
		//еп╤отб
		for (int i = 1; i <= 12; i++)
		{
			if (n <= monthDayToBegin[i])
			{
				month = i;
				break;
			}
		}

		day = n - monthDayToBegin[month - 1];
		if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month > 2)
		{
			monthDay[2] = 29;
			if (day == 1)
			{
				month -= 1;
				day = monthDay[month - 1] + 1;
			}

			day -= 1;
		}
		else
		{
			monthDay[2] = 28;
		}

		printf("%4d-%02d-%02d\n", year, month, day);
	}

	return 0;
}
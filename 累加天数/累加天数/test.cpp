#include <iostream>
using namespace std;

int main()
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int m;
	//输入样例个数
	cin >> m;
	int year[m], month[m], day[m], n[m];

	//输入m组样例
	for (int i = 0; i < m; i++)
	{
		cin >> year[i] >> month[i] >> day[i] >> n[i];
	}

	//输出m行结果
	for (int i = 0; i < m; i++)
	{

		//将天数累加
		day[i] += n[i];

		//判断日期是否合法
		while (day[i] > monthDay[month[i]])
		{
			//修正monthDay
			if (year[i] % 4 == 0 && year[i] % 100 != 0 || year[i] % 400 == 0)
			{
				monthDay[2] = 29;
			}
			else
			{
				monthDay[2] = 28;
			}
			//修正天数
			day[i] -= monthDay[month[i]];
			month[i] += 1;
			//判断月是否合法
			if (month[i] > 12)
			{
				//修正month
				month[i] = 1;
				year[i] += 1;
			}
		}

		//日期合法
		printf("%04d-%02d-%02d\n", year[i], month[i], day[i]);
		//         cout << year[i] << "-" ;
		//         if(month[i] < 10)
		//         {
		//             cout << 0 << month[i] << "-";
		//         }
		//         else
		//         {
		//             cout << month[i] << "-";
		//         }
		//         if(day[i] < 10)
		//         {
		//             cout << 0 << day[i] << endl;
		//         }
		//         else
		//         {
		//             cout << day[i] << endl;
		//         }

	}



	return 0;
}
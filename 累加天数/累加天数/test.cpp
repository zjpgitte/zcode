#include <iostream>
using namespace std;

int main()
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int m;
	//������������
	cin >> m;
	int year[m], month[m], day[m], n[m];

	//����m������
	for (int i = 0; i < m; i++)
	{
		cin >> year[i] >> month[i] >> day[i] >> n[i];
	}

	//���m�н��
	for (int i = 0; i < m; i++)
	{

		//�������ۼ�
		day[i] += n[i];

		//�ж������Ƿ�Ϸ�
		while (day[i] > monthDay[month[i]])
		{
			//����monthDay
			if (year[i] % 4 == 0 && year[i] % 100 != 0 || year[i] % 400 == 0)
			{
				monthDay[2] = 29;
			}
			else
			{
				monthDay[2] = 28;
			}
			//��������
			day[i] -= monthDay[month[i]];
			month[i] += 1;
			//�ж����Ƿ�Ϸ�
			if (month[i] > 12)
			{
				//����month
				month[i] = 1;
				year[i] += 1;
			}
		}

		//���ںϷ�
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
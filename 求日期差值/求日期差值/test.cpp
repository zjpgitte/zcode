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

	//������������
	int maxD, minD;
	cin >> maxD;
	cin >> minD;
	if (minD > maxD)
	{
		Swap(minD, maxD);
	}

	//���������������ת��
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

	//������µ�����ȫ���ۼӵ�����
	while (maxYear != minYear || maxMonth != minMonth)
	{
		//�Ȱ�ǰһ�����ۼӵ�������
		if (maxMonth == 1)
		{
			//������
			maxYear -= 1;
			maxMonth = 13;
		}
		//�ж��Ƿ������꣬����monthDay
		if ((maxYear % 4 == 0 && maxYear % 100 != 0 || maxYear % 400 == 0))
		{
			monthDay[2] = 29;
		}
		else
		{
			monthDay[2] = 28;
		}

		//��ǰһ���µ������ۼӵ�����
		maxDay += monthDay[--maxMonth];
	}

	//��������
	int gap = maxDay - minDay + 1;
	cout << gap << endl;

	return 0;
}
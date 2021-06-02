// write your code here cpp
#include <iostream>

using namespace std;

bool isSuShu(int num)
{
	if (num == 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int fromYear, fromMonth, fromDay, toYear, toMonth, toDay;
	int wOfMonth[13] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 }; // ������
	int _wYear = 0;
	int wYear = 0; // ������
	for (int i = 0; i < 13; i++)
	{
		_wYear += wOfMonth[i];
	}
	while (cin >> fromYear >> fromMonth >> fromDay >> toYear >> toMonth >> toDay)
	{
		int w = 0;

		if (fromYear == toYear)
		{
			if (fromYear % 4 == 0 && fromYear % 100 != 0 || fromYear % 400 == 0)
			{
				wOfMonth[2] = 29;
				wYear = _wYear + 1;
			}
			else
			{
				wOfMonth[2] = 28;
				wYear = _wYear;
			}
			if (fromMonth == toMonth)
			{
				if (isSuShu(toMonth))
					w += toDay - fromDay + 1;
				else
					w += (toDay - fromDay + 1) * 2;
				cout << w << endl;
				continue;
			}
			for (int i = fromMonth + 1; i < toMonth; i++)
			{
				w += wOfMonth[i];
			}
			if (isSuShu(fromMonth))
			{
				w += wOfMonth[fromMonth] - (fromDay - 1);
			}
			else
			{
				w += wOfMonth[fromMonth] - (fromDay - 1) * 2;
			}
			if (isSuShu(toMonth))
			{
				w += toDay;
			}
			else
			{
				w += toDay * 2;
			}

			cout << w << endl;
			continue;
		}
		// ��fromyear������
		// �����������������
		if (fromYear % 4 == 0 && fromYear % 100 != 0 || fromYear % 400 == 0)
		{
			wOfMonth[2] = 29;
			wYear = _wYear + 1;
		}
		else
		{
			wOfMonth[2] = 28;
			wYear = _wYear;
		}
		// ��fromyearһ�������
		for (int i = fromMonth + 1; i < 13; i++)
		{
			w += wOfMonth[i];
		}
		int wMonth; // fromMonth��һ���µ�����
		if (isSuShu(fromMonth))
		{
			wMonth = wOfMonth[fromMonth] - fromDay + 1;
		}
		else
		{
			wMonth = wOfMonth[fromMonth] - (fromDay - 1) * 2;
		}
		w += wMonth;

		// ����(fromYear, toYear) ֮�������
		for (int i = fromYear + 1; i < toYear; i++)
		{
			// ����������
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			{
				wYear = _wYear + 1;
			}
			w += wYear;
		}

		// ��toYear��������
		if (toYear % 4 == 0 && toYear % 100 != 0 || toYear % 400 == 0)
		{
			wOfMonth[2] = 29;
		}
		else
		{
			wOfMonth[2] = 28;
		}
		for (int i = 1; i < toMonth; i++)
		{
			w += wOfMonth[i];
		}
		if (isSuShu(toMonth))
		{
			wMonth = toDay;
			w += wMonth;
		}
		else
		{
			wMonth = toDay * 2;
			w += wMonth;
		}

		cout << w << endl;
	}

	return 0;
}
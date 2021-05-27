#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string add(const string& a, const string& b)
{
	//a、b从后往前每一位相加再加上进位
	//记录相加结果，再判断是否进位，记录进位结果
	string sret;
	int nextNum = 0;
	int aI = a.size() - 1, bI = b.size() - 1;

	while (aI >= 0 || bI >= 0)
	{
		int numA = 0, numB = 0;
		if (aI >= 0)
		{
			numA = a[aI] - '0';
		}
		if (bI >= 0)
		{
			numB = b[bI] - '0';
		}

		int ret = numA + numB + nextNum;

		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}

		sret += (ret + '0');
		aI--;
		bI--;
	}
	if (nextNum == 1)
	{
		sret += '1';
	}

	reverse(sret.begin(), sret.end());

	return sret;
}

bool greate(const string& a, const string& b)
{
	if (a.size() > b.size())
	{
		return true;
	}
	else if (a.size() < b.size())
	{
		return false;
	}
	else
	{
		return a > b;
	}
}

bool canForm(string a, string b, string c)
{

	if (greate(add(a, b), c) && greate(add(a, c), b) && greate(add(b, c), a))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string a;
	string b;
	string c;
	
	while (cin >> a >> b >> c)
	{
		string ret = add(a, b);
		/*if (canForm(a, b, c))
		{
		cout << "Yes" << endl;
		}
		else
		{
		cout << "No" << endl;
		}*/
	}

	system("pause");
	return 0;
}
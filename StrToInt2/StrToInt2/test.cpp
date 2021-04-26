#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool IsNum(char ch)
	{
		if (ch >= '0' && ch <= '9')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int StrToInt(string str) {
		int sign = 1;
		int i = 0;
		if (str[0] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[0] == '+')
		{
			i++;
		}

		int ret = 0;
		for (; i < str.size(); i++)
		{
			if (IsNum(str[i]))
			{
				ret = ret * 10 + str[i] - '0';
			}
			else
			{
				return 0;
			}
		}

		return sign * ret;
	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
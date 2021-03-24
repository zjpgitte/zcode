#include <iosgream>
#include <string>
using namespace std;


class Solution {
public:
	bool IsNumber(char ch)
	{
		if (ch >= '1' && ch <= '9')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int StrToInt(string str) {

		//输入字符串
		//cin >> str;

		//空串直接返回
		if (str.size() == 0)
		{
			return 0;
		}

		int ret = 0;//记录结果

		int i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			i++;
		}
		//遍历str 
		for (; i < str.size(); i++)
		{
			//判断是否是数字
			if (IsNumber(str[i]))
			{
				//是数字将其加到ret中
				ret = ret * 10 + str[i] - '0';
			}
			else//不是数字
			{
				return 0;
			}
		}

		//判断结果正负
		if (str[0] == '-')
		{
			return -ret;
		}
		else
		{
			return ret;
		}



	}
};
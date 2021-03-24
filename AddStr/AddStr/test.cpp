#include <iostream>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string addS; //记录结果

		//cur1, cur2记录当前要相加的两个字符的下标
		int cur1 = num1.size() - 1;
		int cur2 = num2.size() - 1;

		int nextNum = 0; //记录进位
		while (cur1 >= 0 || cur2 >= 0)
		{
			int number1 = 0, number2 = 0;
			if (cur1 >= 0)
			{
				number1 = num1[cur1] - '0';
			}
			if (cur2 >= 0)
			{
				number2 = num2[cur2] - '0';
			}

			//求得当前两个字符相加的结果
			int ret = number1 + number2 + nextNum;
			//判断结果是否进位
			if (ret > 9)
			{
				ret -= 10;
				nextNum = 1;
			}
			else
			{
				nextNum = 0;
			}
			addS += ret + '0';
			cur1--;
			cur2--;
		}

		//判断最终结果是否进位
		if (nextNum == 1)
		{
			addS += '1';
		}

		reverse(addS.begin(), addS.end());

		return addS;

	}
};
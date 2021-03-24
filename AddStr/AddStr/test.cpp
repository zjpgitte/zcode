#include <iostream>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string addS; //��¼���

		//cur1, cur2��¼��ǰҪ��ӵ������ַ����±�
		int cur1 = num1.size() - 1;
		int cur2 = num2.size() - 1;

		int nextNum = 0; //��¼��λ
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

			//��õ�ǰ�����ַ���ӵĽ��
			int ret = number1 + number2 + nextNum;
			//�жϽ���Ƿ��λ
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

		//�ж����ս���Ƿ��λ
		if (nextNum == 1)
		{
			addS += '1';
		}

		reverse(addS.begin(), addS.end());

		return addS;

	}
};
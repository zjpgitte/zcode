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

		//�����ַ���
		//cin >> str;

		//�մ�ֱ�ӷ���
		if (str.size() == 0)
		{
			return 0;
		}

		int ret = 0;//��¼���

		int i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			i++;
		}
		//����str 
		for (; i < str.size(); i++)
		{
			//�ж��Ƿ�������
			if (IsNumber(str[i]))
			{
				//�����ֽ���ӵ�ret��
				ret = ret * 10 + str[i] - '0';
			}
			else//��������
			{
				return 0;
			}
		}

		//�жϽ������
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
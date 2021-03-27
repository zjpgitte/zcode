#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void TransformToLittle(string& s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 'a' - 'A';
			}
		}
	}

	bool IsLetter(char ch)
	{
		if (ch >= '0' && ch <= '9' ||
			ch >= 'a' && ch <= 'z' ||
			ch >= 'A' && ch <= 'Z')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isPalindrome(string s) {
		//����д��ĸתСд
		TransformToLittle(s);
		int left = 0, right = s.size() - 1;

		while (left < right)
		{
			//���������ĸ�������ַ�
			while (left < right && !IsLetter(s[left]))
			{
				left++;
			}
			//���ұ���������ĸ���ַ�
			while (left < right && !IsLetter(s[right]))
			{
				right--;
			}

			//�ж������ַ��Ƿ����
			if (s[left] != s[right])
			{
				return false;
			}
			left++;
			right--;
		}

		return true;
	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
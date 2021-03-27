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
		//½«´óÐ´×ÖÄ¸×ªÐ¡Ð´
		TransformToLittle(s);
		int left = 0, right = s.size() - 1;

		while (left < right)
		{
			//´Ó×ó±ßÕÒ×ÖÄ¸ºÍÊý×Ö×Ö·û
			while (left < right && !IsLetter(s[left]))
			{
				left++;
			}
			//´ÓÓÒ±ßÍù×óÕÒ×ÖÄ¸ºÍ×Ö·û
			while (left < right && !IsLetter(s[right]))
			{
				right--;
			}

			//ÅÐ¶ÏÁ½¸ö×Ö·ûÊÇ·ñÏàµÈ
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
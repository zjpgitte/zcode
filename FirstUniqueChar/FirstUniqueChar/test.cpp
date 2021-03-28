#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		//计数每个字符
		int count[26] = { 0 };

		for (int i = 0; i < s.size(); i++)
		{
			count[s[i] - 'a']++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (count[s[i] - 'a'] == 1)
			{
				return i;
			}
		}

		return -1;

	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
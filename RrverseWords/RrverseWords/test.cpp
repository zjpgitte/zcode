#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		//遍历字符串
		int cur = 0;//记录当前单词的下标
		while (cur < s.size())
		{
			//确定单词区间
			int left = cur; //单词的左区间
			int pos = s.find_first_of(' ', left); //记录空格的位置
			//是否找到空格        
			if (pos == string::npos)
			{
				pos = s.size();
			}

			int right = pos - 1; //单词的右区间
			//翻转单词
			while (left < right)
			{
				swap(s[left], s[right]);
				left++;
				right--;
			}

			cur = pos + 1;

		}

		return s;
	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k)
		{
			//记录2k个元素的前k个区间
			int left = i, right = i + k - 1; //前k个

			//若元素数量小于k,修正right
			if (s.size() - i < k)
			{
				right = s.size() - 1;
			}

			//发展 [left, right]
			while (left < right)
			{
				swap(s[left], s[right]);
				left++;
				right--;
			}

		}

		return s;
	}
};
int main()
{
	
	
	
	system("pause");
	return 0;
}
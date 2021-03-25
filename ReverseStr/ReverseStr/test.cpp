#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k)
		{
			//��¼2k��Ԫ�ص�ǰk������
			int left = i, right = i + k - 1; //ǰk��

			//��Ԫ������С��k,����right
			if (s.size() - i < k)
			{
				right = s.size() - 1;
			}

			//��չ [left, right]
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
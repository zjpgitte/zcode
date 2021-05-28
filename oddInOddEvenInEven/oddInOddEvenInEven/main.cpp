#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int oddI = 0; // 记录偶数位
		int evenI = 1; // 记录奇数位

		while (oddI < arr.size() && evenI < arr.size())
		{
			// 偶数位上找奇数
			while (oddI < arr.size() && arr[oddI] % 2 == 0)
			{
				oddI += 2;
			}

			//奇数为上找偶数
			while (evenI < arr.size() && arr[evenI] % 2 != 0)
			{
				evenI += 2;
			}

			// 有一个走到头了，说明要么奇数为全是奇数，要么偶数位全是偶数
			if (oddI >= arr.size() || evenI >= arr.size())
			{
				break;
			}

			swap(arr[oddI], arr[evenI]);
		}
	}
};


int main()
{
	
	
	
	system("pause");
	return 0;
}
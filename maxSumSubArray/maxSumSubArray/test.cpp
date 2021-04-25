#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = 0; // 记录当前的子数组和(不是最大的)
		int maxSum = array[0]; // 记录最大的和

		for (int i = 0; i < array.size(); i++)
		{
			sum += array[i];

			//如果当前的子数组和比最大的子数组和还大，更新maxSum
			if (sum > maxSum)
			{
				maxSum = sum;
			}

			if (sum < 0)
			{
				sum = 0;
			}

		}

		return maxSum;

	}
};

int main()
{
	
	
	
	system("pause");
	return 0;
}
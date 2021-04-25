#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = 0; // ��¼��ǰ���������(��������)
		int maxSum = array[0]; // ��¼���ĺ�

		for (int i = 0; i < array.size(); i++)
		{
			sum += array[i];

			//�����ǰ��������ͱ�����������ͻ��󣬸���maxSum
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
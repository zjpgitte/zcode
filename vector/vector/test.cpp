#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> nums(numRows);

		for (int i = 0; i < numRows; i++)
		{
			nums[i].resize(i + 1, 1);
		}

		for (int i = 2; i < nums.size() ; i++) 
		{
			for (int j = 1; j < nums[i].size()- 1; j++)
			{
				nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
			}
		}

		return nums;
	}
};


int main()
{
	Solution s;
	s.generate(5);
	
	
	system("pause");
	return 0;
}
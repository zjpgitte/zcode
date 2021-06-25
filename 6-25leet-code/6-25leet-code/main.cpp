#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int _sum(vector<int>& nums, int left, int right){
		if (left > right) {
			return 0;
		}
		else if (left == right) {
			return nums[left];
		}
		else {
			int mid = (left + right) / 2;
			return _sum(nums, left, mid) + _sum(nums, mid + 1, right);
		}
	}
	int sum(vector<int>& nums){
		return _sum(nums, 0, nums.size() - 1);
	}

	int _maxNum(vector<int>& nums, int left, int right){
		if (left > right) {
			return INT_MIN;
		}
		else if (left == right) {
			return nums[left];
		}
		else if (right - left == 1) {
			return nums[right] > nums[left] ? nums[right] : nums[left];
		}
		else {
			int leftMax = _maxNum(nums, left, (left + right) / 2);
			int rightMax = _maxNum(nums, (left + right) / 2, right);
			return leftMax > rightMax ? leftMax : rightMax;
		}
	}
	int maxNum(vector<int>& nums){
		return _maxNum(nums, 0, nums.size() - 1);
	}
};

int main()
{

	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(10);
	nums.push_back(50);
	nums.push_back(1000);
	nums.push_back(10);
	nums.push_back(1089);
	nums.push_back(10123);
	nums.push_back(120);
	int ret = s.sum(nums);

	int maxRet = s.maxNum(nums);

	system("pause");
	return 0;
}
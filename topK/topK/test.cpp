#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//建一个k个数的小堆
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < k; i++)
		{
			q.push(nums[i]);
		}

		//遍历数组找出比堆顶大的元素,删除堆顶元素入堆
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] > q.top())
			{
				q.pop();
				q.push(nums[i]);
			}
		}

		//返回堆顶
		return q.top();
	}
};
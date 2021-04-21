#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//��һ��k������С��
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < k; i++)
		{
			q.push(nums[i]);
		}

		//���������ҳ��ȶѶ����Ԫ��,ɾ���Ѷ�Ԫ�����
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] > q.top())
			{
				q.pop();
				q.push(nums[i]);
			}
		}

		//���ضѶ�
		return q.top();
	}
};
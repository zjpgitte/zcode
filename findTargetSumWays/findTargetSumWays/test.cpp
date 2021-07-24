class Solution {
public:
	// left + right = sum;   sum > target, ��sum < target ������
	// left - right = target;
	// left - (sum - left) = target;
	// left = (sum + target) / 2; 
	// �ҳ���Ϊ left ����������ϵĸ���
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto& e : nums) {
			sum += e;
		}

		if (sum < target) return 0;
		if ((sum + target) % 2 != 0) {
			// ��ʱleft������������Ȼ�Ҳ�����Ϊleft���������
			return 0;
		}

		int bagSize = (sum + target) / 2;

		//��������ѡ����ΪbagSize�����м��ַ���
		// dp[j] ��ʾѡ���������͵���j�ķ�����dp[j]��
		vector<int> dp(bagSize + 1, 0);
		dp[0] = 1;

		// dp[j] += dp[j - nums[i]]
		for (int i = 0; i < nums.size(); i++) {
			for (int j = bagSize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];
			}
		}

		return dp[bagSize];
	}
};

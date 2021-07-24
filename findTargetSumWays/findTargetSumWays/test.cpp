class Solution {
public:
	// left + right = sum;   sum > target, 若sum < target 不存在
	// left - right = target;
	// left - (sum - left) = target;
	// left = (sum + target) / 2; 
	// 找出和为 left 所有数的组合的个数
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto& e : nums) {
			sum += e;
		}

		if (sum < target) return 0;
		if ((sum + target) % 2 != 0) {
			// 此时left不是整数，自然找不到和为left的数的组合
			return 0;
		}

		int bagSize = (sum + target) / 2;

		//从数组中选出和为bagSize的数有几种方案
		// dp[j] 表示选择若干数和等于j的方法有dp[j]种
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

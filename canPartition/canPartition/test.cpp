class Solution {
public:
	bool canPartition(vector<int>& nums) {
		// dp[i] 表示选取任意元素，和值不超过i的前提下
		// 和的最大值
		int target = 0;
		for (auto& e : nums) target += e;
		if (target % 2 != 0) return false;
		target /= 2;
		vector<int> dp(target + 1, 0);

		// dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
		for (int i = 0; i < nums.size(); i++) {
			for (int j = target; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}


		return dp[target] == target;

	}
};
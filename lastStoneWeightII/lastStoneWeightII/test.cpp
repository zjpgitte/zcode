class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		// 只需将石头分成两堆，使得这两堆石头的中量差值最小
		// 选出若干个石头，使得这些石头重量最接近总重量的一般即可。

		// dp[j] 表示 j 重量的背包中，能装的石头中量的最大值。
		// dp[j] = max(dp[j], dp[j - stones[i]] + stones)
		int target = 0;
		int sum = 0;
		for (auto& e : stones) sum += e;
		target = sum / 2;

		vector<int> dp(target + 1, 0);

		for (int i = 0; i < stones.size(); i++) {
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		// dp[target]表示不超过总重量一半的前提下，选择的石头的最大重量

		return sum - dp[target] - dp[target];
	}
};
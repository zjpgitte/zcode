class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		// ֻ�轫ʯͷ�ֳ����ѣ�ʹ��������ʯͷ��������ֵ��С
		// ѡ�����ɸ�ʯͷ��ʹ����Щʯͷ������ӽ���������һ�㼴�ɡ�

		// dp[j] ��ʾ j �����ı����У���װ��ʯͷ���������ֵ��
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
		// dp[target]��ʾ������������һ���ǰ���£�ѡ���ʯͷ���������

		return sum - dp[target] - dp[target];
	}
};
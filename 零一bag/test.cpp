#include "bag.h"

using namespace std;

int MaxValue(int bagWeight, vector<int>& weight, vector<int>& value) {
	int m = value.size(), n = bagWeight;
	vector<vector<int>> dp(m, vector<int>(n + 1, 0));

	// dp[i][j] = max<int>(dp[i - 1][j], dp[i - 1][j - V[i]] + value[i]) 

	for (int j = 0; j <= n; j++) {
		if (j >= weight[0]) {
			dp[0][j] = value[0];
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = weight[i]; j <= bagWeight; j++) {
			dp[i][j] = max<int>(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[m - 1][n];
}

int maxValue(int bagWeight, vector<int>& weight, vector<int>& value) {
	vector<int> dp(bagWeight + 1, 0);// dp[j]表示容量j的背包的最大价值

	for (int j = 0; j <= bagWeight; j++) {
		if (j >= weight[0]) dp[j] = value[0];
	}

	for (int i = 1; i < weight.size(); i++) {
		for (int j = bagWeight; j >= weight[i]; j--) {
			dp[j] = max<int>(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	return dp[bagWeight];
}

int main() {
	
	vector<int> weight = { 1, 3, 5 };
	vector<int> value = { 10, 20, 35 };

	cout << maxValue(5, weight, value) << endl;

	return 0;
}
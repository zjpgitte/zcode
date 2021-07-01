#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 01背包问题
int bagpage(vector<int>& w, vector<int>& v, int bagWeight) {
	int m = w.size();
	int n = bagWeight;
	// 创建一个dp二维数组，dp[i][j]的含义是把 i 之前的任意物品放到重量为
	// j 的背包中，此时背包的价值的最大值是dp[i][j]
	// 注意：i 之前的任意物品不是指所有物品仅仅只是指使背包价值最大的那几个物品
	vector<vector<int>> dp(m);
	for (auto& e : dp) {
		e.resize(n + 1);
	}

	// 状态转移方程 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])  
	// dp[i - 1][j] 可以理解为第i个物品不放到背包里，背包里的物品还是之前的 i-1 个物品里面的任意物品的价值.
	// dp[i - 1][j - weight[i]] + v[i] 可以理解从j重量的背包中取出weight[i]重量的物品(可能是[0, i]个)，
	// 然后再把第 i 个物品放进去的价值。
	// dp[i][j]记录的就是最大价值，自然取上述两个中最大的即可。

	
	// 初始化二维数组  dp[i][j] 要依赖i - 1和j - w[i]，因此对第一行和第一列要进行初始化
	
	// 初始化 dp[0][j] 将第0个物品放到j重量的背包中，背包的价值
	for (int j = 0; j <= bagWeight; j++) {
		if (j < w[0]) { // 此时的背包重量无法容纳第0个物品
			dp[0][j] = 0;
		}
		else {
			dp[0][j] = v[0]; // 背包中只放0物品因此背包重量就是该物品重量
		}
	}

	// 初始化dp[i][0] 将 i 之前人以物品放到0重量的背包中，背包的价值还是0
	for (int i = 0; i < w.size(); i++) {
		dp[i][0] = 0;
	}

	// 将 i之前的物品放到j重量的背包中的价值
	for (int i = 1; i < w.size(); i++) {
		for (int j = 1; j <= bagWeight; j++) {
			if (j < w[i]) { // 背包根本容纳不下i物品
				dp[i][j] = dp[i - 1][j]; // i 之前任意物品放到背包里和 i - 1之前的物品放入背包价值是一样的。
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				//要么将i物品放进去替换掉原来背包中同等重量的物品，要么背包里放前i - 1个任意物品
				// 取价值大的即可。
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	return dp[m - 1][n];
}

int main()
{
	
	vector<int> weight = {1, 3, 4};
	vector<int> values = {15, 20, 30};
	int bagWeight = 4;

	int ret = bagpage(weight, values, bagWeight);
	
	system("pause");
	return 0;
}
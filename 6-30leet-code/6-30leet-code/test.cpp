class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp;
		dp.resize(m);
		for (auto& e : dp) {
			e.resize(n);
		}

		// dp[i][j] 表示从start到[i,j]的路径个数
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				while (j < n) {
					dp[0][j] = 0;
					j++;
				}
			}
			else {
				dp[0][j] = 1;
			}
		}

		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] == 1) {
				while (i < m) {
					dp[i][0] = 0;
					i++;
				}
			}
			else {
				dp[i][0] = 1;
			}
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}

		return dp[m - 1][n - 1];
	}
};


class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1); // dp[i] 表示i拆分成的整数的乘积最大值
		dp[2] = 1; dp[1] = 0;

		for (int i = 3; i <= n; i++) {

			//求出dp[i]
			int max = 0;
			for (int j = 1; j <= i / 2; j++) {
				int num1 = j * (i - j);
				int num2 = dp[j] * dp[i - j];
				int temp1 = num1 > num2 ? num1 : num2;
				int num3 = j * dp[i - j];
				int num4 = dp[j] * (i - j);
				int temp2 = num3 > num4 ? num3 : num4;
				int temp = temp1 > temp2 ? temp1 : temp2;
				if (temp > max) max = temp;
			}
			dp[i] = max;
		}

		for (auto& e : dp) cout << e << " "; cout << endl;
		return dp[n];
	}
};
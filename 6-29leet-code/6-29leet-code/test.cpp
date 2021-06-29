#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> ret;
	vector<string> path;
	vector<bool> col;
	vector<bool> mainDia;
	vector<bool> subDia;
	inline int hashMain(int row, int col, int n) {
		return row - col + n - 1;
	}
	inline int hashSub(int row, int col) {
		return row + col;
	}

	bool hasQ(int i, int j, int n) {
		return col[j] || mainDia[hashMain(i, j, n)] || subDia[hashSub(i, j)];
	}
	void backTracking(int n, int level) {
		if (path.size() == n) {
			ret.push_back(path);
			return;
		}

		// 单层搜索
		string s(n, '.');
		for (int i = 0; i < n; i++) {
			if (hasQ(level, i, n)) continue;
			s[i] = 'Q';
			col[i] = true; mainDia[hashMain(level, i, n)] = true; subDia[hashSub(level, i)] = true; // 更新列、主对角线、副对角线
			path.push_back(s);
			cout << "----" << endl; for (auto& e : path) cout << e << endl;
			backTracking(n, level + 1);
			path.pop_back();
			s[i] = '.';
			col[i] = false; mainDia[hashMain(level, i, n)] = false; subDia[hashSub(level, i)] = false;
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		col.resize(n, false);
		mainDia.resize(2 * n, false);
		subDia.resize(2 * n, false);
		backTracking(n, 0);
		return ret;
	}
};


class Solution {
public:
	vector<string> ret;
	vector<string> path;
	vector<bool> used;
	int flag = 0;
	void backTracking(vector<vector<string>>& tickets, string src) {
		if (path.size() == tickets.size() + 1) {
			flag = 1;
			ret = path;
			return;
		}

		string min("ZZZ");
		// 单层搜索src为起点的那个
		for (int i = 0; i < tickets.size(); i++) {
			if (used[i] == true) continue;
			if (tickets[i][0] == src && tickets[i][1] < min) { // 找到一个
				path.push_back(tickets[i][1]);
				used[i] = true;
				backTracking(tickets, tickets[i][1]);
				if (flag == 1) min = tickets[i][1];
				path.pop_back();
				used[i] = false;
			}
		}
	}
	class func{
	public:
		bool operator () (const vector<string>& a, const vector<string>& b) {
			return a[1] < b[1];
		}
	};
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		used.resize(tickets.size(), false);
		sort(tickets.begin(), tickets.end(), func());
		path.push_back("JFK");
		backTracking(tickets, "JFK");
		return ret;
	}
};


class Solution {
public:
	int fib(int n) {
		vector<int> dp;
		dp.resize(n + 1);

		// dp[i] = dp[i - 1] + dp[i - 2]
		for (int i = 0; i <= n; i++) {
			if (i < 2) {
				dp[i] = i;
			}
			else {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
		}

		return dp[n];
	}
};


class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		vector<int> dp(n + 1);
		dp[0] = 0; dp[1] = 1; dp[2] = 2;
		// dp[n] = dp[n - 1] + dp[n - 2]

		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};


class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		// cost[i] 表示站在第i个楼梯上面，再向上爬时需要支付的体力
		//dp[N] = dp[N - 2] + cost[N - 2] 或 dp[N] = dp[N - 1] + cost[N - 1]

		int n = cost.size(); // 阶梯的数量是n或n+1因为可以上一步也可以上2不

		vector<int> dp(n + 1); // dp[i] 表示上到第i个阶梯上面需要消耗的最少体力

		dp[0] = 0; dp[1] = 0;
		if (n <= 1) return 0;
		int cost1 = cost[0];
		int cost2 = cost[1];
		dp[2] = cost1 < cost2 ? cost1 : cost2;

		for (int i = 3; i <= n; i++) {

			//上到第n层阶梯上面的代价可以是  上到第n-2层上的最小代价 + 从第n-2层上支付cost[n-2]再上两步 的代价和
			//                    也可以是 上到第n-1层上的最小代价 + 从第n-1层上支付cost[n-1]再上一步 的代价和
			//                       取两者之中较小的那个即可。
			cost1 = dp[i - 2] + cost[i - 2];
			cost2 = dp[i - 1] + cost[i - 1];
			dp[i] = cost1 < cost2 ? cost1 : cost2;
		}

		return dp[n];
	}
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		// dp[i][j] 表示从[0, 0] 开始到 [i, j] 的路线个数
		// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
		if (m == 1 || n == 1) return 1;
		vector<vector<int>> dp;
		dp.resize(m);
		for (auto& e : dp) {
			e.resize(n);
		}
		dp[0][1] = 1; dp[1][0] = 1;
		for (int j = 0; j < n; j++) {
			dp[0][j] = 1;
		}

		for (int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};

int main()
{
	/*Solution s;
	vector<vector<string>> ret = s.solveNQueens(4);*/




	
	system("pause");
	return 0;
}
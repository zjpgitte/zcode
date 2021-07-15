#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	int maxValueOfBag(vector<int> v, vector<int> value, int vBag) {
		vector<vector<int>> dp(v.size());
		for (int i = 0; i < dp.size(); i++) {
			dp[i].resize(vBag + 1, 0);
		}

		// dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + value[i])

		// ³õÊ¼»¯
		for (int j = 0; j <= vBag; j++) {
			if (j >= v[0]) dp[0][j] = value[0];
		}

		for (int i = 1; i < v.size(); i++) {
			for (int j = 1; j <= vBag; j++) {
				if (j < v[i]) 
					dp[i][j] = dp[i - 1][j];
				else 
					dp[i][j] = max<int>(dp[i - 1][j], dp[i - 1][j - v[i]] + value[i]);
			}
		}

		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[i].size(); j++)
				cout << dp[i][j] << " ";

			cout << endl;
		}

		return 0;
	}
};


int main()
{
	vector<int> v = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	Solution().maxValueOfBag(v, value, 4);
		
	
	system("pause");
	return 0;
}
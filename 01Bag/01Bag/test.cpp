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

//class Solution {
//public:
//	int maxValueOfBag(vector<int> v, vector<int> value, int vBag) {
//		vector<vector<int>> dp(v.size());
//		for (int i = 0; i < dp.size(); i++) {
//			dp[i].resize(vBag + 1, 0);
//		}
//
//		 //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + value[i])
//
//		 // 初始化
//		for (int j = 0; j <= vBag; j++) {
//			if (j >= v[0]) dp[0][j] = value[0];
//		}
//
//		for (int i = 1; i < v.size(); i++) {
//			for (int j = 1; j <= vBag; j++) {
//				if (j < v[i]) 
//					dp[i][j] = dp[i - 1][j];
//				else 
//					dp[i][j] = max<int>(dp[i - 1][j], dp[i - 1][j - v[i]] + value[i]);
//			}
//		}
//
//		for (int i = 0; i < dp.size(); i++) {
//			for (int j = 0; j < dp[i].size(); j++)
//				cout << dp[i][j] << " ";
//
//			cout << endl;
//		}
//
//		return 0;
//	}
//};
	
class Solution {
public:
	int maxValueOfBag(vector<int> weight, vector<int> value, int wBag) {
		//dp[j]表示将若干个物品放到j容量的背包中最大价值是多少

		vector<int> dp(wBag + 1);

		//
		for (int j = 0; j <= wBag; j++) {
			if (j >= weight[0]) dp[j] = value[0];
			else dp[j] = 0;
		}

		for (auto& e : dp) cout << e << " "; cout << endl;

		// dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
		for (int j = wBag; j >= 0; j--) {
			for (int i = 0; i < weight.size(); i++) {
				if (j < weight[i]) continue;
				dp[j] = max<int>(dp[j], dp[j - weight[i]] + value[i]);
			}
			for (auto& e : dp) {
				cout << e << " ";
			}
			cout << endl;
		}

		return dp[wBag];
		
	}
};

int main()
{
	/*vector<int> v = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	Solution().maxValueOfBag(v, value, 4);
	
	vector<vector<int>> dp(5);*/
	
	

	system("pause");
	return 0;
}
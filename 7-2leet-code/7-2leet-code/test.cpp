class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1); // dp[i]的含义是由i个结点组成的二叉搜索树个数。与结点值没有关系
							 // 这i个结点值可以是任意的，只是在本题中结点值是[1，n]的。


		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
		}

		dp[0] = 1; // 可以认为 0 个结点组成的二叉搜索树只有一个是空树

		// dp[i] = dp[j - 1] * dp[i - j];  // j可以是[1,i]的任意值

		for (int i = 1; i <= n; i++) { // 求出每个dp[i]
			// 从[1,i]的每个结点都是头根节点的情况,将不同结点下的情况相加即可
			for (int j = 1; j <= i; j++) {
				//      dp[j - 1] * dp[i - j]意思是j为根节点，左边结点组成二叉搜索树的个数 * 右边结点组成的二叉搜索树的个数         
				//                              j 的左边结点是比j小的有j - 1个，右边是比j大的有i - j个       
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}

		return dp[n];
	}
};

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1); // dp[i] 表示i拆分成的整数的乘积最大值
		dp[2] = 1; dp[1] = 0;

		for (int i = 3; i <= n; i++) {
			//求出dp[i]
			int maxNum = 0;
			for (int j = 1; j <= i / 2; j++) {
				int temp = max(max(j * (i - j), dp[j] * dp[i - j]), max(j * dp[i - j], dp[j] * (i - j)));
				if (temp > maxNum) maxNum = temp;
			}
			dp[i] = maxNum;
		}

		for (auto& e : dp) cout << e << " "; cout << endl;
		return dp[n];
	}
};


class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1); // dp[i]�ĺ�������i�������ɵĶ�������������������ֵû�й�ϵ
							 // ��i�����ֵ����������ģ�ֻ���ڱ����н��ֵ��[1��n]�ġ�


		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
		}

		dp[0] = 1; // ������Ϊ 0 �������ɵĶ���������ֻ��һ���ǿ���

		// dp[i] = dp[j - 1] * dp[i - j];  // j������[1,i]������ֵ

		for (int i = 1; i <= n; i++) { // ���ÿ��dp[i]
			// ��[1,i]��ÿ����㶼��ͷ���ڵ�����,����ͬ����µ������Ӽ���
			for (int j = 1; j <= i; j++) {
				//      dp[j - 1] * dp[i - j]��˼��jΪ���ڵ㣬��߽����ɶ����������ĸ��� * �ұ߽����ɵĶ����������ĸ���         
				//                              j ����߽���Ǳ�jС����j - 1�����ұ��Ǳ�j�����i - j��       
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}

		return dp[n];
	}
};

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1); // dp[i] ��ʾi��ֳɵ������ĳ˻����ֵ
		dp[2] = 1; dp[1] = 0;

		for (int i = 3; i <= n; i++) {
			//���dp[i]
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


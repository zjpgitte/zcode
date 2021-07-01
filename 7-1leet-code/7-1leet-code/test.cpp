#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 01��������
int bagpage(vector<int>& w, vector<int>& v, int bagWeight) {
	int m = w.size();
	int n = bagWeight;
	// ����һ��dp��ά���飬dp[i][j]�ĺ����ǰ� i ֮ǰ��������Ʒ�ŵ�����Ϊ
	// j �ı����У���ʱ�����ļ�ֵ�����ֵ��dp[i][j]
	// ע�⣺i ֮ǰ��������Ʒ����ָ������Ʒ����ֻ��ָʹ������ֵ�����Ǽ�����Ʒ
	vector<vector<int>> dp(m);
	for (auto& e : dp) {
		e.resize(n + 1);
	}

	// ״̬ת�Ʒ��� dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])  
	// dp[i - 1][j] �������Ϊ��i����Ʒ���ŵ���������������Ʒ����֮ǰ�� i-1 ����Ʒ�����������Ʒ�ļ�ֵ.
	// dp[i - 1][j - weight[i]] + v[i] ��������j�����ı�����ȡ��weight[i]��������Ʒ(������[0, i]��)��
	// Ȼ���ٰѵ� i ����Ʒ�Ž�ȥ�ļ�ֵ��
	// dp[i][j]��¼�ľ�������ֵ����Ȼȡ�������������ļ��ɡ�

	
	// ��ʼ����ά����  dp[i][j] Ҫ����i - 1��j - w[i]����˶Ե�һ�к͵�һ��Ҫ���г�ʼ��
	
	// ��ʼ�� dp[0][j] ����0����Ʒ�ŵ�j�����ı����У������ļ�ֵ
	for (int j = 0; j <= bagWeight; j++) {
		if (j < w[0]) { // ��ʱ�ı��������޷����ɵ�0����Ʒ
			dp[0][j] = 0;
		}
		else {
			dp[0][j] = v[0]; // ������ֻ��0��Ʒ��˱����������Ǹ���Ʒ����
		}
	}

	// ��ʼ��dp[i][0] �� i ֮ǰ������Ʒ�ŵ�0�����ı����У������ļ�ֵ����0
	for (int i = 0; i < w.size(); i++) {
		dp[i][0] = 0;
	}

	// �� i֮ǰ����Ʒ�ŵ�j�����ı����еļ�ֵ
	for (int i = 1; i < w.size(); i++) {
		for (int j = 1; j <= bagWeight; j++) {
			if (j < w[i]) { // �����������ɲ���i��Ʒ
				dp[i][j] = dp[i - 1][j]; // i ֮ǰ������Ʒ�ŵ�������� i - 1֮ǰ����Ʒ���뱳����ֵ��һ���ġ�
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				//Ҫô��i��Ʒ�Ž�ȥ�滻��ԭ��������ͬ����������Ʒ��Ҫô�������ǰi - 1��������Ʒ
				// ȡ��ֵ��ļ��ɡ�
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
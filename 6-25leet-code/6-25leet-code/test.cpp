#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	int sum = 0;
	void backTracking(int k, int n, int start) {
		if (sum > n + 1) return; //��֦���������Ѿ���n���ˣ�û��Ҫ�����µݹ��ˡ�

		if (path.size() == k) {  // �Ѿ��ݹ鵽��������������ˣ�û��Ҫ�����µݹ��ˡ�
			if (sum == (n + 1)) { // ��������������
				ret.push_back(path);
			}
			return;
		}

		// �ݹ�����
		for (int i = start; i <= 9; i++) {
			path.push_back(i);
			sum += i;
			backTracking(k, n, i + 1); //���µݹ�����
			path.pop_back(); // ���ݳ�������
			sum -= i;
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		// ����
		backTracking(k, n - 1, 1);
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	// ��[1,n] ���ҳ���k������ɵ��Ӽ�
	void backTracking(int n, int k, int start) {
		if (path.size() == k) {  // �ϲ�Ľ����������
			ret.push_back(path); //������
			return;
		}

		// �ϲ�����������������������
		for (int i = start; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i); // �������
			backTracking(n, k, i + 1); //�ݹ飬�жϵ�ǰ�������Ƿ������������������������淵�أ��������������ݵݹ�ֱ���������Ϊֹ.
			path.pop_back(); // ���ݲ�������֤�ݹ�ǰ������û�иı䡣
		}

	}

	vector<vector<int>> combine(int n, int k) {
		// ���ݷ����Ӽ�
		backTracking(n, k, 1);
		return ret;
	}
};

class Solution {
public:
	vector<string> tel = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> ret;
	string path;
	void backTracking(int k, string& digits, int level) {
		if (k == 0) {
			return;
		}
		if (level == k) { // ���������ֵĸ��������ݹ����
			ret.push_back(path);
			return;
		}

		// ����
		int num = digits[level] - '0';
		for (int i = 0; i < tel[num].size(); i++) {
			path += tel[num][i];
			backTracking(k, digits, level + 1);
			path.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		backTracking(digits.size(), digits, 0);
		return ret;
	}
};

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	int sum = 0;
	void backTracking(vector<int>& candidates, int target, int startIndex) {
		if (sum > target) {
			return;
		}
		if (sum == target) { // �ݹ���ֹ�������Ƹ߶�
			ret.push_back(path);
			return;
		}

		// ����
		for (int i = startIndex; i < candidates.size(); i++) {
			path.push_back(candidates[i]);
			sum += candidates[i];
			backTracking(candidates, target, i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		backTracking(candidates, target, 0);
		return ret;
	}
};

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	vector<bool> used;
	void backTracking(vector<int>& candidates, int target, int sum, int startIndex) {
		if (sum > target) return;
		if (sum == target) { // �ռ����
			ret.push_back(path);
			return;
		}

		// ���������߼�
		for (int i = startIndex; i < candidates.size(); i++) { //�ѱ����Ԫ�ؼ�������
			if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false) { // ��used[i - 1] == false ʱ������ȵ���������ͬһ�㣬û�г�����ͬһ����֦
				continue;
			}
			path.push_back(candidates[i]);
			sum += candidates[i];
			used[i] = true;
			backTracking(candidates, target, sum, i + 1); //�ݹ��������������ռ����
			path.pop_back();
			sum -= candidates[i];
			used[i] = false;
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		used.resize(candidates.size(), false); // ��֦�ϵ�������true;
		// �⼯�������ظ������Ҫ��ȥ��
		backTracking(candidates, target, 0, 0);
		return ret;
	}
};
int main()
{
	
	Solution s;
	vector<vector<int>> ret;

 	ret = s.combinationSum3(9, 45);
	
	system("pause");
	return 0;
}
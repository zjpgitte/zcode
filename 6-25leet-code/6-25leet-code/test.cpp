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
		if (sum > n + 1) return; //剪枝操作。和已经比n大了，没必要再往下递归了。

		if (path.size() == k) {  // 已经递归到满足条件的深度了，没必要再往下递归了。
			if (sum == (n + 1)) { // 满足条件保存结果
				ret.push_back(path);
			}
			return;
		}

		// 递归搜索
		for (int i = start; i <= 9; i++) {
			path.push_back(i);
			sum += i;
			backTracking(k, n, i + 1); //向下递归搜索
			path.pop_back(); // 回溯撤销数据
			sum -= i;
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		// 回溯
		backTracking(k, n - 1, 1);
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	// 在[1,n] 中找出由k个数组成的子集
	void backTracking(int n, int k, int start) {
		if (path.size() == k) {  // 上层的结果满足条件
			ret.push_back(path); //保存结果
			return;
		}

		// 上层结果不满足条件，增加数据
		for (int i = start; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i); // 添加数据
			backTracking(n, k, i + 1); //递归，判断当前的数据是否满足条件。若满足条件保存返回，否则继续添加数据递归直到不能添加为止.
			path.pop_back(); // 回溯操作，保证递归前后数据没有改变。
		}

	}

	vector<vector<int>> combine(int n, int k) {
		// 回溯法找子集
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
		if (level == k) { // 号码中数字的个数决定递归深度
			ret.push_back(path);
			return;
		}

		// 搜索
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
		if (sum == target) { // 递归终止条件控制高度
			ret.push_back(path);
			return;
		}

		// 搜索
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
		if (sum == target) { // 收集结果
			ret.push_back(path);
			return;
		}

		// 单层搜索逻辑
		for (int i = startIndex; i < candidates.size(); i++) { //把本层的元素加入结果集
			if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false) { // 当used[i - 1] == false 时两个相等的数出现在同一层，没有出现在同一个树枝
				continue;
			}
			path.push_back(candidates[i]);
			sum += candidates[i];
			used[i] = true;
			backTracking(candidates, target, sum, i + 1); //递归是向下搜索，收集结果
			path.pop_back();
			sum -= candidates[i];
			used[i] = false;
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		used.resize(candidates.size(), false); // 树枝上的数都是true;
		// 解集不包含重复的组合要先去重
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
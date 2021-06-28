class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	vector<bool> used;
	void backTracking(vector<int>& nums) {
		if (path.size() == nums.size()) {
			ret.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == true) continue;
			path.push_back(nums[i]);
			used[i] = true;
			backTracking(nums);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		used.resize(nums.size(), false);
		backTracking(nums);
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	vector<bool> used; // 记录树枝上的元素使用情况
	void backTracking(const vector<int>& nums) {
		if (path.size() == nums.size()) {
			ret.push_back(path);
			return;
		}

		unordered_set<int> uset; //记录同一个父亲结点下的同一层上使用过的元素
		for (int i = 0; i < nums.size(); i++) {
			if ((i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) || used[i] == true) continue;
			path.push_back(nums[i]);
			used[i] = true;
			uset.insert(nums[i]);
			backTracking(nums);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		used.resize(nums.size(), false);
		sort(nums.begin(), nums.end());
		backTracking(nums);
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	vector<bool> used;
	void backTracking(vector<int>& nums, int startIndex) {
		// 横向遍历结束时终止条件
		if (path.size() >= 2) {
			ret.push_back(path); //要收集每一个结果，因此终止条件是循环结束
		}

		unordered_set<int> uset;
		for (int i = startIndex; i < nums.size(); ++i) {
			if (uset.find(nums[i]) != uset.end()) continue; // 在本层使用过了该元素
			if (path.empty() || nums[i] >= path.back()) {
				path.push_back(nums[i]);
				uset.insert(nums[i]);
				used[i] = true;
				backTracking(nums, i + 1);
				path.pop_back();
				used[i] = false;
			}
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		used.resize(nums.size(), false);
		backTracking(nums, 0);
		return ret;
	}
};
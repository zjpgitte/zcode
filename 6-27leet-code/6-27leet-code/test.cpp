class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	void backTracking(vector<int>& nums, int startIndex) {
		ret.push_back(path);

		for (int i = startIndex; i < nums.size(); i++) {
			path.push_back(nums[i]);
			backTracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		backTracking(nums, 0);
		return ret;
	}
};



class Solution {
public:
	vector<vector<int>> ret;
	vector<int> path;
	vector<bool> used;
	void backTracking(vector<int>& nums, int startIndex) {
		ret.push_back(path);

		for (int i = startIndex; i < nums.size(); i++) {
			if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;  // 当前数和上一个数相等的情况
			used[i] = true;
			path.push_back(nums[i]);
			backTracking(nums, i + 1);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		used.resize(nums.size(), false);
		backTracking(nums, 0);
		return ret;
	}
};
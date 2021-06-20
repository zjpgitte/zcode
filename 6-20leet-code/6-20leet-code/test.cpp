class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		// 只需求出最小子数组的大小即可，无序给出最小子数组的范围。

		int minLength = INT32_MAX;
		int left = 0, right = 0; // 记录窗口的边界

		// 遍历数组，求出每个 >=target 的窗口的大小，并找出最小的那个
		int sum = 0; // 记录窗口内元素的和
		for (right = 0; right < nums.size(); right++) {
			sum += nums[right];
			while (sum >= target) {
				// 找到满足条件的窗口
				int length = right - left + 1; // 记录该窗口的大小
				// 若该窗口比最小的length还小，则更新minlength
				if (length < minLength)
				{
					minLength = length;
				}

				// 缩小窗口。为了找出其它满足条件的窗口，进而找出最小的那个。
				sum -= nums[left];
				++left;
			}
		}

		minLength = minLength == INT32_MAX ? 0 : minLength;
		return minLength;
	}
};


class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (size_t i = 0; i < nums.size(); i++) {
			nums[i] *= nums[i];
		}

		// 平方后数组可能先降序再升序,看成两个升序数组，把大的插入到新数组中
		vector<int> ret;
		ret.resize(nums.size()); //记录结果
		int retI = ret.size() - 1;
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			if (nums[left] > nums[right]) {
				ret[retI] = nums[left];
				retI--;
				left++;
			}
			else{
				ret[retI] = nums[right];
				retI--;
				right--;
			}
		}

		return ret;
	}
};


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int newSize = 0;
		int oldI = 0;

		while (oldI < nums.size()) {
			if (nums[oldI] != val) {
				nums[newSize] = nums[oldI];
				++oldI;
				++newSize;
			}
			else {
				++oldI;
			}
		}

		return newSize;

	}
};


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret;
		ret.resize(n);
		for (size_t i = 0; i < ret.size(); i++) {
			ret[i].resize(n);
		}

		int left = 0, right = n - 1, up = 0, down = n - 1; // 记录边界
		int num = 1;
		// n-1次循环,每次填充边界上的值
		while (left < right) {
			// 填充上边界
			for (int i = left; i < right; i++) {
				ret[up][i] = num++;
			}

			//右边界
			for (int i = up; i < down; i++) {
				ret[i][right] = num++;
			}

			//下边界
			for (int i = right; i > left; i--) {
				ret[down][i] = num++;
			}

			// 左边界
			for (int i = down; i > up; i--) {
				ret[i][left] = num++;
			}

			left++; right--; down--; up++;
		}

		// n是奇数，最后会剩一个位置没有填充
		if (n % 2 != 0)
			ret[left][left] = num;

		return ret;
	}
};
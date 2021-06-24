class Solution {
public:
	int totalFruit(vector<int>& tree) {
		if (tree.size() < 3) {
			return tree.size();
		}
		// 滑动窗口中[left, right) 区间内只有两种数
		int left = 0, right = 0;

		int first = tree[left];
		int second; // 表示区间内的两个不同的数
		int firstTotal = 0; // 一个数的个数
		int secondTotal = 0; // 另一个数的个数
		int maxTotal = 0;

		// 初始化窗口,使[left, right) 区间有两种数
		while (right < tree.size() && tree[right] == first) {
			++firstTotal;
			++right;
		} // right走到第二个数或走完结束 
		if (right >= tree.size()) { // right走完了，说明只有一种数
			return firstTotal;
		}

		second = tree[right]; // 第二种数
		secondTotal++;
		++right; // [left, right) 区间有两种数。

		// 通过判断tree[right]是不是那两种数不断更新right，找出每个满足条件的窗口大小，求出最大的
		while (right < tree.size()) {
			while (right < tree.size() && (tree[right] == first || tree[right] == second)) {
				if (tree[right] == first) {
					++firstTotal;
				}
				else {
					++secondTotal;
				}
				++right;
			}// right走到第三种数或走到结束停下来 

			int sumTotal = firstTotal + secondTotal;
			if (sumTotal > maxTotal) { // 更新最大窗口
				maxTotal = sumTotal;
			}

			if (right >= tree.size()) { // 走到结束
				return maxTotal;
			}

			// right指向第三种数
			// 更新left，使[left, right]只有两种数
			int tempLeft = right - 1;
			int tempTotal = 1;
			while (tree[tempLeft] == tree[tempLeft - 1]) {
				++tempTotal;
				--tempLeft;
			} // left指向下个窗口的第一种数 
			left = tempLeft;

			first = tree[tempLeft];
			firstTotal = tempTotal;
			second = tree[right];
			secondTotal = 1;
			++right; // 扩大窗口
		}

		return maxTotal;

	}
};


class Solution {
public:
	int totalFruit(vector<int>& tree) {
		// 使用滑动窗口，窗口内只有两种元素
		int left = 0, right = 0; // 滑动窗口的边界
		int total = 0; // 滑动窗口中元素的个数
		int first = tree[left], second; // 滑动窗口的
		int maxTotal = 0;


		while (right < tree.size() && tree[right] == first) {
			++total;
			++right;
		}

		if (right >= tree.size()) {
			return total;
		}

		second = tree[right];
		total += 1;

		while (right < tree.size()) {
			++right;
			while (right < tree.size() && (tree[right] == first || tree[right] == second)) { //判断当前窗口是否满足条件(窗口中只有两种元素)
				++total; // 窗口大小+1
				++right;
			}

			if (total > maxTotal) {
				maxTotal = total;
			}

			if (right >= tree.size()) {
				return maxTotal;
			}

			// 走到这，窗口不满足条件
			// 更新left
			int tempLeft = right - 1;
			int tempTotal = 1;
			while (tree[tempLeft] == tree[tempLeft - 1]) {
				tempTotal++;
				--tempLeft;
			}


			// 更新窗口。 更新左右边界，更新大小，更新限制条件。
			left = tempLeft;
			total = tempTotal + 1;
			first = tree[left];
			second = tree[right];
		}

		return maxTotal;
	}
};


// 最小覆盖子串 O(N^3)
class Solution {
public:
	bool includeT(string& s, string& t, int left, int right) {
		// 判断s的[left, right] 是否包含t中的每个字符
		int countS[256] = { 0 };
		int countT[256] = { 0 };
		for (int i = left; i <= right; i++) {
			countS[s[i]]++;
		}
		for (int i = 0; i < t.size(); i++) {
			countT[t[i]]++;
		}

		for (int i = 0; i < t.size(); i++) {
			if (countS[t[i]] < countT[t[i]]) {
				return false;
			}
		}

		return true;
	}
	string minWindow(string s, string t) {
		string mins;
		if (s.size() < t.size()) {
			return mins;
		}

		int minLength = INT32_MAX;

		// 初始化窗口为不满足条件的窗口
		int length = 1;
		int left = 0, right = 0;
		if (includeT(s, t, left, right)) { // 如果满足条件
			mins += t;
			return mins;
		}

		// 不满足条件
		while (right < s.size() && left <= right) {
			if (includeT(s, t, left, right)) { // 窗口满足限制条件
				// 判断该窗口是否是最小的
				length = right - left + 1;
				if (length < minLength) {
					minLength = length;
					mins = string(s.begin() + left, s.begin() + right + 1);
				}
				++left;
			}
			else { // 不满足限制条件
				++right;
			}
		}

		return mins;

	}
};


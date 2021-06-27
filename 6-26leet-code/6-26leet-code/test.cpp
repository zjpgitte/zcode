class Solution {
public:
	vector<vector<string>> ret;
	vector<string> path;
	bool isPalindrome(const string& s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	void backTracking(const string& s, int startIndex) {// startIndex表示分割位置
		if (startIndex >= s.size()) { // 当分割位置是最后一个 
			ret.push_back(path);// 收集结果
			return;
		}

		// 单层搜索逻辑
		for (int i = startIndex; i < s.size(); i++) { // 从startInddex开始到结束有多个分割位置
			if (isPalindrome(s, startIndex, i)) {// 分割区间是回文串，保存该结果
				path.push_back(string(s.begin() + startIndex, s.begin() + i + 1));
			}
			else { // 当前分割区间不是回文串，没必要再向下递归继续切割串了。重新选择本次切割的位置
				continue;
			}
			backTracking(s, i + 1); // 本次切割是回文，进行下次切割或收集结果
			path.pop_back();
		}

	}
	vector<vector<string>> partition(string s) {
		backTracking(s, 0);
		return ret;
	}
};


class Solution {
public:
	vector<string> ret;
	vector<string> path;
	bool isTrue(const string& s, int left, int right) {
		string temp(s.begin() + left, s.begin() + right + 1);
		if (temp.size() > 3) return false;
		cout << temp << endl;
		int num = stoi(temp);
		if (num >= 0 && num <= 255) return true;
		return false;
	}
	void backTracking(const string& s, int startIndex) {
		if (path.size() == 4) {
			string temp;
			temp = temp + path[0] + "." + path[1] + "." + path[2] + "." + path[3];
			ret.push_back(temp);
			return;
		}

		int end = path.size() + s.size() - 5;
		for (int i = startIndex; i <= startIndex + 2 && i < s.size(); i++) {

			if (path.size() == 3)  i = s.size() - 1;
			if (s[startIndex] == '0' && (i != startIndex)) break;
			if (isTrue(s, startIndex, i)) {
				path.push_back(string(s.begin() + startIndex, s.begin() + i + 1));
			}
			else continue;

			backTracking(s, i + 1);
			path.pop_back();
		}
	}
	vector<string> restoreIpAddresses(string s) {
		backTracking(s, 0);
		return ret;
	}
};


class Solution {
public:
	bool isTrue(const string& s, int left, int right) {
		if (left > right) return false;

		if (s[left] == '0' && left != right) return false; // 没有前导0

		if (right - left + 1 > 3) return false;
		int num = 0;
		for (int i = left; i <= right; i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false; // 非法字符
			}
			num = num * 10 + s[i] - '0';
			if (num > 255) {
				return false;
			}
		}
		return true;
	}
	vector<string> ret;
	vector<string> path;
	void backTracking(const string& s, int startIndex) {
		if (path.size() == 3) {
			if (isTrue(s, startIndex, s.size() - 1)) {
				string temp;
				temp = temp + path[0] + "." + path[1] + "." + path[2] + "." + string(s.begin() + startIndex, s.begin() + s.size());
				ret.push_back(temp);
			}
			return;
		}

		for (int i = startIndex; i <= startIndex + 2 && i < s.size(); i++) {
			if (isTrue(s, startIndex, i)) {
				path.push_back(string(s.begin() + startIndex, s.begin() + i + 1));
				backTracking(s, i + 1);
				path.pop_back();
			}
			else break; //数字不合法直接结束本层循环。因为如果出现了前导0，分割符再往后移还是有前导0，如果出现大于255的数字，再往后移还是大于255
		}


	}
	vector<string> restoreIpAddresses(string s) {
		backTracking(s, 0);
		return ret;
	}
};
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
	void backTracking(const string& s, int startIndex) {// startIndex��ʾ�ָ�λ��
		if (startIndex >= s.size()) { // ���ָ�λ�������һ�� 
			ret.push_back(path);// �ռ����
			return;
		}

		// ���������߼�
		for (int i = startIndex; i < s.size(); i++) { // ��startInddex��ʼ�������ж���ָ�λ��
			if (isPalindrome(s, startIndex, i)) {// �ָ������ǻ��Ĵ�������ý��
				path.push_back(string(s.begin() + startIndex, s.begin() + i + 1));
			}
			else { // ��ǰ�ָ����䲻�ǻ��Ĵ���û��Ҫ�����µݹ�����и�ˡ�����ѡ�񱾴��и��λ��
				continue;
			}
			backTracking(s, i + 1); // �����и��ǻ��ģ������´��и���ռ����
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

		if (s[left] == '0' && left != right) return false; // û��ǰ��0

		if (right - left + 1 > 3) return false;
		int num = 0;
		for (int i = left; i <= right; i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false; // �Ƿ��ַ�
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
			else break; //���ֲ��Ϸ�ֱ�ӽ�������ѭ������Ϊ���������ǰ��0���ָ���������ƻ�����ǰ��0��������ִ���255�����֣��������ƻ��Ǵ���255
		}


	}
	vector<string> restoreIpAddresses(string s) {
		backTracking(s, 0);
		return ret;
	}
};

// 时间复杂度O(N + M) 空间O(1)
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int sI = s.size() - 1; // 指向s中不被删除的元素
		int tI = t.size() - 1; // 指向t中不被删除的元素
		int countS = 0; // s中应该被删除的字母数量
		int countT = 0; // t中应该被删除的字母数量

		while (sI >= 0 || tI >= 0) {
			cout << sI << " " << tI << endl;
			while (sI >= 0 && (s[sI] == '#' || countS > 0)) {
				if (s[sI] == '#') {
					++countS;
					--sI;
				}
				else {
					--sI;
					--countS;
				}
			} // 当字符串遍历结束，或者走到一个不应该被删除的字母时循环退出

			while (tI >= 0 && (t[tI] == '#' || countT > 0)) {
				if (t[tI] == '#') {
					--tI;
					++countT;
				}
				else {
					--tI;
					--countT;
				}
			}


			if (sI >= 0 && tI >= 0 && s[sI] == t[tI]) {
				--sI; --tI;
			}
			else if (sI < 0 && tI < 0) {
				return true;
			}
			else {
				return false;
			}
		}

		return true;
	}
};





// 时间复杂度O(N + M) 空间O(N)
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string retS;
		string retT;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '#') {
				if (!retS.empty())
					retS.pop_back();
			}
			else {
				retS += s[i];
			}
		}
		cout << retS << endl;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == '#') {
				if (!retT.empty())
					retT.pop_back();
			}
			else {
				retT += t[i];
			}
		}
		cout << retT << endl;
		return retS == retT;
	}
};



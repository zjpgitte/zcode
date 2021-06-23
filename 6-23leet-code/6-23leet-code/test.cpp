
// ʱ�临�Ӷ�O(N + M) �ռ�O(1)
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int sI = s.size() - 1; // ָ��s�в���ɾ����Ԫ��
		int tI = t.size() - 1; // ָ��t�в���ɾ����Ԫ��
		int countS = 0; // s��Ӧ�ñ�ɾ������ĸ����
		int countT = 0; // t��Ӧ�ñ�ɾ������ĸ����

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
			} // ���ַ������������������ߵ�һ����Ӧ�ñ�ɾ������ĸʱѭ���˳�

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





// ʱ�临�Ӷ�O(N + M) �ռ�O(N)
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



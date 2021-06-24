class Solution {
public:
	int totalFruit(vector<int>& tree) {
		if (tree.size() < 3) {
			return tree.size();
		}
		// ����������[left, right) ������ֻ��������
		int left = 0, right = 0;

		int first = tree[left];
		int second; // ��ʾ�����ڵ�������ͬ����
		int firstTotal = 0; // һ�����ĸ���
		int secondTotal = 0; // ��һ�����ĸ���
		int maxTotal = 0;

		// ��ʼ������,ʹ[left, right) ������������
		while (right < tree.size() && tree[right] == first) {
			++firstTotal;
			++right;
		} // right�ߵ��ڶ�������������� 
		if (right >= tree.size()) { // right�����ˣ�˵��ֻ��һ����
			return firstTotal;
		}

		second = tree[right]; // �ڶ�����
		secondTotal++;
		++right; // [left, right) ��������������

		// ͨ���ж�tree[right]�ǲ��������������ϸ���right���ҳ�ÿ�����������Ĵ��ڴ�С���������
		while (right < tree.size()) {
			while (right < tree.size() && (tree[right] == first || tree[right] == second)) {
				if (tree[right] == first) {
					++firstTotal;
				}
				else {
					++secondTotal;
				}
				++right;
			}// right�ߵ������������ߵ�����ͣ���� 

			int sumTotal = firstTotal + secondTotal;
			if (sumTotal > maxTotal) { // ������󴰿�
				maxTotal = sumTotal;
			}

			if (right >= tree.size()) { // �ߵ�����
				return maxTotal;
			}

			// rightָ���������
			// ����left��ʹ[left, right]ֻ��������
			int tempLeft = right - 1;
			int tempTotal = 1;
			while (tree[tempLeft] == tree[tempLeft - 1]) {
				++tempTotal;
				--tempLeft;
			} // leftָ���¸����ڵĵ�һ���� 
			left = tempLeft;

			first = tree[tempLeft];
			firstTotal = tempTotal;
			second = tree[right];
			secondTotal = 1;
			++right; // ���󴰿�
		}

		return maxTotal;

	}
};


class Solution {
public:
	int totalFruit(vector<int>& tree) {
		// ʹ�û������ڣ�������ֻ������Ԫ��
		int left = 0, right = 0; // �������ڵı߽�
		int total = 0; // ����������Ԫ�صĸ���
		int first = tree[left], second; // �������ڵ�
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
			while (right < tree.size() && (tree[right] == first || tree[right] == second)) { //�жϵ�ǰ�����Ƿ���������(������ֻ������Ԫ��)
				++total; // ���ڴ�С+1
				++right;
			}

			if (total > maxTotal) {
				maxTotal = total;
			}

			if (right >= tree.size()) {
				return maxTotal;
			}

			// �ߵ��⣬���ڲ���������
			// ����left
			int tempLeft = right - 1;
			int tempTotal = 1;
			while (tree[tempLeft] == tree[tempLeft - 1]) {
				tempTotal++;
				--tempLeft;
			}


			// ���´��ڡ� �������ұ߽磬���´�С����������������
			left = tempLeft;
			total = tempTotal + 1;
			first = tree[left];
			second = tree[right];
		}

		return maxTotal;
	}
};


// ��С�����Ӵ� O(N^3)
class Solution {
public:
	bool includeT(string& s, string& t, int left, int right) {
		// �ж�s��[left, right] �Ƿ����t�е�ÿ���ַ�
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

		// ��ʼ������Ϊ�����������Ĵ���
		int length = 1;
		int left = 0, right = 0;
		if (includeT(s, t, left, right)) { // �����������
			mins += t;
			return mins;
		}

		// ����������
		while (right < s.size() && left <= right) {
			if (includeT(s, t, left, right)) { // ����������������
				// �жϸô����Ƿ�����С��
				length = right - left + 1;
				if (length < minLength) {
					minLength = length;
					mins = string(s.begin() + left, s.begin() + right + 1);
				}
				++left;
			}
			else { // ��������������
				++right;
			}
		}

		return mins;

	}
};


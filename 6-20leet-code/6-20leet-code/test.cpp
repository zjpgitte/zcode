class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		// ֻ�������С������Ĵ�С���ɣ����������С������ķ�Χ��

		int minLength = INT32_MAX;
		int left = 0, right = 0; // ��¼���ڵı߽�

		// �������飬���ÿ�� >=target �Ĵ��ڵĴ�С�����ҳ���С���Ǹ�
		int sum = 0; // ��¼������Ԫ�صĺ�
		for (right = 0; right < nums.size(); right++) {
			sum += nums[right];
			while (sum >= target) {
				// �ҵ����������Ĵ���
				int length = right - left + 1; // ��¼�ô��ڵĴ�С
				// ���ô��ڱ���С��length��С�������minlength
				if (length < minLength)
				{
					minLength = length;
				}

				// ��С���ڡ�Ϊ���ҳ��������������Ĵ��ڣ������ҳ���С���Ǹ���
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

		// ƽ������������Ƚ���������,���������������飬�Ѵ�Ĳ��뵽��������
		vector<int> ret;
		ret.resize(nums.size()); //��¼���
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

		int left = 0, right = n - 1, up = 0, down = n - 1; // ��¼�߽�
		int num = 1;
		// n-1��ѭ��,ÿ�����߽��ϵ�ֵ
		while (left < right) {
			// ����ϱ߽�
			for (int i = left; i < right; i++) {
				ret[up][i] = num++;
			}

			//�ұ߽�
			for (int i = up; i < down; i++) {
				ret[i][right] = num++;
			}

			//�±߽�
			for (int i = right; i > left; i--) {
				ret[down][i] = num++;
			}

			// ��߽�
			for (int i = down; i > up; i--) {
				ret[i][left] = num++;
			}

			left++; right--; down--; up++;
		}

		// n������������ʣһ��λ��û�����
		if (n % 2 != 0)
			ret[left][left] = num;

		return ret;
	}
};
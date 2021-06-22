
// ���ֲ��� ��

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		// ��������ʹ�ö��ֲ���
		int left = 0, right = nums.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			if (target > nums[mid]) {
				left = mid + 1;
				mid = (left + right) / 2;
			}
			else if (target < nums[mid]) {
				right = mid - 1;
				mid = (left + right) / 2;
			}
			else {
				return mid;
			}
		}


		if (target > nums[mid]) {
			return mid + 1;
		}
		else {
			return mid;
		}
	}
};


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		ret.resize(2);
		ret[0] = ret[1] = -1;
		if (nums.size() == 0) {
			return ret;
		}
		// ���ֲ����ҵ�target�Ĵ���λ��
		int left = 0, right = nums.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (target > nums[mid]) {
				left = mid + 1;
			}
			else if (target < nums[mid]) {
				right = mid - 1;
			}
			else {
				// �ҵ�һ�������һ��
				int begin = mid, end = mid;
				while (begin >= 0 && nums[begin] == target) {
					--begin;
				}
				while (end < nums.size() && nums[end] == target) {
					++end;
				}
				ret[0] = begin + 1;
				ret[1] = end - 1;
				return ret;
			}
		}


		return ret;
	}
};


class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		unsigned long long mid;

		while (left <= right) {
			mid = (left + right) / 2;

			if (mid * mid > x) {
				right = mid - 1;
			}
			else if (mid * mid < x) {
				left = mid + 1;
			}
			else {
				return mid;
			}

		}

		if (mid * mid < x) {
			return mid;
		}
		else {
			return mid - 1;
		}

	}
};


class Solution {
public:
	bool isPerfectSquare(int num) {
		// ��[0, num] ��������ʹ�ö��ֲ���
		int left = 0, right = num;
		long long mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (mid * mid > num) {
				right = mid - 1;
			}
			else if (mid * mid < num) {
				left = mid + 1;
			}
			else {
				return true;
			}
		}

		return false;
	}
};



class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int newI = 0;
		int oldI = 0;
		// oldIʼ��ָ����ͬԪ�صĵ�һ��, newIʼ��ָ����Բ����λ��
		if (nums.size() == 0) {
			return newI;
		}

		while (oldI < nums.size()) {
			nums[newI] = nums[oldI];
			++newI;
			while (oldI + 1 < nums.size() && nums[oldI + 1] == nums[oldI]) {
				++oldI;
			}
			++oldI; //oldI�ߵ���һ����ͬ��Ԫ��λ�ô������β��
		}

		return newI;
	}
};


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int oldI = 0; // ָ���0Ԫ��
		int newI = 0; // ���Դ�ŷ�0Ԫ�ص�λ��
		while (oldI < nums.size()) {
			if (nums[oldI] != 0) {
				nums[newI] = nums[oldI];
				++newI;
			}
			++oldI;
		}
		while (newI < nums.size()) {
			nums[newI] = 0;
			++newI;
		}
	}
};


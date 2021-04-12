#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int max = numbers[0], min = numbers[0];
		//遍历数组找出最大最小值
		for (const auto& e : numbers)
		{
			if (e > max)
			{
				max = e;
			}
			else if (e < min)
			{
				min = e;
			}
		}

		int gap = max - min;
		//计数数组
		vector<int> count;
		count.resize(gap + 1, 0);
		for (const auto& e : numbers)
		{
			count[e - min]++;
		}

		for (int i = 0; i < count.size(); i++)
		{
			if (count[i] > numbers.size() / 2)
			{
				return i + min;
			}

		}

		return 0;
	}
};



#include "test.h"

// 求两个数组的交集

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// 对nums1和nums2去重
		set<int> s1;
		set<int> s2;

		for (auto& e : nums1)
		{
			s1.insert(e);
		}
		for (auto& e : nums2)
		{
			s2.insert(e);
		}

		set<int>::iterator it1 = s1.begin();
		set<int>::iterator it2 = s2.begin();
		vector<int> ret;
		while (it1 != s1.end() && it2 != s2.end())
		{
			if (*it1 == *it2)
			{
				ret.push_back(*it1);
				it1++;
				it2++;
			}
			else if (*it1 < *it2)
			{
				it1++;
			}
			else
			{
				it2++;
			}
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// 对两个数组去重
		set<int> s1;
		set<int> s2;

		// 把两个数组元素分别插入到不同的set中去重
		for (auto e : nums1)
		{
			s1.insert(e);
		}

		for (auto e : nums2)
		{
			s2.insert(e);
		}

		//分别遍历去重后的两组数，对每个元素计数
		map<int, int> m;
		for (auto& e : s1)
		{
			m[e]++;
		}
		for (auto& e : s2)
		{
			m[e]++;
		}

		// 找出出现次数是2的那个元素
		vector<int> ret;
		for (auto& e : m)
		{
			if (e.second == 2)
			{
				ret.push_back(e.first);
			}
		}

		return ret;
	}
};


// 重复出现的元素
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		// 计数
		unordered_map<int, int> countMap;
		for (auto& e : nums)
		{
			countMap[e]++;
		}

		for (auto& e : countMap)
		{
			if (e.second >= 2)
			{
				return true;
			}
		}

		return false;
	}
};


// 最不常出现的单词
class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		// 统计每个句子中每个单词出现次数
		map<string, int> countMap;
		for (auto wordBegin = s1.begin(); wordBegin != s1.end();)
		{
			auto wordEnd = find(wordBegin, s1.end(), ' ');
			string word(wordBegin, wordEnd);
			countMap[word]++;
			if (wordEnd != s1.end())
				wordBegin = wordEnd + 1;
			else
				wordBegin = wordEnd;
		}
		for (auto wordBegin = s2.begin(); wordBegin != s2.end();)
		{
			auto wordEnd = find(wordBegin, s2.end(), ' ');
			string word(wordBegin, wordEnd);
			countMap[word]++;
			if (wordEnd != s2.end())
				wordBegin = wordEnd + 1;
			else
				wordBegin = wordEnd;
		}

		vector<string> ret;
		for (auto& e : countMap)
		{
			if (e.second == 1)
			{
				ret.push_back(e.first);
			}
		}

		return ret;
	}
};
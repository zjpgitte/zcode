#include "test.h"

// ����������Ľ���

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// ��nums1��nums2ȥ��
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
		// ����������ȥ��
		set<int> s1;
		set<int> s2;

		// ����������Ԫ�طֱ���뵽��ͬ��set��ȥ��
		for (auto e : nums1)
		{
			s1.insert(e);
		}

		for (auto e : nums2)
		{
			s2.insert(e);
		}

		//�ֱ����ȥ�غ������������ÿ��Ԫ�ؼ���
		map<int, int> m;
		for (auto& e : s1)
		{
			m[e]++;
		}
		for (auto& e : s2)
		{
			m[e]++;
		}

		// �ҳ����ִ�����2���Ǹ�Ԫ��
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


// �ظ����ֵ�Ԫ��
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		// ����
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


// ������ֵĵ���
class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		// ͳ��ÿ��������ÿ�����ʳ��ִ���
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
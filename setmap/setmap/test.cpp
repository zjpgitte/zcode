#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <functional>

using namespace std;
void testSet()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(8);
	s.insert(2);
	s.insert(1);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	set<int>::iterator ret = find(s.begin(), s.end(), 8);
	if (ret == s.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "found" << endl;
	}

	ret = s.find(8);
	if (ret != s.end())
	{
		cout << "found" << endl;
	}
}

void testMap()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("±Ê", "pen"));
	dict.insert(pair<string, string>("Ç¦±Ê", "pencil"));
	dict.insert(pair<string, string>("Æ»¹û", "apple"));
	dict.insert(pair<string, string>("Æ»¹û", "apple"));
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void testCount()
{
	string strs[] = { "Æ»¹û", "Ïã½¶", "Ïã½¶", "Î÷¹Ï", "ÁñÁ«", "Æ»¹û","Î÷¹Ï", "Î÷¹Ï" };
	map<string, int> countMap;
	/*for (auto& e : strs)
	{
		map<string, int>::iterator it = countMap.find(e);
		if (it == countMap.end())
		{
			countMap.insert(make_pair(e, 1));
		}
		else
		{
			it->second++;
		}
	}*/



	for (auto& e: strs)
	{
		countMap[e]++;
	}

	for (auto& e: countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	//testSet();

	//testMap();

	testCount();

	system("pause");
	return 0;
}
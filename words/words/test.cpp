#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void toLitter(string& s)
{
	for (auto& e : s)
	{
		if (e >= 'A' && e <= 'Z')
		{
			e = e - 'A' + 'a';
		}
	}
}

int main()
{
	string s;
	getline(cin, s);
	map<string, int> m;

	// 大写字母转小写
	toLitter(s);

	// 每个单词插入到m中
	// 确定每个单词
	string::iterator startWord = s.begin();
	string::iterator endWord = s.begin();
	while (*endWord != '.')
	{
		if (*endWord == ' ')
		{
			string word(startWord, endWord);
			m[word]++;
			++endWord;
			startWord = endWord;
		}
		else
		{
			++endWord;
		}
	}
	string word(startWord, endWord);
	m[word]++;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}

	return 0;
}
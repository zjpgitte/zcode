#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	int count[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		count[str2[i]] = 1;
	}

	string ret;
	for (int i = 0; i < str1.size(); i++)
	{
		if (count[str1[i]] == 0)
		{
			ret.push_back(str1[i]);
		}
	}

	cout << ret;

	return 0;
}
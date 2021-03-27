#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	//cin >> s;
	getline(cin, s); //可以读取空格

	//找最后一个空格
	size_t pos = s.find_last_of(' ');

	if (pos == string::npos) //没找到空格
	{
		cout << s.size() << endl;
	}
	else // 找到空格
	{
		cout << (s.size() - pos - 1) << endl;
	}

	return 0;
}
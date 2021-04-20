#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string str;
	getline(cin, str);

	reverse(str.begin(), str.end());

	string::iterator start = str.begin();

	while (start != str.end())
	{
		auto end = find(start, str.end(), ' ');
		reverse(start, end);
		if (end != str.end())
			start = end + 1;
		else
			start = end;
	}

	cout << str;

	return 0;
}
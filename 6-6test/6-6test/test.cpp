#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class cmpV
{
public:
	bool operator () (pair<string, int> a, pair<string, int> b)
	{
		return a.second > b.second;
	}
};

int main()
{

	vector<pair<string, int>> v;
	v.push_back(make_pair("hello", 1));
	v.push_back(make_pair("ok", 2));
	v.push_back(make_pair("h", 4));
	v.push_back(make_pair("yes", 5));
	v.push_back(make_pair("ye", 5));
	v.push_back(make_pair("no", 3));

	sort(v.begin(), v.end(), cmpV());



	return 0;
}
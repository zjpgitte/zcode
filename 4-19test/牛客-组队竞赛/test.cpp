#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a_i;
	vector<long long> val;
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> a_i;
		val.push_back(a_i);
	}

	sort(val.begin(), val.end());

	long long ret = 0;
	for (int i = 3 * n - 2; i > n - 1; i -= 2)
	{
		ret += val[i];
	}

	cout << ret;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long long A_i;
	vector<long long> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A_i;
		v.push_back(A_i);
	}

	int count = 0;
	int start = 0, end = 1;
	while (start < v.size())
	{
		if (end >= v.size())
		{
			count++;
			break;
		}

		if (v[end] > v[start])
		{
			//升序子序列
			while (end + 1 < v.size() && v[end + 1] > v[end])
			{
				end++;
			}
			start = end + 1;
			end = start + 1;
			count++;
		}
		else if (v[end] < v[start])
		{
			//降序子序列
			while (end + 1 < v.size() && v[end + 1] < v[end])
			{
				end++;
			}
			start = end + 1;
			end = start + 1;
			count++;
		}
		else
		{
			end++;
		}


	}

	cout << count;

	return 0;
}

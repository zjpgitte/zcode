#include <iostream>
#include <algorithm>

using namespace std;

// 辗转相处法求最大公约数
// 通过最大公约数求最小公倍数

int main()
{
	int A, B;
	cin >> A >> B;

	int max = A, min = B;
	if (max < min)
	{
		swap(max, min);
	}

	int reminder = max % min;
	while (reminder != 0)
	{
		max = min;
		min = reminder;
		reminder = max % min;
	}

	int ret = (A / min) * (B / min) * min;
	cout << ret << endl;

	return 0;
}
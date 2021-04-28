#include <iostream>
#include <algorithm>

using namespace std;

// շת�ദ�������Լ��
// ͨ�����Լ������С������

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
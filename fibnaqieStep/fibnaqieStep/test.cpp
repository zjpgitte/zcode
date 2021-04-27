#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{

	int N;
	cin >> N;

	int first = 0, second = 1, third;
	int count = abs(N - first);

	if (abs(N - second) < count)
	{
		count = N - second;
	}
	else
	{
		cout << count;
		return 0;
	}

	while (true)
	{
		third = first + second;
		if (abs(third - N) <= count)
		{
			count = abs(third - N);
			first = second;
			second = third;
		}
		else
		{
			cout << count;
			return 0;
		}
	}

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int arr[3][3] = { { 4, 9, 8 }, 
					  { 2, 3, 4 }, 
					  { 3, 4, 8} };
	int n = 3;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		int minj = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] < arr[i][minj])
			{
				minj = j;
			}
		}

		int k;
		for (k = 0; k < n; k++)
		{
			if (arr[k][minj] > arr[i][minj])
			{
				break;
			}
		}

		if (k >= 3)
		{
			printf("%dÊÇ°°µã\n", arr[i][minj]);
		}
	}

	system("pause");
	return 0;
}
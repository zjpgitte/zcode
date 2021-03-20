#include <iostream>
using namespace std;

void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{

	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 3;

	printf("后移前：");
	Print(a, n);

	for (int i = 0; i < k; i++)
	{
		int temp = a[n - 1];
		for (int j = n - 2; j >= 0; j--)
		{
			a[j + 1] = a[j];
		}
		a[0] = temp;
	}

	printf("后移3位后：");
	Print(a, n);
	
	
	

	system("pause");
	return 0;
}
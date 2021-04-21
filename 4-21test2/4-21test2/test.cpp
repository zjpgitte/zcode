#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int IsTruePos(int row, int col, int *a)
{
	//判断每一行的皇后是否满足条件
	for (int i = 0; i < row; i++)
	{
		if (a[i] == col || (abs(row - i) == abs(col - a[i])))
		{
			return 0;
		}
	}

	return 1;
}

void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == a[i])
			{
				printf(" 1");
			}
			else
			{
				printf(" 0");
			}
		}
		printf("\n");
	}
	printf("\n");

}

int main()
{
	int n = 8;
	printf("输入阶数:");
	scanf("%d", &n);
	int count = 0;
	int i = 0;
	int j = 0;
	int *a = (int*)malloc(sizeof(int) * n);
	while (i >= 0)
	{
		//第i个皇后找合适的位置
		while (j < n)
		{
			if (IsTruePos(i, j, a))
			{
				a[i] = j;
				break;
			}
			j++;
		}

		if (j >= n)
		{
			i--;
			if (i > 0)
				j = a[i] + 1;
		}
		else
		{
			i++;
			j = 0;
		}
		if (i >= n)
		{
			Print(a, n);
			i = n - 1;
			j = a[i] + 1;
			count++;
		}
	}

	printf("一共有%d种\n", count);

	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
void backtrack(int k); //位置尝试，要求使用递归
int n;//皇后个数
int *arr, *brr;
int c = 0, t = 0;
void gs(int x, int y)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (arr[i*n + y] == 0)	arr[i*n + y] = x + 1;
	}
	i = x; j = y;
	while (i<n && j<n)
	{
		i++;
		j++;
	}
	while (i>0 && j>0)
	{
		i--;
		j--;
		if (arr[i*n + j] == 0)	arr[i*n + j] = x + 1;
	}
	i = x; j = y;
	while (i<n && j >= 0)
	{
		i++;
		j--;
	}
	while (i>0 && j < n)
	{
		i--;
		j++;
		if (arr[i*n + j] == 0) 	arr[i*n + j] = x + 1;
	}

}
void gh(int x, int y)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		if (arr[i*n + y] == x + 1)	arr[i*n + y] = 0;
	}
	i = x; j = y;
	while (i<n && j<n)
	{
		i++;
		j++;
	}
	while (i>0 && j>0)
	{
		i--;
		j--;
		if (arr[i*n + j] == x + 1)	arr[i*n + j] = 0;
	}
	i = x; j = y;
	while (i<n && j >= 0)
	{
		i++;
		j--;
	}
	while (i>0 && j < n)
	{
		i--;
		j++;
		if (arr[i*n + j] == x + 1)	arr[i*n + j] = 0;
	}

}
void prt()
{
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("第%d皇后在%d列\n", i + 1, brr[i] + 1);
	}
	printf("\n");
}
void backtrack(int k)   //位置尝试，要求使用递归
{
	int i, j, s = k;
	if (s == n)
	{
		prt();
		c++;
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		if (arr[s*n + i] == 0)
		{
			brr[s] = i;
			gs(s, i);
			backtrack(s + 1);
			gh(s, i);

		}
	}
}
int main()
{
	int i = 0, j = 0;
	printf("请输入n：");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n*n);
	brr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			arr[i*n + j] = 0;
		brr[i] = 0;
	}

	backtrack(0);
	printf("一共有%d种方案\n", c);
}
#include "stdio.h"
#include "math.h"
int a[100];   //皇后位置
int n;       //棋盘n*n，n个皇后
int total = 0;   //方案总数
void backdate(int k);  //寻找皇后位置



void prt()
{
	int i;
	printf("huang hou\n");
	for (i = 1; i <= n; i++)
	{
		printf("第%d皇后在%d列\n", i, a[i]);
	}
	printf("huang hou\n");
	total++;

}
int check_2(int *a, int n)
{
	int i, j;
	for (i = 1; i <= n - 1; i++)
	{
		if ((abs(a[i] - a[n]) == n - i) || (a[i] == a[n]))
			return 0;
	}
	return 1;
}
void backdate(int k)
{
	int i, j;

	a[1] = 0;
	while (k > 0)
	{
		a[k] = a[k] + 1;
		while ((a[k] <= n) && (!check_2(a, k)))
		{
			a[k] = a[k] + 1;
		}
		if (a[k] <= n)
		{
			if (k == n)
			{
				prt();


			}
			else
			{
				k = k + 1;
				a[k] = 0;
			}
		}
		else
		{
			k = k - 1;
		}
	}
}

void main()
{
	printf("请输入n：");
	scanf("%d", &n);
	backdate(1);
	printf("一共有%d种方案\n", total);
}
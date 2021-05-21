#include<stdio.h>
#include<stdlib.h>

int fx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int fy[8] = { 2, -2, -1, 1, 2, -2, 1, -1 };
int arr[5][5];
int c = 0;

void prt()
{
	int i, j;
	c++;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void search(int x, int y, int t)  //路径寻找，要求使用递归的函数
{
	int i;
	if (x >= 0 && y >= 0 && x < 5 && y < 5)
	{
		if (arr[x][y] != 0)	return 0;
		arr[x][y] = t;
		if (t == 25)
		{
			prt();
			arr[x][y] = 0;
			return 0;
		}
		for (i = 0; i < 8; i++)
		{
			search(x + fx[i], y + fy[i], t + 1);
		}
		arr[x][y] = 0;
	}
}

int main()
{
	search(0, 0, 1);
	printf("路径总数%d\n", c);
	return 0;
}
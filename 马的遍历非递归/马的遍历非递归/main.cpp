#include<stdio.h>
int fx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int fy[8] = { 2, -2, -1, 1, -2, 2, 1, -1 };
int arr[5][5];
int count = 0, t = 1;

void prt()
{
	int i, j;
	count++;
	printf("output count=%d\n\n", count);
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

}

int	JC(int x, int y)
{
	if (x >= 0 && y >= 0 && x < 5 && y < 5)
	{
		if (arr[x][y] == 0)	return 1;
		if (arr[x][y] == t)	return 2;
	}
	return 0;
}

void maze()
{
	int x = 0, y = 0, i = 0, j;
	arr[0][0] = t;
	while (1)
	{

		for (; i < 8; i++)
		{
			while (JC(x + fx[i], y + fy[i]) == 1)
			{
				t++;
				x = x + fx[i];
				y = y + fy[i];
				arr[x][y] = t;
				i = 0;
				if (t == 25)
				{
					prt();
					arr[x][y] = 0;
					t--;
					for (j = 0; j < 8; j++)
					{
						if (JC(x + fx[j], y + fy[j]) == 2)
						{
							x = x + fx[j];
							y = y + fy[j];
							break;
						}
					}
					i = (j + 4) % 8 + 1;
				}
			}
		}
		if (t == 1)	break;
		t--;
		arr[x][y] = 0;
		for (j = 0; j < 8; j++)
		{
			if (JC(x + fx[j], y + fy[j]) == 2)
			{
				x = x + fx[j];
				y = y + fy[j];
				break;
			}
		}
		i = (j + 4) % 8 + 1;

	}
}
int main()
{
	maze();
	printf("\nÂ·¾¶×ÜÊýcount=%d\n", count);
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int n = 5;
	int **arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	int rowStart = 0, rowEnd = n - 1;
	int colStart = 0, colEnd = n - 1;
	int val = 1;

	while (rowStart <= rowEnd && colStart <= colEnd)
	{
		int i = rowStart, j = colStart;
		//写入列
		while (i <= rowEnd)
		{
			arr[i][j] = val++;
			i++;
		}
		i--;
		j++;
		//写入行
		while (j <= colEnd)
		{
			arr[i][j] = val++;
			j++;
		}
		j--;
		i--;
		//写入列
		while (i >= rowStart)
		{
			arr[i][j] = val++;
			i--;
		}
		i++;
		j--;
		//写入行
		while (j > colStart )
		{
			arr[i][j] = val++;
			j--;
		}
		
		rowStart++;
		rowEnd--;
		colStart++;
		colEnd--;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}
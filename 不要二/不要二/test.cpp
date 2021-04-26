#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int row, col;
	cin >> col >> row;

	vector<vector<int>> vv(row);

	int count = 0;

	int i = 0;
	while (i < row)
	{
		vv[i].resize(col);
		if (i >= 2 && vv[i - 2][0] == 1)
		{
			vv[i][0] = 0;
			if (col > 1)
			{
				vv[i][1] = 0;
			}

		}
		else
		{
			vv[i][0] = 1;
			if (col > 1)
			{
				vv[i][1] = 1;
				count += 2;
			}
			else
			{
				count += 1;
			}

		}
		i++;
	}

	for (i = 0; i < row; i++)
	{
		for (int j = 2; j < col; j++)
		{
			if (vv[i][j - 2] == 1)
			{
				vv[i][j] = 0;
			}
			else
			{
				vv[i][j] = 1;
				count++;
			}
		}
	}

	cout << count;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	//steps[i] 表示从N到i最少需要几步。若j 是 i 的约数,则从i 到 j 只需要一步即可.
	//那么 第i+j个台阶 要么通过i走一步到达，即steps[i+j] = steps[i] + 1;
	//要么通过其它途径到达，无论如何只要可以到达steps[i + j]都会有一个小于INT_MAX的值
	//至于steps[i + j]的值具体是多少，取小的即可。
	//状态转移方程: steps[i + j] = min(steps[i] + 1, steps[i + j]);
	//但是如果都不能到达i，那通过i到达i+j就无从谈起。但是并不保证其它途径不能到达i+j
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;

		//找到i可以到达的每一个台阶 i+j，求出最小步数。前提是可以到达 i
		for (int i = N; i <= M; i++)
		{
			if (steps[i] == INT_MAX)  // i 不能到达
			{
				continue;
			}

			for (int j = 2; (j * j) <= i; j++) //求 i 的公约数 
			{
				if (i % j == 0)  // i可以一步到达 i+j 或者 i + i/j;
				{
					if (i + j <= M)
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					if (j != i / j && (i + i / j <= M))
						steps[i + i / j] = min(steps[i] + 1, steps[i + i / j]);
				}
			}
		}

		if (steps[M] == INT_MAX)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << steps[M] << endl;
		}
	}

	return 0;
}
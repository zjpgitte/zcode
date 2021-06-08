#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<string> v;
	while (cin >> n)
	{
		v.resize(n);
		getchar();
		for (int i = 0; i < n; i++)
		{
			getline(cin, v[i]);
		}

		int countPool = 0; // 连接池的总连接数
		int countCur = 0; // 当前已使用的连接数

		for (int i = 0; i < n; i++)
		{
			cout << v[i][2] << endl;
			if (v[i][2] == 'c') // 来了一个新链接
			{
				if (countCur >= countPool) // 链接池满
				{
					countPool++;
					countCur++;
				}
				else
				{
					countCur++;
				}
			}
			else // 断开一个新链接 
			{
				countCur--;
			}
		}

		cout << countPool << endl;
	}

	return 0;
}
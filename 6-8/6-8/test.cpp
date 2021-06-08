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

		int countPool = 0; // ���ӳص���������
		int countCur = 0; // ��ǰ��ʹ�õ�������

		for (int i = 0; i < n; i++)
		{
			cout << v[i][2] << endl;
			if (v[i][2] == 'c') // ����һ��������
			{
				if (countCur >= countPool) // ���ӳ���
				{
					countPool++;
					countCur++;
				}
				else
				{
					countCur++;
				}
			}
			else // �Ͽ�һ�������� 
			{
				countCur--;
			}
		}

		cout << countPool << endl;
	}

	return 0;
}
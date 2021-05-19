#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	//steps[i] ��ʾ��N��i������Ҫ��������j �� i ��Լ��,���i �� j ֻ��Ҫһ������.
	//��ô ��i+j��̨�� Ҫôͨ��i��һ�������steps[i+j] = steps[i] + 1;
	//Ҫôͨ������;������������ֻҪ���Ե���steps[i + j]������һ��С��INT_MAX��ֵ
	//����steps[i + j]��ֵ�����Ƕ��٣�ȡС�ļ��ɡ�
	//״̬ת�Ʒ���: steps[i + j] = min(steps[i] + 1, steps[i + j]);
	//������������ܵ���i����ͨ��i����i+j���޴�̸�𡣵��ǲ�����֤����;�����ܵ���i+j
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;

		//�ҵ�i���Ե����ÿһ��̨�� i+j�������С������ǰ���ǿ��Ե��� i
		for (int i = N; i <= M; i++)
		{
			if (steps[i] == INT_MAX)  // i ���ܵ���
			{
				continue;
			}

			for (int j = 2; (j * j) <= i; j++) //�� i �Ĺ�Լ�� 
			{
				if (i % j == 0)  // i����һ������ i+j ���� i + i/j;
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
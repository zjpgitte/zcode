#include "stdio.h"
#include "math.h"
int a[100];   //�ʺ�λ��
int n;       //����n*n��n���ʺ�
int total = 0;   //��������
void backdate(int k);  //Ѱ�һʺ�λ��



void prt()
{
	int i;
	printf("huang hou\n");
	for (i = 1; i <= n; i++)
	{
		printf("��%d�ʺ���%d��\n", i, a[i]);
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
	printf("������n��");
	scanf("%d", &n);
	backdate(1);
	printf("һ����%d�ַ���\n", total);
}
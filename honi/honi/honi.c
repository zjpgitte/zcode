#include <stdio.h>
void move(char a, char b, int n)
{
	printf("��%c�ϵĵ�%d�������Ƶ�%c��\n", a, n, b);
}
void honi(char a, char b, char c, int n)
{
	if (n == 1)
	{
		move(a, b, n);
		return;
	}

	honi(a, c, b, n - 1);
	move(a, b, n);
	honi(c, b, a, n - 1);
}

int main()
{
	
	honi('A', 'B', 'C', 3);

	system("pause");

	return 0;
}
#include <stdio.h>
void move(char a, char b, int n)
{
	printf("Move dish %d form %c to %c\n", n, a, b);
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
	
	honi('A', 'C', 'B', 3);

	system("pause");

	return 0;
}
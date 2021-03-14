#include <iostream>

using namespace std;

int main()
{

	int money[5] = { 50, 20, 10, 5, 1 };
	int x = 20;
	int y = 80; 
	int z = y - x;
	int countMoney = 0;
	
	for (int i = 0; i < 5; i++)
	{
		int count = z / money[i];
		countMoney += count;
		z -= money[i] * count;
		if (z == 0)
		{
			break;
		}
	}


	system("pause");
	return 0;
}
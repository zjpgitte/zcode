#include<stdio.h>
#include<windows.h>
int main()
{
	int distance = 500, reserve = 500, num = 1; //要使消耗最少，则最后一个储油点储油500加仑，距终点500km
	while (distance < 1000)
	{
		printf("储油点:%d,到起点距离:%d,储油%d\n", num, 1000 - distance, reserve);
		distance += 500 / (2 * num + 1);       //运输油来回的次数必须为单数，保证最后一次运输完成后车驶向终点方向
		reserve += 500;                        //从最后一站到前一站储油量要增加500（车的最大油量），保证车的运输次数最大化
		num++;
	}
	reserve += (1000 - distance)*(2 * num + 1);
	printf("在起点处需要储油%d加仑\n", reserve);


	system("pause");
	return 0;
}
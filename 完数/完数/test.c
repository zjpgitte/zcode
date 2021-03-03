#include <stdio.h>

//int main()
//{
//	int i = 2;
//	for (i = 2; i <= 1000; i++)
//	{
//		int s = 1;
//		int arr[100];
//		int size = 0;
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				s += j;
//				arr[size++] = j;
//			}
//		}
//
//		if (i == s)
//		{
//			printf("完数:%d\n", i);
//			printf("因子:");
//			for (int k = 0; k < size; k++)
//			{
//				printf("%d ", arr[k]);
//			}
//			printf("\n");
//		}
//
//	}
//
//	system("pause");
//	return 0;
//}


#define MAX(A,B) ((A) > (B) ? (A):(B))

int main()
{
	int a = MAX(1, 2);


	system("pause");
	return 0;
}
#include<stdio.h>
#include<windows.h>
int main()
{
	int distance = 500, reserve = 500, num = 1; //Ҫʹ�������٣������һ�����͵㴢��500���أ����յ�500km
	while (distance < 1000)
	{
		printf("���͵�:%d,��������:%d,����%d\n", num, 1000 - distance, reserve);
		distance += 500 / (2 * num + 1);       //���������صĴ�������Ϊ��������֤���һ��������ɺ�ʻ���յ㷽��
		reserve += 500;                        //�����һվ��ǰһվ������Ҫ����500�������������������֤��������������
		num++;
	}
	reserve += (1000 - distance)*(2 * num + 1);
	printf("����㴦��Ҫ����%d����\n", reserve);


	system("pause");
	return 0;
}
#include "class.h"

int main()
{

	//Date d1; //���ඨ������ı��� d1 ���Ƕ���
	//Date d2; //�������һ������

	//Date d1(2000, 1, 1);

	
	Date d1(2000, 2, 2);
	Date d2; //��ʼ����ʱ��Ҫ�ÿ������캯��
	Date d3;

	d3 = d2 = d1;  // ��ֵ��ʱ���õ���ֵ�����
	d1 == d2;

	d1.Print();
	d2.Print();
	d3.Print();

	system("pause");
	return 0;
}


#include "hashtable.hpp"
#include "mayunordered_map.h"
#include "myunordered_set.h"

void testSpeed()
{
	srand((unsigned)time(nullptr));
	int n = 10000000;
	set<int> rbset;
	unordered_set<int> hashset;


	int begin1 = clock();  // clock()�ǽ���������ִ�е�������õ�ʱ��
	for (int i = 0; i < n; i++)
	{
		int num = rand() % n;
		rbset.insert(num);

	}
	int end1 = clock();
	int begin2 = clock();
	for (int i = 0; i < n; i++)
	{
		int num = rand() % n;
		hashset.insert(num);
	}
	int end2 = clock();

	cout << "�������" << end1 - begin1 << endl;
	cout << "��ϣ��" << end2 - begin2 << endl;
}

void testMyUnordered_set()
{
	close::myunordered_set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
}

int main()
{
	
	//testSpeed();

	testMyUnordered_set();
	
	system("pause");
	return 0;
}
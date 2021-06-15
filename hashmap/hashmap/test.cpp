#include "hashtable.hpp"
#include "mayunordered_map.h"
#include "myunordered_set.h"

void testSpeed()
{
	srand((unsigned)time(nullptr));
	int n = 10000000;
	set<int> rbset;
	unordered_set<int> hashset;


	int begin1 = clock();  // clock()是进程启动到执行到这块所用的时间
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

	cout << "红黑树：" << end1 - begin1 << endl;
	cout << "哈希表：" << end2 - begin2 << endl;
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
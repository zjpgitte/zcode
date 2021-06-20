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
	s.insert(3);
	s.insert(5);
	s.insert(8);

	int find = s.find(1);

	s.erase(3);

}

void testMyUnordered_map()
{
	close::myunordered_map<int, int> m;

	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(3, 1));
	m.insert(make_pair(4, 1));

	int find = m.find(3);

	m.erase(1);

	close::myunordered_map<int, int> m1;
	m.swap(m1);
}

int main()
{
	
	//testSpeed();

	//testMyUnordered_set();

	testMyUnordered_map();
	
	system("pause");
	return 0;
}
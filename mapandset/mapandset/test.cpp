#include "mymap.h"
#include "myset.h"
#include <map>
#include <set>

void testMySet()
{
	myset<int> s;
	s.insert(8);
	s.insert(9);
	s.insert(7);
	s.insert(3);
	s.insert(4);
	s.insert(6);
	s.insert(1);
	s.insert(2);

	myset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void testMyMap()
{
	mymap<string, int> m;
	m["hello"]++;
	m["hello"]++;
	m["ok"]++;
	m["hi"]++;
	m["apple"]++;
	m["apple"]++;
	m["apple"]++;
	m["apple"]++;
	m["apple"]++;
	m["banana"]++;

	for (auto& e: m)
	{
		cout  << ":" << e.second << endl;
	}
}

void testSet()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);

	set<int>::iterator it = s.find(5);
	//*it = 6;
}

void testMap()
{
	//map<string, int> m;
	/*m["hello"]++;
	m["hello"]++;
	m["ok"]++;
	m["hi"]++;
	m["apple"]++;
	m["banana"]++;

	for (auto& e: m)
	{
		cout << e.first << ":" << e.second << endl;
	}*/
}

int main()
{
	//testMySet();
	testMyMap();
	//testSet();
	//testMap();


	system("pause");
	return 0;
}
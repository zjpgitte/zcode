#include "mymap.h"
#include "myset.h"
#include <map>
#include <set>

void testMySet()
{
	myset<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(4);

	myset<int>::iterator it = s.begin();
	*it = 2;

}

void testMyMap()
{
	mymap<string, int> m;
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
	*it = 6;
}

void testMap()
{
	map<int, int> m;
	m.insert(make_pair(1, 2));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 2));
	m.insert(make_pair(4, 2));

	map<int, int>::iterator it = m.find(3);
	(*it).first = 3;
	(*it).second = 3;

}

int main()
{
	testMySet();
	testMyMap();
	//testSet();
	//testMap();


	system("pause");
	return 0;
}
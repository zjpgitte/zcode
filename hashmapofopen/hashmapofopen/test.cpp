
#include "myunordered_map.h"
#include "myunordered_set.h"
#include <string>

void testMyMap()
{
	open::unordered_map<string, int> m;

	m.insert(make_pair("hello", 1));
	m.insert(make_pair("yes", 1));
	m.insert(make_pair("ok", 1));
	m.insert(make_pair("hi", 1));
	m.insert(make_pair("hi", 1));
	m.insert(make_pair("ai", 1));
	m.insert(make_pair("bi", 1));
	m.insert(make_pair("ci", 1));
	m.insert(make_pair("di", 1));
	m.insert(make_pair("hi", 1));

	auto ret = m.find("ok");

	m.erase("hello");

	open::unordered_map<string, int>::iterator it = m.begin();

	while (it != m.end())
	{
		cout << (*it).first << ": " << (*it).second << endl;
		++it;
 	}


}

void testMySet()
{
	open::unordered_set<string> s;

	s.insert("apple");
	s.insert("origan");
	s.insert("banana");
	s.insert("juice");

	s.erase("apple");

	auto ret = s.find("apple");

	

}

int main()
{
	testMyMap();
	//testMySet();


	system("pause");
	return 0;
}
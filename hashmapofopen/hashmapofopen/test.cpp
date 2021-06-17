
#include "myunordered_map.h"
#include "myunordered_set.h"

void testMyMap()
{
	open::unordered_map<int, int> m;

	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(3, 1));

}


int main()
{
	testMyMap();


	system("pause");
	return 0;
}
#include "list.h"
#include <list>
void TestList1()
{
	zjp::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_front(1);

	l1.pop_front();
	l1.pop_front();
	l1.pop_front();

	zjp::list<int>::iterator it = l1.begin();
	it = l1.insert(it, 0);
	
	while (it != l1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestConst(const zjp::list<int>& l)
{
	//list<int>::const_iterator it = l.begin();
	//*it = 0;

	zjp::list<int>::const_iterator it = l.begin();
	//*it = 0;


	
}

void TestList2()
{
	zjp::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	TestConst(l);
}

int main()
{
	//TestList1();
	TestList2();

	system("pause");
	return 0;
}
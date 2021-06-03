#include "rbtree.hpp"

void testRbtree()
{
	RBTree<int, int> t;

	t.insert(make_pair(100, 3));
	t.insert(make_pair(50, 3));
	t.insert(make_pair(150, 3));
	t.insert(make_pair(25, 3));
	t.insert(make_pair(30, 3));
	t.insert(make_pair(200, 3));
	t.insert(make_pair(175, 3));

	cout << t.isBalance() << endl;
	

}

int main()
{
	testRbtree();

	system("pause");
	return 0;
}
#include "AvlTree.h"

class Fun
{
public:
	int operator ()(int a, int b)
	{
		return a + b;
	}
};

void testFunc()
{
	Fun f;
	cout << f(1, 2) << endl;
}

void testAVLTree()
{
	//AVLTreeNode<int, int> t;
	AVLTree<int, int> t;
	t.insert(pair<int, int>(60, 3));
	t.insert(pair<int, int>(30, 3));
	t.insert(pair<int, int>(70, 3));
	t.insert(pair<int, int>(40, 3));
	t.insert(pair<int, int>(50, 3));
	t.insert(pair<int, int>(55, 3));

	t.inorder();
	cout << t.isBalanced() << endl;

}


int main()
{
	//testFunc();

	testAVLTree();

	system("pause");
	return 0;
}
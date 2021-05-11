#include "bstree.h"

using namespace std;

int main()
{
    BSTree<int> b;

    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(1);
    b.insert(4);
    b.insert(6);
    b.insert(8);
    b.insert(0);
    b.insert(3);
    b.insert(9);
    
    BSTree<int>::iterator ret = b.find(10);
    if(ret == nullptr)
    {
        cout << "没找到" << endl;
    }

    b.inorder();

    b.erase(6);
    b.inorder();
    b.erase(8);
    b.inorder();
    b.erase(5);
    b.inorder();
    b.erase(1);
    b.inorder();


    return 0;
}

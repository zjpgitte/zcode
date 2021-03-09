#include "queue.h"
#include "btree.h"


int main()
{
    char a[] = "ABD##E##C##";
    int i = 0;
    BTNode *root = BinaryTreeCreat(a, &i);

    BinaryTreeLevelTravel(root);
    cout << endl;
    PreOrder(root); 
    cout << endl;

    return 0;
}

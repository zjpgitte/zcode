#include "queue.h"
#include "btree.h"

BTNode *BinaryTreeCreat(BTDateType *a, int *i)
{
    if(a[*i] == '#')
    {
        (*i)++;
        return NULL;
    }

    //创建结点
    BTNode *newNode = (BTNode*)malloc(sizeof(BTNode));
    newNode->_val = a[(*i)++];
    newNode->_left = BinaryTreeCreat(a, i);
    newNode->_right = BinaryTreeCreat(a, i);
    
    return newNode;
}


//层序遍历
void BinaryTreeLevelTravel(BTNode *root)
{
   Queue q;
   QueueInit(&q);
   QueuePush(&q, root);
   while(!QueueEmpty(&q))
   {
       BTNode *parent = QueueHead(&q);
       //访问双亲节点
       printf("%c ",parent->_val);

       //孩子结点入队
       if(parent->_left)
       {
           QueuePush(&q, parent->_left);
       }
       if(parent->_right)
       {
           QueuePush(&q, parent->_right);
       }
       
       //双亲结点出队
       QueuePop(&q);
    
   }

}

//先序遍历
void PreOrder(BTNode *root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%c",root->_val);
    PreOrder(root->_left);
    PreOrder(root->_right);
}

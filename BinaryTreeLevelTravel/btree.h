#pragma once 

typedef char BTDateType;

typedef struct BTNode
{
    BTDateType _val;
    struct BTNode* _left;
    struct BTNode* _right;
}BTNode;

//建二叉树
BTNode* BinaryTreeCreat(BTDateType *a, int *i);

//层序遍历
void BinaryTreeLevelTravel(BTNode *root);

//先序遍历
void PreOrder(BTNode *root);


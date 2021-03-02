#include "SeqList.h"

void SeqListInit(SeqList *L)
{
    L->_capacity = 4;
    L->_size = 0;
    L->_a = (SLDateType*)malloc(sizeof(int)*L->_capacity);
}



void CheckSeqListCapacity(SeqList *L)
{
    assert(L);
    if(L->_size >= L->_capacity)
    {
        L->_capacity *= 2;
        SLDateType *temp;
        temp = (SLDateType*)realloc(L->_a, sizeof(SLDateType)*L->_capacity);
        if(temp == NULL)
        {
            printf("realloc error!\n");
            exit(0);
        }
        L->_a = temp;
    }
}

//头插
void SeqListPushFront(SeqList *L, SLDateType x)
{
    SeqListPushMid(L, x, 0);
}
//尾插
void SeqListPushTail(SeqList *L, SLDateType x)
{
    SeqListPushMid(L, x, L->_size);
}
//中间插入
void SeqListPushMid(SeqList *L, SLDateType x, int pos)
{
    assert(L);
    //判断插入位置是否合法
    if(pos < 0 || pos > L->_size)
    {
        printf("Insert pos is not legal!\n");
        return;
    }

    CheckSeqListCapacity(L);
    
    //pos+1 之后的元素向后移动一位
    for(int i = L->_size - 1; i >= pos; i--)
    {
        L->_a[i+1] = L->_a[i];
    }

    L->_a[pos] = x;
    L->_size++;
}

//头删
void SeqListPopFront(SeqList *L)
{
    SeqListPopMid(L, 0);
}
//尾删
void SeqListPopTail(SeqList *L)
{
    SeqListPopMid(L, L->_size - 1);
}
//中间删除
void SeqListPopMid(SeqList *L, int pos)
{
    assert(L);
    //判断删除位置是否合法
    if(pos < 0 || pos >= L->_size)
    {
        printf("Delect pos error!\n");
        return;
    }
    //把pos+1到结尾处的元素向前挪一位
    for(int i = pos+1; i < L->_size; i++)
    {
        L->_a[i-1] = L->_a[i];
    }

    L->_size--;
}

//修改
void SeqListModify(SeqList *L, SLDateType x, int pos)
{
    assert(L);

    //判断pos是否合法
    if(pos < 0 || pos >= L->_size)
    {
        printf("Modify pos is not legal!\n");
        return;
    }
    
    L->_a[pos] = x;

}

//打印
void SeqListPrint(SeqList *L)
{
    assert(L);
    for(int i = 0; i < L->_size; i++)
    {
        printf("%d ",L->_a[i]);
    }
    printf("\n");
}

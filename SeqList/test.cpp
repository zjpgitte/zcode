#include "SeqList.h"

int main()
{

    SeqList L;
    SeqListInit(&L);
    SeqListPushMid(&L, 1, 0);
    SeqListPushFront(&L, 0);
    SeqListPushTail(&L, 2);
    SeqListPushTail(&L, 5);
    SeqListPushFront(&L, -1);
    SeqListPopMid(&L, 0);
    SeqListPopFront(&L);
    SeqListPopTail(&L);
    SeqListPopMid(&L, -1);
    SeqListPopMid(&L, 6);
    SeqListModify(&L, 5, 0);
    SeqListPrint(&L);
    return 0;
}

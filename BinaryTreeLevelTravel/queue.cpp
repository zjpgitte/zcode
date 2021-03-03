#include "queue.h"

void Print(Queue *pq)
{
    QueueNode *cur = pq->_head;
    while(cur)
    {
        printf("%d ",cur->_val);
        cur = cur->_next;
    }
    printf("\n");
}

//初始化
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->_head = NULL;
    pq->_tail = NULL;
}

//入队
void QueuePush(Queue *pq, QDateType x)
{
    assert(pq);
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(newNode == NULL)
    {
        printf("malloc error!\n");
        exit(0);
    }
    newNode->_next = NULL;
    newNode->_val = x;
    if(pq->_head == NULL)
    {
        pq->_head = newNode;
        pq->_tail = newNode;
    }
    else 
    {
        pq->_tail->_next = newNode;
        pq->_tail = newNode;
    }
}

//出队
void QueuePop(Queue *pq)
{
    assert(pq);
    if(QueueEmpty(pq))
    {
        return ;
    }
    QueueNode *del = pq->_head;
    pq->_head = pq->_head->_next;
    free(del);
}

//取队头
QDateType QueueHead(Queue* pq)
{
    return pq->_head->_val;
}

//判队空
bool QueueEmpty(Queue *pq)
{
    assert(pq);
    return !pq->_head;
}

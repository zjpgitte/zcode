#include <iostream>
#include <assert.h>
using namespace std;

typedef int QDateType;
typedef struct QueueNode
{
    QDateType _val;
    struct QueueNode *_next;
}QueueNode;

typedef struct Queue 
{
    QueueNode *_head;
    QueueNode *_tail;
}Queue;

void Print(Queue *pq);
//初始化
void QueueInit(Queue *pq);

//入队
void QueuePush(Queue *pq, QDateType x);

//出队
void QueuePop(Queue *pq);

//取队头
QDateType QueueHead(Queue* pq);

//判队空
bool QueueEmpty(Queue *pq);

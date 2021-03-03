#include "queue.h"

int main()
{
    
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 5);
    QueuePop(&q);
    QueuePop(&q);
    Print(&q);
    printf("%d ",QueueHead(&q));
    return 0;
}

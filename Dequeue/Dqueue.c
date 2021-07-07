// !线性表实现一个Dqueue
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10

typedef int DqType;

typedef struct
{
    DqType data[MaxSize];
    int front;
    int rear;
    size_t size;
} SqQueue;

void SqQueueInit(SqQueue *q)
{
    q->front = q->rear = q->size = 0;
    for (size_t i = 0; i < MaxSize; i++)
    {
        q->data[i] = 0;
    }
}

bool SqQueueEmpty(SqQueue *q)
{
    return q->front == q->rear ? true : false;
}

bool EnQueue(SqQueue *q, DqType data)
{
    if (q->size == MaxSize)
    {
        return false;
    }
    q->data[q->rear++] = data;
    q->size++;
    return true;
}

bool DeQueue(SqQueue *q, DqType *data)
{
    if (SqQueueEmpty(q))
    {
        return false;
    }
    *data = q->data[q->front++];
    q->size--;
    return true;
}
void PrintSqQueue(SqQueue *s)
{
    for (size_t i = 0; i < MaxSize; i++)
    {
        printf("%d  ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    SqQueue q;
    SqQueueInit(&q);

    // printf("%d ", SqQueueEmpty(&q));

    EnQueue(&q, 2);
    EnQueue(&q, 7);
    EnQueue(&q, 5);
    EnQueue(&q, 6);
    printf("size:%d\n", q.size);

    DqType x;
    DqType y;
    DeQueue(&q, &x);
    DeQueue(&q, &y);
    PrintSqQueue(&q);
    printf("size:%d\n", q.size);

    printf("%d \n", x);
    printf("%d \n", y);
}
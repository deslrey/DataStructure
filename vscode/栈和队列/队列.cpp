#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

typedef struct
{
    DateType data[MAXSIZE];
    int front, rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &q)
{
    q.front = q.rear = 0;
}

// 入队
bool EnQueue(SqQueue &q, DateType e)
{
    if ((q.rear + 1) % MAXSIZE == q.front) //  判断当前队列是否已满
    {
        printf("当前队列已满,插入失败\n");
        return false;
    }
    q.data[q.rear] = e;
    q.rear = (q.rear + 1) % MAXSIZE;
    printf("插入成功\n");
    return true;
}

// 出队
bool DeQueue(SqQueue &q, DateType &e)
{
    if (q.front == q.rear)
    {
        printf("当前队列为空\n");
        return false;
    }
    e = q.data[q.front];
    q.front = (q.front + 1) % MAXSIZE;
    printf("出队成功\n");
    return true;
}

// 获取队头元素
bool GetHead(SqQueue &q, DateType &e)
{
    if (q.front == q.rear)
    {
        printf("当前队列为空\n");
        return false;
    }
    e = q.data[q.front];
    return true;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue q)
{
    return q.front == q.rear;
}

int main()
{

    return 0;
}
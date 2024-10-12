#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

typedef struct LinkNode
{
    DateType data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = NULL;
    printf("初始化成功\n");
}

// 入队
bool EnQueue(LinkQueue &q, DateType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
    {
        printf("内存不足,插入失败\n");
        return false;
    }
    s->data = e;
    s->next = NULL;
    if (q.front == NULL)
    {
        q.front = s;
        q.rear = s;
    }
    else
    {
        q.rear->next = s;
        q.rear = s;
    }
    printf("插入成功\n");
    return true;
}

bool DeQueue(LinkQueue &q, DateType &e)
{
    if (QueueEmpty(q))
    {
        printf("当前队列为空\n");
        return false;
    }
    LinkNode *s = q.front; //  s指向此次出队的节点
    e = s->data;
    q.front = s->next; //  修改 front 指针
    if (q.rear == s)   //  此次是最后一个节点出队
    {
        q.front = NULL; //  front 指向 NULL
        q.rear = NULL;  //  rear 指向 NULL
    }
    free(s);
    printf("出队成功\n");
    return true;
}

// 判空队列
bool QueueEmpty(LinkQueue q)
{
    return q.front == NULL;
}

int main()
{

    return 0;
}
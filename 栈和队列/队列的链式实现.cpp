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

// 初始化队列(带头节点)
bool InitQueue(LinkQueue &q)
{
    q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    if (q.front == NULL || q.rear == NULL)
    {
        printf("内存不足,初始化失败\n");
        return false;
    }
    q.front->next = NULL;
    printf("初始化成功\n");
    return true;
}

// 新元素入队(带头节点)
bool EnQueueHead(LinkQueue &q, DateType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
    {
        printf("内存不足,插入失败\n");
        return false;
    }
    s->data = e;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
    printf("插入成功\n");
    return true;
}

//  队头元素出队
bool DeQueue(LinkQueue &q, DateType &e)
{
    if (q.front == q.rear)
    {
        printf("当前队列为空,删除失败\n");
        return false;
    }
    LinkNode *s = q.front->next;
    e = s->data;
    q.front->next = s->next;        //  修改头节点的 next 指针
    if (q.rear == s)                //  此次是最后一个节点出队
    {
        q.rear = q.front;           //  修改 rear 指针
    }
    free(s);
    printf("出队成功\n");
    return true;
}

int main()
{

    return 0;
}
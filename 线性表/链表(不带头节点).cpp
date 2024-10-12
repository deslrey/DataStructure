#include "stdio.h"
#include "stdlib.h"

typedef int dataType;

typedef struct LNode
{
    dataType data;      // 每一个节点存放数据
    struct LNode *next; //  指向下一个节点的指针
} *LinkList;

// 初始化,不携带头节点
bool InitList(LinkList &L)
{
    return L == NULL;
}

bool LinkInsert(LinkList &L, int i, dataType e)
{
    if (i < 1)
    {
        printf("插入元素的下标不能小于1");
        return false;
    }
    LNode *s;
    if (i == 1)
    {
        s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL)
        {
            printf("内存不足,分配失败\n");
            return false;
        }
        s->data = e;
        s->next = L;
        L = s;
        printf("插入成功");
        return true;
    }
    LNode *p = L;
    int index = 1;
    while (p != NULL && index < i - 1)
    {
        p = p->next;
        index++;
    }
    if (p == NULL)
    {
        printf("插入数据的下标非法\n");
        return false;
    }

    s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("插入成功");
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList &L)
{
    return L == NULL;
}

int main()
{

    return 0;
}
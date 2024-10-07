#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct DNode
{
    dataType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化一个循环双链表
bool InitList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        printf("内存不足,分配失败\n");
        return false;
    }
    L->prior = L;
    L->next = L;
    printf("初始化成功\n");
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinkList &L)
{
    if (L == NULL)
    {
        printf("传入的循环单链表为NULL\n");
        return true;
    }
    if (L->next == L)
    {
        printf("传入的循环单链表为空\n");
        return true;
    }
    printf("传入的循环单链表不为空\n");
    return false;
}

// 在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;
    printf("插入成功\n");
    return true;
}

// 删除p的后继节点p
bool DeleteDNode(DNode *p, DNode *q)
{
    p->next = q->next;
    q->next->prior = p;
    printf("删除成功\n");
    return true;
}

//  判断节点p是否为循环双链表的表尾节点
bool isTail(DLinkList &L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}
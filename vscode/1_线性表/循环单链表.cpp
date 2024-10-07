#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct LNode
{
    dataType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个循环单链表

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("内存不足,分配失败\n");
        return false;
    }
    L->next = L;
    printf("初始化成功\n");
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList &L)
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

//  判断节点p是否为循环单链表的表尾节点
bool isTail(LinkList &L, LNode *p)
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
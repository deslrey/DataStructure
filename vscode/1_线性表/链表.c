#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("内存空间分配失败,内存不足");
    }
    L->next = NULL;
}
// 根据下标插入数据(携带头节点)
void InsterList(LinkList L, int index, ElemType value)
{
    if (index < 1)
    {
        printf("插入的下标不合法,不能小于1");
        return;
    }
    int currentIndex = 0;
    LNode *p;
    p = L;
    if (p != NULL && currentIndex < index - 1)
    {
        p = p->next;
        currentIndex++;
    }
    if (p == NULL)
    {
        printf("插入的下标不合法");
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    printf("数据插入完成");
}

// 根据下标插入数据(不携带头节点)
void InsterNoHeadList(LinkList L, int index, ElemType value)
{
    if (index < 1)
    {
        printf("插入的下标不合法,不能小于1");
        return;
    }

    if (index == 1)
    {
        LNode *t = (LNode *)malloc(sizeof(LNode));
        if (t == NULL)
        {
            printf("内存空间分配失败,内存不足");
            return;
        }
        t->data = value;
        t->next = L;
        L = t;
        return;
    }

    int currentIndex = 1;
    LNode *p;
    p = L;
    if (p != NULL && currentIndex < index - 1)
    {
        p = p->next;
        currentIndex++;
    }
    if (p == NULL)
    {
        printf("插入的下标不合法");
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    printf("数据插入完成");
}

// 后插操作: 在node节点之后插入元素 value
void InsterNextNode(LNode *node, ElemType value)
{
    if (node == NULL)
    {
        printf("插入节点为NULL,插入失败");
        return;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("内存空间分配失败,内存不足");
        return;
    }

    s->data = value;
    s->next = node->next;
    node->next = s;
    printf("数据插入完成");
}

// 前插操作: 在node节点之前插入元素 value
void InsertPriorNode(LNode *node, ElemType value)
{
    if (node == NULL)
    {
        printf("插入节点为NULL,插入失败");
        return;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("内存空间分配失败,内存不足");
        return;
    }

    s->next = node->next;
    node->next = s;
    s->data = node->data;
    node->data = value;
}

int main()
{

    LinkList L;
    InitList(L);

    return 0;
}
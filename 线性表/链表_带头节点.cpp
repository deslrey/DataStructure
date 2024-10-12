#include "stdio.h"
#include "stdlib.h"

typedef int dataType;

typedef struct LNode
{
    dataType data;      // 每一个节点存放数据
    struct LNode *next; //  指向下一个节点的指针
} *LinkList;

// 初始化,携带头节点
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("分配失败,内存不足\n");
        return false;
    }
    L->next = NULL;
    return true;
}

LNode *InitNode()
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("分配失败,内存不足\n");
        return NULL;
    }
    return s;
}

// 在第 i 个位置插入元素 e
bool ListInsert(LinkList &L, int i, dataType e)
{
    if (i < 1)
    {
        printf("插入元素的下标不能小于1\n");
        return false;
    }
    LNode *p = L;
    int index = 0;
    while (p != NULL && index < i - 1)
    {
        p = p->next;
        index++;
    }
    if (p == NULL)
    {
        printf("插入元素的下标非法\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("内存不足,分配失败\n");
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 后插操作: 在p节点之后插入元素e
bool InsertNextNode(LNode *p, dataType e)
{
    if (p == NULL)
    {
        printf("传入节点为NULL\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("内存不足,分配失败\n");
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("插入成功\n");
    return true;
}

// 前插操作: 在p节点之前插入元素e
bool InsertPriorNode(LNode *p, dataType e)
{
    if (p == NULL)
    {
        printf("传入节点为NULL\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("内存不足,分配失败\n");
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    printf("插入成功\n");
    return true;
}

// 按位序删除
bool ListDelete(LinkList &L, int i, dataType &e)
{
    if (i < 1)
    {
        printf("插入元素的下标不能小于1\n");
        return false;
    }
    LNode *p = L;
    int index = 0;
    while (p != NULL && index < i - 1)
    {
        p = p->next;
        index++;
    }
    if (p == NULL || p->next == NULL)
    {
        printf("插入元素的下标非法\n");
        return false;
    }

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    printf("删除成功\n");
    return true;
}

// 删除指定节点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        printf("传入节点为NULL\n");
        return false;
    }
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    printf("删除成功\n");
    return true;
}

// 按位查找节点,返回第i个元素
LNode *getElem(LinkList &L, int i)
{
    if (L == NULL)
    {
        printf("传入节点为NULL\n");
        return NULL;
    }
    int index = 0;
    LNode *p = L;
    while (p != NULL && index < i)
    {
        p = p->next;
        index++;
    }

    if (p == NULL)
    {
        printf("查找的下标非法\n");
        return NULL;
    }

    printf("查找成功\n");
    return p;
}

LNode *LocateElem(LinkList &L, dataType e)
{
    if (L == NULL)
    {
        printf("传入节点为NULL\n");
        return NULL;
    }
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("当前链表中未查找到该数据\n");
        return NULL;
    }
    printf("查找成功\n");
    return p;
}

// 求表的长度
int Lenfth(LinkList &L)
{
    if (L == NULL)
    {
        return 0;
    }
    int count = 0;
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 尾插法建立单链表
LinkList ListTaillensert(LinkList &L)
{
    int x;
    bool result = InitList(L);
    if (!result)
    {
        printf("创建失败\n");
        return NULL;
    }

    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LinkList ListHeadInsert(LinkList &L)
{
    bool result = InitList(L);
    if (!result)
    {
        printf("创建失败\n");
        return NULL;
    }

    LNode *s;
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = InitNode();
        if (s == NULL)
        {
            break;
        }
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

void PrintList(LinkList &L)
{
    if (L == NULL)
    {
        printf("当前链表未空\n");
    }
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        printf("%d\t", p->data);
    }
}

// 判断单链表是否为空
bool Empty(LinkList &L)
{
    return L->next == NULL;
}

int main()
{
    // 初始化链表
    LinkList L;
    InitList(L);
    InsertNextNode(L, 1);
    PrintList(L);

    return 0;
}
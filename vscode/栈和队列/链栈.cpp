#include <stdio.h>
#include <stdlib.h>

typedef int DateType;

typedef struct SNode
{
    DateType data;
    struct SNode *next;
} SNode, *LinkStack;

// 初始化链栈
bool InitLinkStack(LinkStack &s)
{
    s == (SNode *)malloc(sizeof(SNode));
    if (s == NULL)
    {
        printf("初始化失败,内存不足\n");
        return false;
    }
    s->next == NULL;
    printf("初始化成功\n");
    return true;
}

// 入栈操作
bool PushStack(LinkStack &s, DateType e)
{
    if (s == NULL)
    {
        printf("当前链栈为NULL,插入失败\n");
        return false;
    }
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if (p == NULL)
    {
        printf("内存不足,插入失败\n");
        return false;
    }
    p->data = e;
    p->next = s->next;
    s->next = p;
    printf("插入成功");
    return true;
}

// 出栈操作
bool PopStack(LinkStack &s, DateType &e)
{
    if (s == NULL)
    {
        printf("当前链栈为NULL,插入失败\n");
        return false;
    }
    SNode *p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    printf("删除成功\n");
    return true;
}

// 获取栈顶元素
bool GetTop(LinkStack &s, DateType &e)
{
    if (s == NULL)
    {
        printf("当前链栈为NULL,获取失败\n");
        return false;
    }
    e = s->next->data;
    printf("获取成功\n");
    return true;
}

// 判断链栈是否为空
bool Empty(LinkStack s)
{
    return s->next == NULL;
}

int main()
{

    return 0;
}
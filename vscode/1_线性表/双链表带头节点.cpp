#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct DNode
{
    dataType data;
    struct DNode *prior, *next;
} DNode, *DlinkList;

bool InitDLinkList(DlinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        printf("创建失败,内存不足\n");
        return false;
    }

    L->prior = NULL;
    L->next = NULL;
    printf("创建成功\n");
    return true;
}

// 在p节点之后插入s节点
bool InsterNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        printf("传入的节点数据存在NULL\n");
        return false;
    }
    s->next = p->next;
    if (p->next != NULL)
    { //   如果p节点之后存在后继节点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    printf("插入成功\n");
    return true;
}

bool Empty(DlinkList L)
{
    return L->next == NULL;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}

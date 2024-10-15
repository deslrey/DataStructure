#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

struct ElemType
{
    DateType value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 链式队列节点
typedef struct LinkNode
{
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear; //  队头队尾
} LinkQueue;

// 初始化链树
bool InitTree(BiTree &tree)
{
    tree->data = {0};
    tree->lchild = NULL;
    tree->rchild = NULL;
    printf("初始化成功\n");
    return true;
}

// 初始化队列
bool InitQueue(LinkQueue &q)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL)
    {
        printf("内存不足,初始化失败\n");
        return false;
    }
    q.front->data = NULL;
    q.rear->data = NULL;
    q.front = q.rear = p;
    q.front->next = NULL;
    printf("初始化成功\n");
    return true;
}

// 入队
bool EnQueue(LinkQueue &q, BiTree T)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
    {
        printf("内存不足,插入失败\n");
        return false;
    }
    s->data = T;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
    printf("插入成功\n");
    return true;
}

// 出队
bool DeQueue(LinkQueue &q, BiTree &T)
{
    if (q.rear == q.front)
    {
        printf("当前队列为空,出队失败\n");
        return false;
    }
    LinkNode *s = q.front->next;
    T = s->data;
    q.front->next = s->next;
    if (q.rear == s)
    {
        q.rear = q.front;
    }
    free(s);
    printf("出队成功\n");
    return true;
}

// 判断是否为空队列
bool IsEmpty(LinkQueue q)
{
    return q.front == q.rear;
}

// 插入数据
bool InsertTreeNode(BiTree &tree, DateType e)
{
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    if (p == NULL)
    {
        printf("内存不足,插入失败\n");
        return false;
    }
    p->data = {e};
    p->lchild = NULL;
    p->rchild = NULL;
    tree->lchild = p;
}

// 先序访问树节点数据
void PreOrder(BiTree L)
{
    if (L != NULL)
    {
        visit(L);
        PreOrder(L->lchild);
        PreOrder(L->rchild);
    }
}
// 中序访问树节点数据
void MidOrder(BiTree L)
{
    if (L != NULL)
    {
        MidOrder(L->lchild);
        visit(L);
        MidOrder(L->rchild);
    }
}
// 后序访问树节点数据
void PosOrder(BiTree L)
{
    if (L != NULL)
    {
        PosOrder(L->lchild);
        PosOrder(L->rchild);
        visit(L);
    }
}

// 求树的深度
int treeDepth(BiTree L)
{
    if (L == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(L->lchild);
        int r = treeDepth(L->rchild);
        return l > r ? l + 1 : r + 1;
    }
}

// 层序遍历
void LevelOrder(BiTree T)
{
    // 定义队列并初始化
    LinkQueue Q;
    InitQueue(Q);
    // 定义当前遍历节点
    BiTree T;
    // 将当前节点入队
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, T);
        visit(T);
        if (T->lchild != NULL)
            EnQueue(Q, T->lchild);
        if (T->rchild != NULL)
            EnQueue(Q, T->rchild);
    }
}

void visit(BiTree L)
{
    printf("%d\t", L->data.value);
}
int main()
{

    return 0;
}
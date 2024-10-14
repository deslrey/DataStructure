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

// 初始化链树
bool InitTree(BiTree &tree)
{
    tree->data = {0};
    tree->lchild = NULL;
    tree->rchild = NULL;
    printf("初始化成功\n");
    return true;
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

int main()
{

    return 0;
}
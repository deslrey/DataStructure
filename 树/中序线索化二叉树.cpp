#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

// 线索二叉树节点
typedef struct ThreadNode
{
    DateType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; //  左右线索标志
} ThreadNode, *ThreadTree;

// 全局变量 pre, 指向当前访问节点的前驱
ThreadNode *pre = NULL;

// 中序线索化二叉树
void CreateInThread(ThreadTree T)
{
    pre = NULL; //  初始化 pre 为NULL
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
        {
            pre->rtag = 1; //  处理遍历的最后一个节点
        }
    }
}

void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}
void visit(ThreadNode *q)
{
    if (q->lchild == NULL) //  左子树为空,建立前驱线索
    {
        q->lchild = pre;
        q->ltag = 1;
    }

    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; //  建立前驱节点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

// 找到以p为根的子树中,第一个被中序遍历的节点
ThreadNode *FirstNode(ThreadNode *p)
{
    // 循环找到最左下节点(不一定是叶节点)
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

// 在中序线索二叉树中找到节点p的后继节点
ThreadNode *NextNode(ThreadNode *p)
{
    // 右子树最左下节点
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

// 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
    {
        visit(p);
    }
}

// 找到以p为根的子树中,最后一个被中序遍历的节点
ThreadNode *LastNode(ThreadNode *p)
{
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

// 在中序线索二叉树中找到节点p的前驱节点
ThreadNode *PreNode(ThreadNode *p)
{
    // 左子树最右下节点
    if (p->rtag == 0)
        return LastNode(p);
    else
        return p->rchild;
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
    {
        visit(p);
    }
}

int main()
{

    return 0;
}
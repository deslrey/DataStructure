#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

typedef struct SqStack
{
    DateType data[MAXSIZE];
    int index;
} SqStack;

// 初始化栈
void InitStack(SqStack &s)
{
    s.index = -1;
}

// 入栈操作
bool Push(SqStack &s, DateType e)
{
    if (s.index == MAXSIZE - 1)
    {
        printf("当前栈以满,插入失败\n");
        return false;
    }
    s.index++;
    s.data[s.index] = e;
    printf("插入成功\n");
    return true;
}

// 出栈操作
bool Pop(SqStack &s, DateType &e)
{
    if (s.index == -1)
    {
        printf("当前栈为空\n");
        return false;
    }
    e = s.data[s.index];
    s.index--;
    printf("删除成功\n");
    return true;
}

// 获取栈顶数据
bool GetTop(SqStack s, DateType &e)
{
    if (s.index == -1)
    {
        printf("当前栈为空\n");
        return false;
    }
    e = s.data[s.index];
    printf("获取成功\n");
    return true;
}

// 判断是否为空栈
bool EmptyStack(SqStack s)
{
    return s.index == -1;
}

int main()
{

    return 0;
}
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

// 判断是否为空栈
bool EmptyStack(SqStack s)
{
    return s.index == -1;
}

int main()
{

    return 0;
}
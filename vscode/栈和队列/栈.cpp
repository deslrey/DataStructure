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

// 判断是否为空栈
bool EmptyStack(SqStack s)
{
    return s.index == -1;
}

int main()
{

    return 0;
}
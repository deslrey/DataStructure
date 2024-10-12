#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DateType;

typedef struct
{
    DateType data[MAXSIZE];
    int front; //  栈头
    int rear;  //  栈尾
} ShStack;

bool StackFull(ShStack s);

void InitStack(ShStack &s)
{
    s.front = -1;
    s.rear = MAXSIZE;
}

// 从栈头插入
bool PushFront(ShStack &s, DateType e)
{
    if (StackFull(s))
    {
        printf("当前栈已满,无法插入\n");
        return false;
    }
    s.data[++s.front] = e;
    printf("插入成功");
    return true;
}

// 从栈头插入
bool PushRear(ShStack &s, DateType e)
{
    if (StackFull(s))
    {
        printf("当前栈已满,无法插入\n");
        return false;
    }
    s.data[--s.rear] = e;
    printf("插入成功");
    return true;
}

// 从栈头删除元素
bool PopFront(ShStack &s, DateType &e)
{
    if (s.front == -1)
    {
        printf("栈头为空\n");
        return false;
    }
    e = s.data[s.front];
    s.front--;
    printf("删除成功\n");
    return true;
}

// 从栈尾删除元素
bool PopRear(ShStack &s, DateType &e)
{
    if (s.rear == MAXSIZE)
    {
        printf("栈尾为空\n");
        return false;
    }
    e = s.data[s.rear];
    s.rear++;
    printf("删除成功\n");
    return true;
}

// 获取栈头元素
bool GetFront(ShStack s, DateType &e)
{
    if (s.front == -1)
    {
        printf("栈头为空\n");
        return false;
    }
    e = s.data[s.front];
    printf("获取成功\n");
    return true;
}

// 获取栈尾元素
bool GetRear(ShStack s, DateType &e)
{
    if (s.rear == MAXSIZE)
    {
        printf("栈尾为空\n");
        return false;
    }
    e = s.data[s.rear];
    printf("获取成功\n");
    return true;
}


// 判断栈是否以满
bool StackFull(ShStack s)
{
    return s.front + 1 == s.rear;
}

// 判断栈是否为空
bool EmptyStack(ShStack s)
{
    return (s.front == -1 && s.rear == MAXSIZE);
}

int main()
{

    return 0;
}
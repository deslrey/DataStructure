#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define InitMaxSize 10

typedef struct
{
    int *data;
    int MaxSize;
    int len;
} SeqList;

void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitMaxSize * sizeof(int));
    L.MaxSize = InitMaxSize;
    L.len = 0;
}

void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.len; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

void InsertList(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.len + 1)
    {
        cout << "插入下表有误,插入的下标为 : " + i << endl;
        return;
    }
    if (L.len >= L.MaxSize)
    {
        cout << "插入失败,当前顺序表数据已满" << endl;
        return;
    }
    for (int j = L.len; j > i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i] = e;
    L.len++;
}

int main()
{
    SeqList L;
    InitList(L);
    InsertList(L, 1, 10);
    printf("p的值是 ------> %d\n", L.len);
    for (int i = 0; i < L.len; i++)
    {
        printf("%d", L.data[i]);
    }

    printf("\n%d\n", L.MaxSize);

    IncreaseSize(L, 10);
    printf("%d\n", L.MaxSize);

    return 0;
}
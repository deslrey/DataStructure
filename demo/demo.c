#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define InitMaxSize 10

typedef struct
{
    ElemType *data;
    int length;
    int MaxLength;
} SeqList;

void InitList(SeqList *L)
{
    L->data = (ElemType *)malloc(InitMaxSize * sizeof(ElemType));
    L->length = 0;
    L->MaxLength = InitMaxSize;
}
// 扩容
void IncreaseSize(SeqList *L, int length)
{
    int *p = L->data;
    L->data = (ElemType *)malloc(InitMaxSize * sizeof(L->MaxLength + length));

    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxLength = L->MaxLength + length;
    free(p);
}

// 插入数据
void InsterList(SeqList *L, int index, int value)
{
    if (index < 1 || index > L->length + 1)
    {
        printf("插入数据下标异常,请检查\n");
        return;
    }
    if (L->length > L->MaxLength)
    {
        printf("当前表中数据已满,自动扩容\n");
        IncreaseSize(L, InitMaxSize);
    }

    for (int i = L->length; i >= index; i--)
    {
        L->data[i] = L->data[i - 1];
    }
    L->data[index - 1] = value;
    L->length++;
}

// 根据下标获取数据
int GetElem(SeqList *L, int index)
{
    if (index < 1 || index > L->length + 1)
    {
        printf("下标异常,查询下标为 : %d,当前顺序表最大下标为 : \n", index, L->length);
        return -1;
    }
    return L->data[index - 1];
}

// 根据值来获取下标
int LocateElement(SeqList *L, int value)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == value)
        {
            return i + 1;
        }
    }
    return -1;
}

// 打印
void PrintList(SeqList *L)
{
    for (int i = 0; i < L->length; ++i)
    {
        printf("%d\t", L->data[i]);
    }
    printf("\n");
}

// 释放内存
void FreeData(SeqList *L)
{
    if (L->data != NULL)
    {
        free(L->data);
    }
}

int main()
{
    SeqList L;
    InitList(&L);

    InsterList(&L, 1, 10);
    InsterList(&L, 2, 20);
    InsterList(&L, 3, 30);
    InsterList(&L, 4, 40);

    int value = GetElem(&L, 1);
    printf("value = %d\n", value);
    value = LocateElement(&L, 20);
    printf("value = %d\n", value);

    PrintList(&L);

    FreeData(&L);

    return 0;
}
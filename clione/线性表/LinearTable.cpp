//
// Created by 肖鑫欢 on 2024-09-17.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define InitMaxSize 10

typedef struct {
    int *data;
    int MaxSize;
    int len;
} SeqList;

void InitList(SeqList &L) {
    L.data = (int *) malloc(InitMaxSize * sizeof(int));
    L.MaxSize = InitMaxSize;
    L.len = 0;
}

void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.len; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

void InsertList(SeqList &L, int i, int e) {
    if (i < 1 || i > L.len + 1) {
        cout << "插入下标有误, 插入的下标为: " << i << endl;  // 正确输出下标
        return;
    }
    if (L.len >= L.MaxSize) {
        cout << "插入失败, 当前顺序表数据已满" << endl;
        return;
    }
    for (int j = L.len; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.len++;
}

void PrintList(SeqList &L) {
    for (int i = 0; i < L.len; ++i) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");
}

bool DeleteList(SeqList &L, int index, int &e) {
    if (index < 1 || index > L.len)
        return false;

    e = L.data[index - 1];
    for (int i = index; i < L.len; i++) {
        L.data[i - 1] = L.data[i];
    }
    L.len--;
    return true;
}

//  按位查找
int GetElement(SeqList &L, int index) {
    if (index < 1 || index > L.len) {
        printf("查找索引下标位置不合法");
        return -1;
    }
    return L.data[index - 1];
}

//  按值查找
int LocateElement(SeqList &L, int data) {
    for (int i = 0; i < L.len; ++i) {
        if (L.data[i] == data) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    SeqList L;
    InitList(L);
    InsertList(L, 1, 10);
    InsertList(L, 2, 20);

    int e = -1;
    DeleteList(L, 1, e);

    int data = GetElement(L, 1);

    printf("%d\n", data);

    PrintList(L);

    free(L.data);

    return 0;
}

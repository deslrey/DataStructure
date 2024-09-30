//
// Created by 肖鑫欢 on 2024-09-27.
//

#include "stdio.h"
#include "stdlib.h"

typedef int dataType;

typedef struct LNode {
    dataType data;      // 每一个节点存放数据
    struct LNode *next; //  指向下一个节点的指针
} *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        printf("内存不足,分配失败\n");
        return false;
    }
    L->next = NULL;
    return true;
}

bool Empty(LinkList &L) {
    return L->next == NULL;
}

bool ListInsetr(LinkList &L, int i, dataType e) {
    if (i < 1) {
        printf("插入元素的下标不能小于1\n");
        return false;
    }
    LNode *p = L;
    int index = 0;
    while (p != NULL && index < i - 1) {
        p = p->next;
        index++;
    }
    if (p == NULL) {
        printf("插入元素的下标非法\n");
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        printf("内存不足,分配失败\n");
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
}

int main() {
    printf("Hello\n");
    return 0;
}
























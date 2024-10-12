#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 255

typedef int DateType;

typedef struct
{
    char ch[MAXSIZE];
    int length;
} SString;

// 定位操作
int Indexof(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString str;
    while (i <= n - m + 1)
    {
        SubString(str, S, i, m);
        if (StrCompare(str, T) != 0)
            i++;
        else
            return i;
    }
    return 0;
}

// 比较操作,若S > T,则返回值 > 0;若S = T,则返回值 = 0,若 S < T,则返回值 < 0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];

    return S.length - T.length;
}

// 求子串
bool SubString(SString &Sub, SString s, int pos, int len)
{
    if (pos + len > s.length)
    {
        printf("下标不符,朝找失败\n");
        return false;
    }
    for (int i = pos; i < pos + len; i++)
    {
        Sub.ch[i - pos + 1] = s.ch[i];
    }
    Sub.length = len;
    return true;
}

// 清空串
void ClearLength(SString &s)
{
    s.length == 0;
}

// 求串的长度
int StrLength(SString s)
{
    return s.length;
}

int main()
{

    return 0;
}
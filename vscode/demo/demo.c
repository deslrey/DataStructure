#include <stdio.h>

void test(int *x)
{
    *x = 1024;
    printf("%d\n", *x);
}

int main()
{

    int x = 1;
    test(&x);
    printf("%d\n", x);

    return 0;
}
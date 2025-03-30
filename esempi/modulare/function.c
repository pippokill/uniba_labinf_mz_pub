#include <stdio.h>
#ifndef MY_F_IMPL
int f(int x)
{
    static int a = 0;
    int b = 0;

    a++;
    b++;

    printf("Ciclo %d:%d\t%d\n", x, a, b);
}
#endif
#include <stdio.h>

int main()
{
    int a = 3;
    int *p;
    p = &a;
    printf("a: %d\n", a);
    printf("indirizzo di a: %X\n", &a);
    printf("p (indirizzo di a): %X\n", p);
    printf("&*p (indirizzo di a): %X\n", &*p);
}
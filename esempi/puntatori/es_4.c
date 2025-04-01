#include <stdio.h>

void scambio(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

void scambioPtr(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int x = 3, y = 5;
    scambio(x, y);
    printf("x=%d\ty=%d\n", x, y);
    scambioPtr(&x, &y);
    printf("x=%d\ty=%d\n", x, y);
}
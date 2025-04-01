#include <stdio.h>

int scambio_somma(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return *a + *b;
}

int main()
{
    int x = 5, y = 33;
    int somma = scambio_somma(&x, &y);
    printf("x=%d\ty=%d\n", x, y);
    printf("Somma=%d\n", somma);
}
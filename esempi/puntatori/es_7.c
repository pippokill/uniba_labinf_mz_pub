#include <stdio.h>

void scambio_old(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void scambio(int* v[])
{
    int t = *(*v);
    *(*v) = *(*(v+1));
    *(*(v+1)) = t;
}

int main()
{
    int x = 3, y = 5;
    printf("x=%d\ty=%d\n", x, y);
    printf("\nPRIMO SCAMBIO\n");
    scambio_old(&x, &y);
    printf("x=%d\ty=%d\n", x, y);
    printf("\nSECONDO SCAMBIO\n");
    int* array[2] = {&x, &y};
    scambio(array);
    printf("x=%d\ty=%d\n", x, y);
}
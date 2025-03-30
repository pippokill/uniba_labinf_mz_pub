#include <stdio.h>

void quadrato(int x[], int n)
{
    for (int i = 0; i < n; i++)
        x[i] = x[i] * x[i];
}

int main()
{
    int x[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
        printf("%d\t", x[i]);
    quadrato(x, 3);
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf("%d\t", x[i]);
    printf("\n");
}
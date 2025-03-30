#include <stdio.h>

void quadrato(int y)
{
    y = y * y;
    printf("Dentro: %d\n", y);
}

int main()
{
    int x = 5;
    printf("Fuori: %d\n", x);
    quadrato(x);
    printf("Fuori: %d\n", x);
}
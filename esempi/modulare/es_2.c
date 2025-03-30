#include <stdio.h>

int promosso(int voto)
{
    short int promosso = 0;
    if (voto > 17)
        promosso = 1;
    return promosso;
}

int main()
{
    int x = 0;
    puts("Inserisci voto: ");
    scanf("%d", &x);
    if (promosso(x))
        puts("Promosso");

    else
        puts("Non promosso");
}
#include <stdio.h>

int promosso(int voto, int soglia)
{
    if (voto > soglia)
        return 1;
    else
        return 0;
}

int main()
{
    int x, y = 0;
    puts("Inserisci voto ESAME: ");
    scanf("%d", &x);
    puts("Inserisci voto MATURITA': ");
    scanf("%d", &y);

    if (promosso(x, 17))
        puts("promosso");
    else
        puts("non promosso");

    if (promosso(y, 60))
        puts("promosso");
    else
        puts("non promosso");
}
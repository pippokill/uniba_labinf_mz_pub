#include <stdio.h>

int somma(int a, int b); // prototipo di funzione​

int main()
{
    int totale = 0;
    int doppioTotale = 0;

    for (int i = 0; i < 10; i++)
    {
        totale = somma(totale, i);
        doppioTotale = somma(doppioTotale, i) * 2;
        printf("Totale:%d\n", totale);
        printf("Doppio Totale:%d\n", doppioTotale);
    }
}

int somma(int a, int b)
{
    return a + b;
}
#include <stdio.h>

int main()
{
    unsigned int costo = 0;
    unsigned int totale = 0;
    unsigned int counter = 0;

    for (counter = 0; counter < 5; counter++)
    {
        printf("Inserisci il costo del prodotto: ");
        scanf("%d", &costo);
        totale = totale + costo;
    }
    printf("Il costo totale è %d euro\n", totale);
}
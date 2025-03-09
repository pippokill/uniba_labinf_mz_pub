#include <stdio.h>

int main()
{
    unsigned int costo = 0;
    unsigned int totale = 0;
    unsigned int counter = 0;

    do
    {
        printf("Inserisci il costo del prodotto: ");
        scanf("%d", &costo);
        totale = totale + costo;
        counter++;
    } while (counter < 5);
    printf("Il costo totale è %d euro\n", totale);
}
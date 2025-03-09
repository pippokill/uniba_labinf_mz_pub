#include <stdio.h>

int main()
{
    float costo = 0;
    float totale = 0;
    do
    {
        printf("Inserisci il costo del prodotto (-1 pre terminare): ");
        scanf("%f", &costo);
    } while (costo != -1 && costo < 0);
    while (costo != -1)
    {
        totale = totale + costo;
        do
        {
            printf("Inserisci il costo del prodotto (-1 pre terminare): ");
            scanf("%f", &costo);
        } while (costo != -1 && costo < 0);
    }
    printf("Totale: %.2f\n", totale);
}
#include <stdio.h>

int main()
{
    float costo = 0;
    float totale = 0;
    printf("Inserisci il costo del prodotto (-1 pre terminare): ");
    scanf("%f", &costo);
    while (costo != -1)
    {
        totale = totale + costo;
        printf("Inserisci il costo del prodotto (-1 pre terminare): ");
        scanf("%f", &costo);
    }
    printf("Totale: %.2f\n", totale);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MIN_VALUE 1
#define MAX_VALUE 100

int main()
{
    int n[SIZE];
    int i = 0;
    int seed = time(NULL);
    srand(seed);
    int somma = 0;

    // ciclo di inizializzazione
    for (i = 0; i < SIZE; i++)
    {
        n[i] = 0;
    }

    // ciclo assegnazione
    for (i = 0; i < SIZE; i++)
    {
        n[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        somma += n[i];
    }

    // ciclo di stampa
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t%d\n", i, n[i]);
    }

    printf("Somma: %d\n", somma);
}
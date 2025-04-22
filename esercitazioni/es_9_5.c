#include <stdio.h>
#include <stdlib.h>

int crea_array(int **);

void stampa(int *ptr, int size);

void inserisci(int *ptr, int size);

int somma(int *ptr, int size);

float media(int *ptr, int size);

void modifica(int *ptr, int size);

int main()
{
    int *a_ptr = NULL;
    int size = crea_array(&a_ptr);
    inserisci(a_ptr, size);
    stampa(a_ptr, size);
    printf("Somma elementi: %d\n", somma(a_ptr, size));
    printf("Media elementi: %f\n", media(a_ptr, size));
    modifica(a_ptr, size);
    stampa(a_ptr, size);
}

int crea_array(int **ptr)
{
    int size;
    printf("Quanti elementi vuoi inserire? ");
    scanf("%d", &size);
    *ptr = (int *)malloc(sizeof(int) * size);
    return size;
}

void inserisci(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Inserisci il valore %d: ", i);
        scanf("%d", ptr);
        ptr++;
    }
}

void stampa(int *ptr, int size)
{
    printf("\nArray:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", *ptr);
        ptr++;
    }
    printf("\n");
}

int somma(int *ptr, int size)
{
    int somma = 0;
    for (int i = 0; i < size; i++)
    {
        somma += *ptr;
        ptr++;
    }
    return somma;
}

float media(int *ptr, int size)
{
    float media = 0;
    for (int i = 0; i < size; i++)
    {
        media += *ptr;
        ptr++;
    }
    return media / size;
}

void modifica(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((*ptr) % 3 == 0)
        {
            (*ptr) = (*ptr) * 10;
        }
        ptr++;
    }
}
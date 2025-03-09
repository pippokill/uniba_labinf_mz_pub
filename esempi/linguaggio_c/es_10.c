#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RIGHE 10   // righe della matrice​
#define COLONNE 10 // colonne della matrice​
#define MAX 100
#define MIN 1

int main(void)
{
    int seed = time(NULL); // generazione random dei valori  ​
    srand(seed);
    int matrix[RIGHE][COLONNE] = {{0}, {0}};
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            matrix[i][j] = rand() % MAX + MIN;
        }
    }
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
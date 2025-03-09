/*
PROBLEMA 2.2
Scrivere un programma che acquisisca le calorie assunte in una settimana da un insieme di 5 individui e
ne calcoli la media (per ogni individuo e complessiva).

Requisiti: utilizzare una matrice​.asm

Input:
Matrice 5 x 7, che memorizza le calorie assunte dagli individui​

Output:
Media delle calorie per ogni individuo, media complessiva​

Quale tipologia di istruzioni ci serve?​
Istruzioni di iterazione per acquisire l’input e calcolare le medie.​
*/
#include <stdio.h>
#define INDIVIDUI 5
#define GIORNI 7

int main()
{
    unsigned int calorie[INDIVIDUI][GIORNI] = {{0}, {0}};

    float sommaCalorie = 0;

    for (int i = 0; i < INDIVIDUI; i++)
    {
        float sommaCalorieIndivido = 0;
        printf("=== INDIVIDUO %d ===\n", i + 1);
        for (int j = 0; j < GIORNI; j++)
        {
            while (calorie[i][j] <= 0)
            {
                printf("\nInserire calorie dell'individuo %d assunte il giorno %d: ", i + 1, j + 1);
                scanf("%d", &calorie[i][j]);
                if (calorie[i][j] <= 0) // mostra un messaggio d'errore
                    printf("\nInserire un valore valido\n");
                else // altrimenti registra il valore
                    sommaCalorieIndivido = sommaCalorieIndivido + calorie[i][j];
            }
        }
        sommaCalorie += sommaCalorieIndivido;
        printf("Calorie media individuo %d: %f\n", i + 1, (sommaCalorieIndivido / GIORNI));
    }
    printf("Colorie medie complessive: %f\n", sommaCalorie / (INDIVIDUI*GIORNI));
}
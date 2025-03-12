/*
Esercitazione 1 - Battaglia Navale
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define RIGHE 6
#define COLONNE 6
#define ACQUA 0
#define NAVE 1
#define AFFONDATA 2
#define NAVI 6
#define TENTATIVI 10

int main()
{
    int seed = time(NULL);
    srand(seed);
    int i = 0;
    int j = 0;
    // genera campo
    unsigned int campo[RIGHE][COLONNE] = {ACQUA};
    for (i = 0; i < NAVI; i++)
    {
        int r, c;
        do
        {
            r = rand() % 6;
            c = rand() % 6;
        } while (campo[r][c] != ACQUA);
        campo[r][c] = NAVE;
    }
    // stampa campo
    printf("\n");
    for (i = 0; i < RIGHE; i++)
    {
        for (j = 0; j < COLONNE; j++)
        {
            printf("%d\t", campo[i][j]);
        }
        printf("\n");
    }
    int punteggio = 0;
    for (i = 0; i < TENTATIVI; i++)
    {
        int r = -1;
        int c = -1;
        printf("=== TENTATIVO %d ===\n", i + 1);
        while (r == -1 && c == -1)
        {
            printf("Inserisci riga (A-F): ");
            char ch;
            scanf(" %c", &ch);
            r = toupper(ch) - 65;
            printf("Inserisci colonna (1-6): ");
            scanf("%d", &c);
            c--;
            if (!(r >= 0 && r < RIGHE && c >= 0 && c < COLONNE))
            {
                printf("COORDINATE NON VALIDE\n");
                r = -1;
                c = -1;
            }
        }
        printf("Coordinate matrice (%d, %d): \n", r, c);
        if (campo[r][c] == ACQUA)
        {
            printf("Acqua!\n");
        }
        else if (campo[r][c] == NAVE)
        {
            printf("Affondata!\n");
            campo[r][c] = AFFONDATA;
            punteggio++;
        }
        else if (campo[r][c] == AFFONDATA)
        {
            printf("Smemorato! Qui hai già sparato!\n");
        }
    }
    printf("\nPUNTEGGIO: %d\n", punteggio);
}

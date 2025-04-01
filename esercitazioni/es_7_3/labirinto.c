#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef LABIRINTO_C_IMPL
#define LABIRINTO_C_IMPL

#define DIM 8
#define VUOTA 0
#define VISITATA 1

typedef struct
{
    int mappa[DIM][DIM];
    int xG;
    int yG;
    int xT;
    int yT;
    int punteggio;
} labirinto;

void stampaLabirinto(int hide);

labirinto l = {{VUOTA, VUOTA}, -1, -1, -1, -1, 0};

void creaLabirinto()
{
    int seed = time(NULL);
    srand(seed);
    l.xG = rand() % DIM;
    l.yG = rand() % DIM;
    l.mappa[l.yG][l.xG] = VISITATA;
    while (l.xT != l.xG && l.yT != l.yG)
    {
        l.xT = rand() % DIM;
        l.yT = rand() % DIM;
    }
}

int muovi(char comando)
{
    switch (comando)
    {
    case 'W':
        if (l.yG > 0)
        {
            l.yG--;
        }
        else
        {
            printf("!!! NON POSSO ANDARE IN ALTO !!!\n");
        }
        break;
    case 'S':
        if (l.yG < DIM - 1)
        {
            l.yG++;
        }
        else
        {
            printf("!!! NON POSSO ANDARE IN BASSO !!!\n");
        }
        break;
    case 'A':
        if (l.xG > 0)
        {
            l.xG--;
        }
        else
        {
            printf("!!! NON POSSO ANDARE A SINISTRA !!!\n");
        }
        break;
    case 'D':
        if (l.xG < DIM - 1)
        {
            l.xG++;
        }
        else
        {
            printf("!!! NON POSSO ANDARE A DESTRA !!!\n");
        }
        break;
    case 'Z':
        stampaLabirinto(0);
        l.punteggio += 10;
        return 0; // ritorna senza modificare mappa e punteggio
    default:
        printf("!!! COMANDO NON VALIDO !!!\n");
    }
    l.mappa[l.yG][l.xG] = VISITATA;
    l.punteggio++;
    if (l.xG == l.xT && l.yG == l.yT)
    {
        printf("*** HAI TROVATO IL TESORO! ***\n");
        printf("PUNTEGGIO: %d\n", l.punteggio);
        return 1;
    }
    else
    {
        return 0;
    }
}

void stampaLabirinto(int hide)
{
    for (int i = 0; i < DIM; i++)
    {
        printf("\n");
        for (int j = 0; j < DIM; j++)
        {
            if (i == l.yG && j == l.xG)
                printf("@");
            else if (i == l.yT && j == l.xT)
                printf(".");
            else if (hide)
                printf(".");
            else
            {
                if (l.mappa[i][j] == VUOTA)
                {
                    printf(".");
                }
                else if (l.mappa[i][j] == VISITATA)
                {
                    printf("#");
                }
            }
        }
    }
    //printf("\nCoordinate giocatore: %d\t%d \n", l.yG, l.xG);
    //printf("Coordinate tesoro: %d\t%d \n", l.yT, l.xT);
    printf("Punteggio: %d \n", l.punteggio);
}

#endif
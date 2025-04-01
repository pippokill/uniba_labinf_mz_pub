#include <stdio.h>
#include <ctype.h>
#include "labirinto.h"

int main()
{
    char mossa;

    creaLabirinto();

    int esci = 0;

    while (!esci)
    {
        //stampaLabirinto(1);
        printf("\nMuoviti (WASD) / Aiuto (Z): ");
        scanf(" %c", &mossa);
        esci = muovi(toupper(mossa));
    }

    return 0;
}
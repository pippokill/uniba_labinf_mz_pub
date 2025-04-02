#include <stdio.h>
#include <ctype.h>
#include "labirinto_p.h"

int main()
{
    char mossa;

    labirinto l = creaLabirinto();

    int esci = 0;

    while (!esci)
    {
        //stampaLabirinto(1);
        printf("\nMuoviti (WASD) / Aiuto (Z): ");
        scanf(" %c", &mossa);
        esci = muovi(&l, toupper(mossa));
    }

    return 0;
}
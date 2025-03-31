#include <stdio.h>
#include "studenti.h"

#define STUDENTI 2

int main()
{
    studente classe[STUDENTI] = {"", "", {0, 0, 0}, 0, {0}};
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        classe[i] = inserisci();
    }
    calcolaMedia(classe, STUDENTI);
    printf("\n === MEDIA ESAMI PER STUDENTE ===\n");
    // calcola media
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        printf("Media esami studente %s %s: %.2f \n", classe[i].cognome, classe[i].nome, classe[i].media);
    }
    int maxPos = maxMedia(classe, STUDENTI);

    // stampa nome e cognome dello studente che ha la media più alta
    if (maxPos > -1)
    {
        printf("\nStudente con la media più alta: %s\t%s\t%f\n", classe[maxPos].nome, classe[maxPos].cognome, classe[maxPos].media);
    }
    int freq[14] = {0};
    frequenzaVoti(classe, STUDENTI, freq);
    printf("\nFrequenza voti esami:\n");
    for (unsigned int i = 0; i < 14; i++)
    {
        if (i < 13)
            printf("Frequenza voto %d: %d\n", i + 18, freq[i]);
        else
            printf("Frequenza voto Trenta e Lode: %d\n", freq[i]);
    }
    printf("\n");
}

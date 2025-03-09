#include <stdio.h>
#define NUM_FILMS 5
#define MAX_LUNGHEZZA_TITOLO 10
#define MAX_LUNGHEZZA_GENERE 10

typedef struct
{
    unsigned char mese[2];
    unsigned int anno;
} data;

typedef struct
{
    char titolo[MAX_LUNGHEZZA_TITOLO];
    char genere[MAX_LUNGHEZZA_GENERE];
    data uscita;
    unsigned int durata;
} film;

int main()
{
    film archivio[NUM_FILMS] = {{"", "", {"", 0}, 0}}; // variabile archivio ​
    // Acquisizione input​
    for (unsigned int i = 0; i < NUM_FILMS; i++)
    {
        printf("Film n.%d Inserisci titolo:", i + 1);
        scanf("%15s", archivio[i].titolo); // NOTA: non accetta spazi
        printf("\nFilm n.%d Inserisci genere:", i + 1);
        scanf("%10s", archivio[i].genere); // NOTA: non accetta spazi
        printf("Film n.%d Inserisci mese di pubblicazione:", i + 1);
        scanf("%s", &archivio[i].uscita.mese);
        printf("Film n.%d Inserisci anno di pubblicazione:", i + 1);
        scanf("%u", &archivio[i].uscita.anno);
        printf("Film n.%d Inserisci durata:", i + 1);
        scanf("%u", &archivio[i].durata);
    }
    // Ciclo di Stampa  ​
    for (unsigned int j = 0; j < NUM_FILMS; j++)
    {
        printf("\n%s\t%s\t%u/%u\t%u\n", archivio[j].titolo, archivio[j].genere, archivio[j].uscita.mese, archivio[j].uscita.anno, archivio[j].durata);
    }
}
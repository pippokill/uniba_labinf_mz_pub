#include <stdio.h>
#define NUM_FILMS 5
#define MAX_LUNGHEZZA_TITOLO 20
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
    film archivio[NUM_FILMS] = {"", "", {"", 0}, 0}; // variabile archivio ​
    // Acquisizione input​
    for (unsigned int i = 0; i < NUM_FILMS; i++)
    {
        printf("Film n.%d Inserisci titolo:", i + 1);
        scanf("%20s", archivio[i].titolo); // NOTA: non accetta spazi
        printf("\nFilm n.%d Inserisci genere:", i + 1);
        scanf("%10s", archivio[i].genere); // NOTA: non accetta spazi
        printf("Film n.%d Inserisci mese di pubblicazione:", i + 1);
        scanf("%2s", &archivio[i].uscita.mese);
        printf("Film n.%d Inserisci anno di pubblicazione:", i + 1);
        scanf("%u", &archivio[i].uscita.anno);
        do
        {
            printf("Film n.%d Inserisci durata:", i + 1);
            scanf("%u", &archivio[i].durata);
            if (&archivio[i].durata <= 0)
            {
                printf("\nValore durata non valido, la durata deve essere maggiore di 0.");
            }
        } while (&archivio[i].durata <= 0);
    }
    // Ciclo di Stampa  ​
    for (unsigned int j = 0; j < NUM_FILMS; j++)
    {
        printf("\n%s\t%s\t%s/%u\t%u\n", archivio[j].titolo, archivio[j].genere, archivio[j].uscita.mese, archivio[j].uscita.anno, archivio[j].durata);
    }
}
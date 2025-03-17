#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STUDENTI 2
#define ESAMI 20
#define STRING_LENGHT 40

typedef struct
{
    int giorno;
    int mese;
    int anno;
} data;

typedef struct
{
    char nome[STRING_LENGHT];
    char cognome[STRING_LENGHT];
    data nascita;
    int matricola;
    int libretto[ESAMI];
} studente;

int main()
{
    studente classe[STUDENTI] = {"", "", {0, 0, 0}, 0, {0}};
    int seed = time(NULL);
    static int giorni_validi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    srand(seed);
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        printf("Inserire nome studente %d: ", i + 1);
        scanf("%s", classe[i].nome);
        printf("Inserire cognome studente %d: ", i + 1);
        scanf("%s", classe[i].cognome);
        do
        {
            printf("Inserire matricola studente %d: ", i + 1);
            scanf("%d", &classe[i].matricola);
            if (classe[i].matricola <= 0)
            {
                printf("\nLa matricola non è valida, deve essre maggiore di 0!\n");
            }
        } while (classe[i].matricola <= 0);
        do
        {
            printf("Inserire mese di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.mese);
            if (classe[i].nascita.mese < 1 || classe[i].nascita.mese > 12)
            {
                printf("\nIl mese di nascita non è valido, deve essre compreso tra 1 e 12!\n");
            }
        } while (classe[i].nascita.mese < 1 || classe[i].nascita.mese > 12);
        do
        {
            printf("Inserire giorno di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.giorno);
            if (classe[i].nascita.giorno < 1 || classe[i].nascita.giorno > giorni_validi[classe[i].nascita.mese - 1])
            {
                printf("\nIl giorno di nascita non è valido per il mese selezionato, deve essre compreso tra 1 e %d!\n", giorni_validi[classe[i].nascita.mese - 1]);
            }
        } while (classe[i].nascita.giorno < 1 || classe[i].nascita.giorno > giorni_validi[classe[i].nascita.mese - 1]);
        do
        {
            printf("Inserire anno di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.anno);
            if (classe[i].nascita.anno < 1800)
            {
                printf("\nL'anno di nascita non è valido, deve essre maggiore di 1799!\n");
            }
        } while (classe[i].nascita.anno < 1800);
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            classe[i].libretto[j] = rand() % 31 + 1;
        }
    }

    // calcola media
    int max_pos = -1;
    float max_avg = 0;
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        float avg = 0;
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            avg += classe[i].libretto[j];
        }
        avg = avg / ESAMI;
        if (avg > max_avg)
        {
            max_avg = avg;
            max_pos = i;
        }
        printf("Media esami studente %d: %.2f \n", i + 1, avg);
    }

    // stampa nome e cognome dello studente che ha la media più alta
    if (max_pos > -1)
    {
        printf("\nStudente con la media più alta: %s\t%s", classe[max_pos].nome, classe[max_pos].cognome);
    }

    int freq[31] = {0};
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            freq[classe[i].libretto[j] - 1]++;
        }
    }
    printf("\nFrequenza voti esami:");
    for (unsigned int i = 0; i < 31; i++)
    {
        printf("\t%d", freq[i]);
    }
    printf("\n");
}

#include <time.h>
#include <stdlib.h>

#ifndef STUDENTI_IMPL

#define STUDENTI_IMPL

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
    double media;
} studente;

static int giorni_validi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int rndInit = 0;

studente inserisci()
{
    if (!rndInit)
    {
        int seed = time(NULL);
        srand(seed);
        rndInit = 1;
    }
    studente s = {"", "", {0, 0, 0}, 0, {0}, 0};
    printf("Inserire nome studente: ");
    scanf("%s", s.nome);
    printf("Inserire cognome studente: ");
    scanf("%s", s.cognome);
    do
    {
        printf("Inserire matricola studente: ");
        scanf("%d", &s.matricola);
        if (s.matricola <= 0)
        {
            printf("\nLa matricola non è valida, deve essre maggiore di 0!\n");
        }
    } while (s.matricola <= 0);
    do
    {
        printf("Inserire mese di nascita studente: ");
        scanf("%d", &s.nascita.mese);
        if (s.nascita.mese < 1 || s.nascita.mese > 12)
        {
            printf("\nIl mese di nascita non è valido, deve essre compreso tra 1 e 12!\n");
        }
    } while (s.nascita.mese < 1 || s.nascita.mese > 12);
    do
    {
        printf("Inserire giorno di nascita studente: ");
        scanf("%d", &s.nascita.giorno);
        if (s.nascita.giorno < 1 || s.nascita.giorno > giorni_validi[s.nascita.mese - 1])
        {
            printf("\nIl giorno di nascita non è valido per il mese selezionato, deve essre compreso tra 1 e %d!\n", giorni_validi[s.nascita.mese - 1]);
        }
    } while (s.nascita.giorno < 1 || s.nascita.giorno > giorni_validi[s.nascita.mese - 1]);
    do
    {
        printf("Inserire anno di nascita studente ");
        scanf("%d", &s.nascita.anno);
        if (s.nascita.anno < 1800)
        {
            printf("\nL'anno di nascita non è valido, deve essre maggiore di 1799!\n");
        }
    } while (s.nascita.anno < 1800);
    for (unsigned int j = 0; j < ESAMI; j++)
    {
        s.libretto[j] = rand() % (31 - 18 + 1) + 18;
    }
    return s;
}

void calcolaMedia(studente studenti[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float avg = 0;
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            avg += studenti[i].libretto[j];
        }
        avg = avg / ESAMI;
        studenti[i].media = avg;
    }
}

int maxMedia(studente studenti[], int n)
{
    int max_pos = -1;
    float max_avg = 0;
    for (int i = 0; i < n; i++)
    {
        if (studenti[i].media > max_avg)
        {
            max_avg = studenti[i].media;
            max_pos = i;
        }
    }
    return max_pos;
}

void frequenzaVoti(studente studenti[], int n, int freq[])
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            freq[studenti[i].libretto[j] - 18]++;
        }
    }
}

#endif
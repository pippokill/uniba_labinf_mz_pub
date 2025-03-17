#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STUDENTI 2
#define ESAMI 20
#define STRING_LENGHT 40
#define NOMI_ESAMI 5

typedef struct
{
    int giorno;
    int mese;
    int anno;
} data;

typedef struct
{
    char insegnamento[STRING_LENGHT];
    int voto;
} esame;

typedef struct
{
    char nome[STRING_LENGHT];
    char cognome[STRING_LENGHT];
    data nascita;
    int matricola;
    esame libretto[ESAMI];
} studente;

int main()
{
    studente classe[STUDENTI] = {"", "", {0, 0, 0}, 0, {"", 0}};
    int seed = time(NULL);
    static int giorni_validi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char nomiEsami[NOMI_ESAMI][STRING_LENGHT] = {"Programmazione", "Logica", "Analisi matematica", "Matematica discreta", "Ingegneria del software"};
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
            classe[i].libretto[j].voto = rand() % (31 - 18 + 1) + 18;
            int esami_rand[NOMI_ESAMI] = {0};
            int ke = 0;
            for (ke = 0; ke < NOMI_ESAMI; ke++)
            {
                esami_rand[ke] = rand() % NOMI_ESAMI;
                for (int ch = 0; ch < ke; ch++)
                {
                    if (esami_rand[ke] == esami_rand[ch])
                    {
                        ke--;
                        break;
                    }
                }
            }
            for (ke = 0; ke < NOMI_ESAMI; ke++)
            {
                for (int k = 0; k < STRING_LENGHT; k++)
                    classe[i].libretto[j].insegnamento[k] = nomiEsami[esami_rand[ke]][k];
            }
        }
    }
    printf("\n === MEDIA ESAMI PER STUDENTE ===\n");
    // calcola media
    int max_pos = -1;
    float max_avg = 0;
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        float avg = 0;
        int s_max_pos = -1;
        int s_min_pos = -1;
        int s_max = 0;
        int s_min = 32;
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            avg += classe[i].libretto[j].voto;
            if (classe[i].libretto[j].voto < s_min)
            {
                s_min = classe[i].libretto[j].voto;
                s_min_pos = j;
            }
            if (classe[i].libretto[j].voto > s_max)
            {
                s_max = classe[i].libretto[j].voto;
                s_max_pos = j;
            }
        }
        avg = avg / ESAMI;
        if (avg > max_avg)
        {
            max_avg = avg;
            max_pos = i;
        }
        printf("Media esami studente %s %s: %.2f\n", classe[i].cognome, classe[i].nome, avg);
        printf("Esame con il voto più basso: %s\t%d\n", classe[i].libretto[s_min_pos].insegnamento, classe[i].libretto[s_min_pos].voto);
        printf("Esame con il voto più alto: %s\t%d\n", classe[i].libretto[s_max_pos].insegnamento, classe[i].libretto[s_max_pos].voto);
    }

    // stampa nome e cognome dello studente che ha la media più alta
    if (max_pos > -1)
    {
        printf("\nStudente con la media più alta: %s\t%s\n", classe[max_pos].nome, classe[max_pos].cognome);
    }

    int freq[14] = {0};
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            freq[classe[i].libretto[j].voto - 18]++;
        }
    }
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

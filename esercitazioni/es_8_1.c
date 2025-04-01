#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define NUM_AUTO 5 // numero di auto da valutare​

#define TEMPO_MIN 80000 // tempo minimo sul giro​

#define TEMPO_MAX 90000 // tempo massimo sul giro​

/* Funzione per la conversione di un tempo in millisecondi
nel formato minuti/secondi/decimi. in questo caso è accettabile
usare VOID perchè restituisce più di un valore​
*/
void converti(int millisecondi, int *minuti, int *secondi, int *decimi);

int main(void)
{
    int tempi[NUM_AUTO] = {0}; // vettore contenente i tempi delle auto​
    int minuti = 0;            // variabili di output da mostrare​
    int secondi = 0;
    int decimi = 0;
    int seed = time(NULL);
    int giro = 0;
    srand(seed);
    for (int i = 0; i < NUM_AUTO; i++)
    {
        // genero random un valore sul giro e lo memorizzo​
        giro = rand() % (TEMPO_MAX - TEMPO_MIN + 1) + TEMPO_MIN;
        tempi[i] = giro;
        // PASSAGGIO PER RIFERIMENTO: non voglio perdere il risultato della conversione​
        converti(tempi[i], &minuti, &secondi, &decimi);
        printf("Auto n.%d:tempo %d'%d''%d \n", i + 1, minuti, secondi, decimi);
    }
}

void converti(int millisecondi, int *minuti, int *secondi, int *decimi)
{
    *secondi = millisecondi / 1000;
    *decimi = millisecondi - (*secondi * 1000);
    *minuti = *secondi / 60;
    *secondi = *secondi - (*minuti * 60);
}
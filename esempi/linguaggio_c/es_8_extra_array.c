#include <stdio.h>

#define GIORNI_SETTIMANA 7 // costanti simboliche​

int main(void)
{
    int calorie[GIORNI_SETTIMANA]; // vettore delle calorie  ​
    int somma_calorie = 0;         // variabili locali
    float media_calorie = 0.0;
    int i = 0;
    char* giorni[7]={"Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato", "Domenica"};

    // ciclo di inizializzazione
    for (i = 0; i < GIORNI_SETTIMANA; i++)
    {
        calorie[i] = 0;
    }
    // ciclo di acquisizione ed elaborazione  ​

    for (i = 0; i < GIORNI_SETTIMANA; i++)
    { // programmazione difensiva - controlla valori di input non corretti    ​
        while (calorie[i] <= 0)
        {
            printf("\nInserire calorie assunte il giorno %s: ", giorni[i]);
            scanf("%d", &calorie[i]);
            if (calorie[i] <= 0) // mostra un messaggio d'errore
                printf("\nInserire un valore valido\n");
            else // altrimenti registra il valore
                somma_calorie = somma_calorie + calorie[i];
        }
    }
    media_calorie = (float)somma_calorie / GIORNI_SETTIMANA;
    printf("\n Media calorie assunte: %.2f\n", media_calorie);
}
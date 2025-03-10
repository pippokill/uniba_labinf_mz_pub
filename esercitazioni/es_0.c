#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAMPIONE 10

int main()
{
    int seed = time(NULL);
    srand(seed);
    // variabili
    int maxPesoOver40 = 0;
    float maxAltezzaOver40 = 0;
    int maxPesoUnder40 = 0;
    float maxAltezzaUnder40 = 0;
    float mediaBMIOver40 = 0;
    float mediaBMIUnder40 = 0;
    int over40 = 0;
    // int randomValue = rand() % (MAX-MIN+1) + MIN;
    for (int i = 0; i < CAMPIONE - 1; i++)
    {
        int eta = rand() % (100 - 1 + 1) + 1;
        int peso = rand() % (150 - 30 + 1) + 30;
        float altezza = (float)(rand() % (210 - 120 + 1) + 120) / 100;
        float bmi = peso / (altezza * altezza);
        printf("Età: %d   Peso: %d   Altezza: %f   BMI: %f\n", eta, peso, altezza, bmi);
        if (eta >= 40)
        {
            mediaBMIOver40 += bmi;
            over40++;
            if (peso > maxPesoOver40)
                maxPesoOver40 = peso;
            if (altezza > maxAltezzaOver40)
                maxAltezzaOver40 = altezza;
        }
        else
        {
            mediaBMIUnder40 += bmi;
            if (peso > maxPesoUnder40)
                maxPesoUnder40 = peso;
            if (altezza > maxAltezzaUnder40)
                maxAltezzaUnder40 = altezza;
        }
    }
    mediaBMIOver40 = mediaBMIOver40 / over40;
    mediaBMIUnder40 = mediaBMIUnder40 / (CAMPIONE - over40);
    printf("=== STATISTICHE UNDER 40 ===\n");
    printf("Altezza massima: %f\n", maxAltezzaUnder40);
    printf("Peso massimo: %d\n", maxPesoUnder40);
    printf("BMI medio: %f\n", mediaBMIUnder40);
    // https://www.salute.gov.it/portale/nutrizione/dettaglioIMCNutrizione.jsp?area=nutrizione&id=5479&lingua=italiano&menu=vuoto
    if (mediaBMIUnder40<18.50) {
        printf("Campione sottopeso.\n");
    } else if(mediaBMIUnder40>24.99) {
        printf("Campione sovrappeso.\n");
    } else {
        printf("Campione normopeso.\n");
    }
    printf("=== STATISTICHE OVER 40 ===\n");
    printf("Altezza massima: %f\n", maxAltezzaOver40);
    printf("Peso massimo: %d\n", maxPesoOver40);
    printf("BMI medio: %f\n", mediaBMIOver40);
    if (mediaBMIOver40<18.50) {
        printf("Campione sottopeso.\n");
    } else if(mediaBMIOver40>24.99) {
        printf("Campione sovrappeso.\n");
    } else {
        printf("Campione normopeso.\n");
    }
}
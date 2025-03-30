#include <stdio.h>

float calcolaBMI(float altezza, float peso)
{
    float BMI = peso / ((altezza / 100) * (altezza / 100));
    return BMI;
}

int main(void)
{
    float altezza = 0;
    float peso = 0;
    float BMI = 0.0;
    printf("Inserisci altezza e peso separati da spazio: ");
    scanf("%f %f", &altezza, &peso);
    BMI = calcolaBMI(altezza, peso);
    printf("Il tuo BMI è : %.2f\n", BMI);
}


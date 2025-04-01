#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAMPIONE 5
#define BMI_THRESHOLD 24.99

float calculateBMI(int weight, int height);

float calculateAverage(float values[], int n);

float calculateMaximum(float values[], int n);

void acquireInput(float values[], int n);

void printOutput(float values[], int n, float average, float maximum);

int main()
{
    float values[CAMPIONE] = {0};
    acquireInput(values, CAMPIONE);
    float avg = calculateAverage(values, CAMPIONE);
    float max = calculateMaximum(values, CAMPIONE);
    printOutput(values, CAMPIONE, avg, max);
}

void acquireInput(float values[], int n)
{
    int seed = time(NULL);
    srand(seed);
    int height = 0;
    int weight = 0;
    float BMI = 0.0;
    for (unsigned int i = 0; i < CAMPIONE; i++)
    {
        height = rand() % 41 + 160;
        weight = rand() % 61 + 40;
        BMI = calculateBMI(weight, height);
        values[i] = BMI;
    }
}

float calculateBMI(int weight, int height)
{
    float BMI = (float) weight / (((float) height / 100) * ((float) height / 100));
    return BMI;
}

float calculateAverage(float values[], int n)
{
    float avg = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        avg += values[i];
    }
    return avg / n;
}

float calculateMaximum(float values[], int n)
{
    float max = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        if (values[i] > max)
            max = values[i];
    }
    return max;
}

void printOutput(float values[], int n, float average, float maximum)
{
    for (unsigned int i = 0; i < n; i++)
    {
        printf("Individio %d, BMI %.2f ", i + 1, values[i]);
        if (values[i] > BMI_THRESHOLD)
            printf(" è sovrappeso\n");
        else
            printf(" non è in soveappeso\n");
    }
    printf("Il valore medio del BMI è %.2f\n", average);
    printf("Il valore massimo di BMI è %.2f\n", maximum);
}

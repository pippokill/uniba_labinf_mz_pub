#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMERI 10

void scrivi(char *nomeFile, int n);
int leggiInt(char *nomeFile, int pos);

int main()
{
    scrivi("int.dat", NUMERI);
    int v = leggiInt("int.dat", 3);
    printf("LETTO: %d\n", v);
}

void scrivi(char *nomeFile, int n)
{
    int seed = time(NULL);
    srand(seed);
    FILE *file = fopen(nomeFile, "wb");
    if (file != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            int r = rand() % 100;
            if (fwrite(&r, sizeof(int), 1, file) > 0)
                printf("SCRITTO: %d\n", r);
        }
        fclose(file);
    }
    else
    {
        printf("Errore apertura file!\n");
    }
}

int leggiInt(char *nomeFile, int pos)
{
    FILE *file = fopen(nomeFile, "rb");
    if (file != NULL)
    {
        fseek(file, pos * sizeof(int), SEEK_SET);
        int v;
        fread(&v, sizeof(int), 1, file);
        fclose(file);
        return v;
    }
    else
    {
        printf("Errore apertura file!\n");
    }
}
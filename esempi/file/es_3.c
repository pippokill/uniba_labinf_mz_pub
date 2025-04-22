#include <stdio.h>

int main()
{
    FILE *file;
    if ((file = fopen("test.txt", "r+")) == NULL)
    {
        puts("Errore nell'apertura del file");
    }
    else
    {
        puts("File aperto...");
        // Lettura
        int value = 0;
        fscanf(file, "%d", &value);
        printf("Valore letto: %d\n", value);
        // Scrittura
        fprintf(file, "%d", 1981);
        puts("Valore scritto");
    }
    if (file != NULL && !fclose(file))
        puts("File chiuso.");
}
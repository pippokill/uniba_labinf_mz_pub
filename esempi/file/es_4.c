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
        fprintf(file, "%d", 123);
        puts("Valore scritto");
        
        rewind(file);

        fprintf(file, "%d", 123);
        puts("Valore scritto");
        
        if (!fclose(file))
            puts("File chiuso.");
    }
}
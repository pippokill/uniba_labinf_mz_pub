// Uso degli argomenti della riga di comando
#include <stdio.h>
int main(int argc, char *argv[])
{
    // controlla il numero degli argomenti della riga di comando
    if (argc != 3)
    {
        puts("Utilizzo del comando: mycopy nomefile_input nomefile_output");
    }
    else
    {
        FILE *inFilePtr = NULL;
        if ((inFilePtr = fopen(argv[1], "r")) != NULL)
        {
            FILE *outFilePtr = NULL;
            if ((outFilePtr = fopen(argv[2], "w")) != NULL)
            {
                int c = 0;
                // legge e invia in uscita i caratteri
                while ((c = fgetc(inFilePtr)) != EOF)
                {
                    fputc(c, outFilePtr);
                }
                fclose(outFilePtr);
            }
            else
            { // non e' stato possibile aprire il file di output
                printf("File \"%s\" non può essere aperto in scrittura.\n", argv[2]);
            }
            fclose(inFilePtr); // chiudi il file di input
        }
        else
        { // non e' stato possibile aprire il file di input
            printf("File \"%s\" non può essere aperto in lettura.\n", argv[1]);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("Utilizzo dei File");
	FILE *file;

	// Apertura del File. Stampa messaggio di conferma o di errore
	if ((file = fopen("test.txt", "r")) == NULL)
	{
		puts("Errore nell'apertura");
	}
	else
	{
		puts("File aperto con successo");
	}

	// Chiusura del file
	if (file != NULL && !fclose(file))
	{
		puts("File Chiuso");
	}
}

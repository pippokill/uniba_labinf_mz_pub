/*
Implementare un programma che acquisisca da tastiera nome (o matricola) e voto d’esame per cinque individui. ​
I valori acquisiti devono essere memorizzati su file (una coppia di valori per ogni riga). ​
Il programma deve poi leggere il file dall’inizio e stampare a schermo i nomi degli studenti che hanno superato l’esame.​
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASSED 18
#define STUDENTI 5

void inputDati(FILE *file);
void printPassed(FILE *file);
void inputDati2(FILE *file);

int main()
{
	FILE *file;
	file = fopen("esami.txt", "a+");
	printf("Il programma memorizza in un file esami.txt le votazioni riportate \n dagli studenti in un singolo insegnamento\n");
	if (file == NULL)
		printf("Errore nell'apertura del file!\n");
	else
	{
		inputDati(file);
		// inputDati2(file);
		rewind(file);
		printPassed(file);
		fclose(file);
	}
}

void inputDati(FILE *file)
{
	for (unsigned int i = 0; i < STUDENTI; i++)
	{
		char nome[20];
		int voto;
		printf("Inserisce nome e voto separati da spazi: ");
		scanf("%19s%d", nome, &voto);
		fprintf(file, "%s\t%d\n", nome, voto);
	}
}

void inputDati2(FILE *file)
{
	char nome[20];
	int voto;
	printf("Inserisce nome e voto separati da spazi: ");
	scanf("%19s%d", nome, &voto);
	while (!feof(stdin))
	{
		fprintf(file, "%s\t%d\n", nome, voto);
		printf("Inserisce nome e voto separati da spazi: ");
		scanf("%19s%d", nome, &voto);
	}
}

void printPassed(FILE *file)
{
	printf("\nElenco studenti che hanno superato l'esame:\n\n");
	while (!feof(file))
	{
		char nome[20];
		int voto;
		int read = fscanf(file, "%s\t%d", nome, &voto);
		if (read > 0 && voto >= PASSED)
		{
			printf("%s\t%d\n", nome, voto);
		}
	}
}

/*
 * Esercitazione 10.2
 * Definire una variabile di tipo studente, rappresentata attraverso una struct con: codice, nome e cognome, matricola, voto medio di esami.
 * Implementare un programma che consenta di
 * - Memorizzare e aggiornare le informazioni in un file​
 * - Ricercare uno specifico studente per cognome e/o per codice​
 * - Visualizzare lo studente/gli studenti con media maggiore​
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int codice;
	char cognome[10];
	char nome[10];
	char matricola[10];
	float media;
} studente_t;

void leggi(FILE *primo);
void scrivi(FILE *primo);
void modifica(FILE *primo);
void cancella(FILE *primo);
void ricerca(FILE *primo);

int main()
{
	FILE *primo_file;

	primo_file = fopen("studenti.dat", "rb+");
	// se uso ab+ appende alla fine, se uso wb+ riscrive, se uso rb+ scrive dove chiedo
	printf("Il programma scrive e legge un file studenti.dat le informazioni di un elenco di studenti \n\n");
	if (primo_file == NULL)
		printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
	else
	{
		scrivi(primo_file);
		leggi(primo_file);
		puts("\n\n************  MODIFICA DATI NEI RECORD DEL FILE   ***********");
		modifica(primo_file);
		leggi(primo_file);
		puts("\n\n************  CANCELLAZIONE RECORD DAL FILE   ***********");
		cancella(primo_file);
		leggi(primo_file);
		puts("\n\n************  RICERCA RECORD DAL FILE   ***********");
		ricerca(primo_file);
		fclose(primo_file);
	}
	return 0;
}

void scrivi(FILE *primo)
{
	studente_t stud = {0, "", "", "", 0};

	do
	{
		printf("Inserire i dati dello studente (-1 nel codice per terminare) -->");
		printf("\n\n\tCODICE   --> ");
		scanf("%d", &stud.codice);
		if (stud.codice != -1)
		{
			printf("\tCOGNOME   --> ");
			scanf("%s", stud.cognome);
			printf("\tNOME   --> ");
			scanf("%s", stud.nome);
			printf("\tMATRICOLA   --> ");
			scanf("%s", stud.matricola);
			printf("\tMEDIA ESAMI   --> ");
			scanf("%f", &stud.media);
			fseek(primo, (stud.codice - 1) * sizeof(studente_t), SEEK_SET);
			fwrite(&stud, sizeof(stud), 1, primo);
			printf("\n");
		}

	} while (stud.codice != -1);

	printf("***************Inserimento Terminato******************\n\n");
}

void leggi(FILE *primo)
{
	studente_t stud;
	rewind(primo);
	printf("I dati memorizzati nel file sono i seguenti \n");
	printf("%-10s %-10s %-10s %-10s %-10s\n\n", "Codice", "Cognome", "Nome", "Matricola", "Media Esami");

	while (!feof(primo))
	{
		fread(&stud, sizeof(studente_t), 1, primo);
		if (!feof(primo))
			printf(" %d %-10s %-10s %-10s %5.2f\n\n", stud.codice, stud.cognome, stud.nome, stud.matricola, stud.media);
	}

	printf("***************File Terminato******************\n\n");
}

void modifica(FILE *primo)
{

	studente_t stud = {0, "", "", "", 0};
	do
	{
		printf("Inserire il codice dello studente che vuoi modificare (-1 nel codice per terminare) -->");
		printf("\n\n\tCODICE   --> ");
		scanf("%d", &stud.codice);
		if (stud.codice != -1)
		{
			fseek(primo, (stud.codice - 1) * sizeof(studente_t), SEEK_SET);
			fread(&stud, sizeof(studente_t), 1, primo); // questa fread è necessaria per controllare che il record esista e sia avvalorato
			if (!feof(primo) && stud.codice != 0)
			{
				printf("\tCOGNOME   --> ");
				scanf("%s", stud.cognome);
				printf("\tNOME   --> ");
				scanf("%s", stud.nome);
				printf("\tMATRICOLA   --> ");
				scanf("%s", stud.matricola);
				printf("\tMEDIA ESAMI   --> ");
				scanf("%f", &stud.media);
				fseek(primo, (stud.codice - 1) * sizeof(studente_t), SEEK_SET); // questa fseek è necessaria perchè dopo la fread il puntatore si è spostato
				fwrite(&stud, sizeof(stud), 1, primo);
				printf("\n");
			}
			else
				puts("Codice non trovato!");
		}
	} while (stud.codice != -1);
}

void cancella(FILE *primo)
{

	studente_t stud, stud_reset = {0, "", "", "", 0};
	int codice;

	do
	{
		printf("Inserire il codice dello studente che vuoi cancellare (-1 nel codice per terminare) -->");
		printf("\n\n\tCODICE   --> ");
		scanf("%d", &stud.codice);
		if (stud.codice != -1)
		{
			fseek(primo, (stud.codice - 1) * sizeof(studente_t), SEEK_SET);
			fread(&stud, sizeof(studente_t), 1, primo); // questa fread è necessaria per controllare che il record esista e sia avvalorato
			if (!feof(primo) && stud.codice != 0)
			{
				codice = stud.codice; // mi conservo il codice prima di sovrascriverlo
				stud = stud_reset;
				fseek(primo, (codice - 1) * sizeof(studente_t), SEEK_SET); // questa fseek è necessaria perchè dopo la fread il puntatore si è spostato
				fwrite(&stud, sizeof(stud), 1, primo);
				puts("Record cancellato");
			}
			else
				puts("Codice non trovato!");
		}
	} while (stud.codice != -1);
}

void ricerca(FILE *primo)
{
	studente_t stud;
	char cognome_ric[10];
	rewind(primo);
	short int trovato = 0;

	printf("\nInserisci il cognome da ricercare: ");
	scanf("%s", cognome_ric);
	fread(&stud, sizeof(studente_t), 1, primo);
	while (!feof(primo) && !trovato)
	{
		if (strstr(stud.cognome, cognome_ric) != NULL)
		{
			trovato = 1;
			printf("%-10s %-10s %-10s %-10s %-10s\n\n", "Codice", "Cognome", "Nome", "Matricola", "Media Esami");
			printf(" %d %-10s %-10s %-10s %5.2f\n\n", stud.codice, stud.cognome, stud.nome, stud.matricola, stud.media);
		}
		fread(&stud, sizeof(studente_t), 1, primo);
	}
	if (!trovato)
	{
		puts("\n\n Nominativo non in elenco");
	}

	printf("***************File Terminato******************\n\n");
}

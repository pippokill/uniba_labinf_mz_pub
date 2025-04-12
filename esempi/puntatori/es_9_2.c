/*
Scrivere una funzione  char* generaPassword(char* nome, char* cognome) che generi random una password per l‘utente​
La funzione prende in input nome e cognome (max. 20 caratteri)​
La funzione restituisce una stringa con i primi tre caratteri del nome, i primi tre caratteri del cognome e due simboli a caso​
Inserire la funzione in un main() che chieda interattivamente all’utente di inserire nome e cognome e stampi la password generata​
Utilizzare calloc() per allocare la memoria.​
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // include la libreria per manipolare i caratteri
#include <string.h> // includo la libreria per manipolare le stringhe
#include <time.h> // libreria per randomizzare il seed

#define LUNG_NOME 20 // lunghezza massima del nome
#define LUNG_COGNOME 20 // lunghezza massima del cognome
#define LUNG_SIMBOLI 5 // vocabolario dei simboli (estendibile)

#define LUNG_PASSWORD 9 // lunghezza della password (aggiungere il terminatore!)
#define NUM_CAR_NOME_PASSWORD 3 // numero di caratteri estratti dal nome da inserire nella password
#define NUM_CAR_COGNOME_PASSWORD 3 // numero di caratteri estratti dal cognome da inserire nella password
#define NUM_SIMBOLI_PASSWORD 2 // numero di simboli nella password

// PROTOTIPO DI FUNZIONE: input -> nome e cognome, output -> password
char* generaPassword(char* nome, char* cognome);

int main(void) {
	char nome[LUNG_NOME]; // variabili locali per input e output
	char cognome[LUNG_COGNOME];
	char* password;

	printf("Inserisci nome: "); // inserimento input da tastiera
	scanf("%20s", nome);
	printf("\nInserisci cognome: ");
	scanf("%20s", cognome);

	password = generaPassword(nome,cognome); // genero la password e la mostro in output

	printf("\n\nCiao, %s %s. La password generata per te è: %s\n",
			nome, cognome, password);
}

/* La funzione prende in input il nome e il cognome di una persona e restituisce
   una password di 8 caratteri che combina nome, cognome e simboli generati random.
*/
char* generaPassword(char* nome, char* cognome) {

	char simboli[LUNG_SIMBOLI] = {'$', '#', '*', '^', '%'}; // estendibile
	int seed = time(NULL);
	srand(seed); // randomizzo la generazione

	int car_nome = 0; // variabile di controllo per verificare la lunghezza del nome
	int car_cognome = 0;

	// alloco un numero sufficiente di caratteri per generare la nuova password
	char* p = (char*)  calloc(LUNG_PASSWORD, sizeof(char));

	// verifico che il nome sia lungo a a sufficienza, altrimenti lo inserisco tutto
	if( strlen(nome) < NUM_CAR_NOME_PASSWORD )
		car_nome = strlen(nome);
	else
		car_nome = NUM_CAR_NOME_PASSWORD;

	// i primi caratteri della password sono estratti dal nome.
	// Utilizzo l'aritmetica dei puntatori per scorrere tra i caratteri
	// utilizza la funzione tolower( ) per convertire tutto in minuscolo
	for(int i=0; i < car_nome; i++) {
		*(p+i) = tolower( *(nome+i) );
	}

	// i primi caratteri della password sono estratti dal cognome.
	// Utilizzo l'aritmetica dei puntatori per scorrere tra i caratteri
	// i = contatore che scorre tra gli elementi del cognome
	// j = contatore che scorre tra gli elementi della password (viene inizializzata
	// in base al numero di caratteri estratti dal nome contenuti nella password
	int j = car_nome;

	// verifico che il cognome sia lungo a a sufficienza, altrimenti lo inserisco tutto
	if( strlen(cognome) < NUM_CAR_COGNOME_PASSWORD )
		car_cognome = strlen(cognome);
	else
		car_cognome = NUM_CAR_COGNOME_PASSWORD;

	for(int i=0; i < car_cognome; i++) {
		*(p+j) = tolower( *(cognome+i) );
		j++; // incremento il contatore per puntare all'elemento successivo
	}

	int k = car_nome + car_cognome;

	for(int i=0; i < NUM_SIMBOLI_PASSWORD; i++) {
		int idSimbolo = rand() % LUNG_SIMBOLI;

		*(p+k) = simboli[idSimbolo]; // genero un simbolo random
		k++;
	}

	return p; // restituisco la password generata
}

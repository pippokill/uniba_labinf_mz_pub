/*
Scrivere una FUNZIONE che, dati in input due array di stringhe composti da nome e cognome, 
inverta il nome dei due individui e lo stampi in output. La stampa deve avvenire nel main!​
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

void scambia(char** a, char** b); // prototipo di funzione per la procedura di scambio
void stampa(char** a, char** b);

int main(void) {
	puts("Esercizio 9.1"); /* prints Esercizio 9.1 */
	char* persona_A[SIZE] = {"Mario", "Rossi"}; // variabili di input
	char* persona_B[SIZE] = {"Luigi", "Bianchi"};
	short int i;

	// STAMPA PRIMA DELLO SCAMBIO
	puts ("\n\nPrima dello scambio:\n");
	stampa (persona_A, persona_B);
	scambia(persona_A, persona_B);
	puts ("Dopo lo scambio:\n");
	// STAMPA DOPO LO SCAMBIO DEI NOMI

	stampa (persona_A, persona_B);
	return EXIT_SUCCESS;
}

// funzione per lo scambio di due nomi
void scambia(char** a, char** b) {
	char* s; // variabile di appoggio
	s = *a; // assegna alla variabile di appoggio il valore del primo elemento (a = primo elemento dell'array)
	*a = *b;
	*b = s; // completa lo scambio
}

void stampa(char** a, char** b) {
	printf("%s\t %s\n", *a, *(a+1));
	printf("%s\t %s\n \n", *b, *(b+1));
}

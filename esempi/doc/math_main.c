#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h" // importo la libreria math

#define SIZE 64	  // fisso la dimensione massima dell'input

/**
* @brief Esempio di utilizzo della libreria math.h
* @return 0 se il programma termina correttamente, altrimenti diverso da 0
*/
int main()
{
	char input_A[SIZE] = {0};	   // memorizza l'input
	char input_B[SIZE] = {0};	   // memorizza l'input
	char *remainingInput_A = NULL; // serve a memorizzare quello che resta dell'input
	char *remainingInput_B = NULL; // serve a memorizzare quello che resta dell'input
	int inputCorrect = 0;		   // serve a uscire dal ciclo appena l'input è corretto
	do
	{
		printf("\nInserire due valori numerici in input, separati da spazio: ");
		scanf("%20s %20s", input_A, input_B);

		int a = (int)strtol(input_A, &remainingInput_A, 0);
		int b = (int)strtol(input_B, &remainingInput_B, 0);

		printf("a pari o dispari? %s\n", pari(a) ? "Pari." : "Dispari.");

		printf("b pari o dispari? %s\n", dispari(b) ? "Dispari." : "Pari.");

		// l'input è corretto quando la parte rimanente della stringa è vuota
		if (strcmp(remainingInput_A, "") == 0 && strcmp(remainingInput_B, "") == 0)
			inputCorrect = 1;

		// calcolo l'espressione (a^2*b)-(a+b^3) e stampo il risultato
		if (inputCorrect)
		{
			int result = sottrazione(prodotto(quadrato(a), b), somma(a, cubo(b)));
			printf("Risultato: %d\n", result);
		}
	} while (inputCorrect == 0); // cicla finchè l'input non è corretto
}

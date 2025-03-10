#include <stdio.h>
#include <ctype.h> // includo la libreria per gestire le funzioni sui caratteri

#define PASSWORD_LENGTH 11 // lunghezza massima della password +  un carattere di fine stringa

int main()
{
	int correct = 0;				// variabile di controllo, diventa = 1 quando è stata inserita una password corretta
	char password[PASSWORD_LENGTH]; // vettore contenente la password

	int upper = 0; // variabili di controllo del numero di maiuscole
	int digit = 0; // e del numero di cifre numeriche

	while (correct == 0)
	{
		// INSERIMENTO INPUT
		printf("Inserisci la tua password (max. 10 caratteri): ");
		scanf("%10s", password); // leggo esattamente dieci caratteri

		upper = 0; // NOTA: perchè inizializzo queste variabili a zero?
		digit = 0;

		// ELABORAZIONE INPUT
		for (unsigned i = 0; i < PASSWORD_LENGTH; i++)
		{
			digit += isdigit(password[i]);
			upper += isupper(password[i]);
			if ((digit > 0) && (upper > 0))
				i = PASSWORD_LENGTH; // a che serve?*/
		}

		// VISUALIZZAZIONE OUTPUT
		if ((digit > 0) && (upper > 0))
		{
			puts("Password impostata correttamente");
			puts(password);
			correct++;
		}
		else if (digit == 0)
			puts("Inserire almeno un carattere numerico");
		if (upper == 0)
			puts("Inserire almeno un carattere maiuscolo");
	}
}

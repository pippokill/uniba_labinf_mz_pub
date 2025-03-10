#include <stdio.h>
#include <stdlib.h>
#define STR_LENGTH 20

int main(void)
{
	char stringaConSpazi[STR_LENGTH] = {""};
	puts("=== Esempio di stringa con spazi ===");
	puts("Inserisci una stringa lunga al più 20 caratteri");
	fgets(stringaConSpazi, STR_LENGTH, stdin);
	printf("Hai inserito: %s\n\n", stringaConSpazi);
	puts("\n\nInserisci un'altra stringa lunga al più 20 caratteri");
	scanf("%[^\n]s", stringaConSpazi); // altro modo metodo meno sicuro
	printf("Hai inserito: %s\n\n", stringaConSpazi);
	return EXIT_SUCCESS;
}

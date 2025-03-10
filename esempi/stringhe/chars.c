
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LUNG 20

int main()
{

   char stringa[LUNG] = "Studente Matr.33965";
   char ch;
   if (isalpha(stringa[0]))
      printf("\nIl carattere --> %c è un carattere alfabetico", stringa[0]);
   if (isdigit(stringa[14]))
      printf("\nIl carattere --> %c è un numero", stringa[14]);
   if (islower(stringa[10]))
      printf("\nIl carattere --> %c è un carattere minuscolo", stringa[10]);
   ch = toupper(stringa[10]);
   printf("\nIl carattere  è trasformato in maiuscolo --> %c", ch);
   if (isupper(stringa[9]))
      printf("\nIl carattere --> %c è un carattere MAIUSCOLO", stringa[9]);
   ch = tolower(stringa[9]);
   printf("\nIl carattere  è trasformato in minuscolo --> %c", ch);
   if (ispunct(stringa[13]))
      printf("\nIl carattere --> %c è un carattere di punteggiatura", stringa[13]);
   if (isspace(stringa[8]))
      printf("\nIl carattere --> %c è uno spazio\n", stringa[8]);
   return 0;
}

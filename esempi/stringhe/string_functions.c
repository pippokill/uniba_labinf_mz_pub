#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 40

int main()
{

   char stringa1[LUNG] = "Mario Rossi";
   char stringa2[LUNG] = "Studente Matr.33965";
   char *punt = NULL;

   printf("\n\n\n******** PROGRAMMA DIMOSTRATIVO SULLE FUNZIONI PER LE STRINGHE *******\n");
   printf("Stringa 1 -->%s\n", stringa1);
   printf("Stringa 2 -->%s\n", stringa2);

   printf("\n\n******** strcpy (stringa1, stringa2)*******\n");
   strcpy(stringa1, stringa2);
   printf("Stringa 1 -->%s\n", stringa1);
   printf("Stringa 2 -->%s\n", stringa2);

   printf("\n\n******** strcmp (stringa1, stringa2)*******\n");
   if (strcmp(stringa1, stringa2) == 0)
      printf("Le due stringhe sono uguali\n");

   printf("\n\n******** strncpy (stringa1, stringa2, 5)*******\n");
   strcpy(stringa1, "Mario Rossi"); /* riportiamo il valore di stringa1 a Mario Rossi*/
   strncpy(stringa1, stringa2, 5);
   printf("Stringa 1 -->%s\n", stringa1); /* N.B. strncpy non aggiunge il carattere /0 e la stringa
                                             continua ad avere sempre lo stesso valore */
   printf("Stringa 2 -->%s\n", stringa2);
   stringa1[5] = '\0'; /* questa istruzione serve per aggiungere il carattere di fine stringa dopo i 5 copiati
                          dalla stringa2*/
   printf("Stringa 1 -->%s\n", stringa1);
   if (strcmp(stringa1, stringa2) == 0)
      printf("Le due stringhe sono uguali\n");
   else if (strcmp(stringa1, stringa2) < 0)
      printf("Stringa1 precede Stringa2\n");

   printf("\n******** strcmp (stringa2, stringa1)*******\n");
   if (strcmp(stringa1, stringa2) > 0)
      printf("Stringa2 segue Stringa1\n");

   printf("\n******** strncmp (stringa2, stringa1, 5)*******\n");
   if (strncmp(stringa2, stringa1, 5) == 0)
      printf("I primi 5 caratteri delle stringhe sono uguali\n\n");

   printf("\n******** strlen(stringa2)*******\n");
   printf("La stringa 2 ha %d caratteri \n\n", strlen(stringa2));

   printf("\n******** strtok(stringa2, \",\")*******\n");
   strcpy(stringa2, "Maria,Elena,Giovanni,Antonio,Ugo");
   punt = strtok(stringa2, ",");
   while (punt != NULL)
   {
      printf("Il token estratto  e' %s\n\n", punt);
      punt = strtok(NULL, ",");
   }
}
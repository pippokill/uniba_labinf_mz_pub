#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
     ordinato,
     in_consegna,
     non_ordinabile
} stato_libro_t;

typedef struct
{
     char autore[20];
     char titolo[50];
     char isbn[11];
     int disponibilita;
     stato_libro_t ordine;
} libro_t;

libro_t inserisci_dettagli();
void stampa_dettagli(libro_t *book);

int main()
{
     libro_t libro;
     printf("**********************************************************\n");
     printf("**                Inserisci i dati del libro            **\n");
     printf("**********************************************************\n");
     libro = inserisci_dettagli();
     printf("\n******************************************\n");
     printf("**    I dati del libro inseriti sono:   **\n");
     printf("******************************************\n");
     stampa_dettagli(&libro);
     return (0);
}

libro_t inserisci_dettagli()
{
     libro_t book;
     int stato;
     printf("\n      AUTORE   --> ");
     scanf("%s", book.autore);
     printf("\n      TITOLO   --> ");
     scanf("%s", book.titolo);
     printf("\n      ISBN   --> ");
     scanf("%s", book.isbn);
     printf("\n      NUMERO COPIE DISPONIBILI --> ");
     scanf("%d", &book.disponibilita);
     if (book.disponibilita == 0)
     {
          printf("\n\n      Inserire:\n      1 se il libro è ordinato,\n      2 se in consegna,\n      3 se non ordinabile\n");

          scanf("%d", &stato);
          switch (stato)
          {
          case 1:
               book.ordine = ordinato;
               break;
          case 2:
               book.ordine = in_consegna;
               break;
          case 3:
               book.ordine = non_ordinabile;
               break;
          default:
               break;
          }
     }
     return (book);
}

void stampa_dettagli(libro_t *book)
{
     printf("\n      AUTORE   --> %s", book->autore);
     printf("\n      TITOLO   --> %s", book->titolo);
     printf("\n      ISBN   --> %s", book->isbn);
     if (book->disponibilita != 0)
          printf("\n\n       DISPONIBILITA'  --> %d \n\n", book->disponibilita);
     else
          switch (book->ordine)
          {
          case ordinato:
               printf("\n\n       Il libro non è disponibile ma è stato ordinato\n\n");
               break;
          case in_consegna:
               printf("\n\n       Il libro non è disponibile ma è in consegna\n\n");
               break;
          case non_ordinabile:
               printf("\n\n       Il libro non è disponibile e non è ordinabile\n\n");
               break;
          default:
               break;
          }
}

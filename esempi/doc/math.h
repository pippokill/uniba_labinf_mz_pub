#include "math.c"

#ifndef MY_MATH

#define MY_MATH

/**
* @brief Somma due numeri interi passati come argomento alla funzione
* @param a Primo addendo
* @param b Secondo addendo
* @return Risultato della somma
*/
int somma(int a, int b);

/**
* @brief Effettua il prodotto di due numeri interi passati come argomento alla funzione
* @param a Primo operando
* @param b Secondo operando
* @return Risultato del prodotto
*/
int prodotto(int a, int b);

/**
* @brief Effetua il quadrato di un numero intero passato come argomento alla funzione
* @param a Numero intero di cui effettuare il quadrato
* @return Risultato del quadrato
*/
int quadrato(int a);

/**
* @brief Restituisce 1 se l'argomento della funzione è un numero intero dispari, altrimenti restituisce 0
* @param a Numero intero
* @return 1 se dispari, altrimenti 0
*/
int dispari(int a);

/**
* @brief Sottrae due numeri interi passati come argomento alla funzione
* @param a Minuendo (intero)
* @param b Sottraendo (intero)
* @return a-b
*/
int sottrazione(int a, int b);

/**
* @brief Effettua la divisione tra due numeri interi. Non viene fatto il controllo di divisore diverso da 0
* @param a Dividendo (intero)
* @param b Divisore (intero)
* @return a/b
*/
float divisione(int a, int b);

/**
* @brief Effetua il cubo di un numero intero passato come argomento alla funzione
* @param a Numero intero di cui effettuare il quadrato
* @return Risultato del cubo
*/
int cubo(int a);

/**
* @brief Restituisce 1 se l'argomento della funzione è un numero intero pari, altrimenti restituisce 0
* @param a Numero intero
* @return 1 se pari, altrimenti 0
*/
int pari(int a);

#endif

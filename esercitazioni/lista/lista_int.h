#include "lista_int.c"

#ifndef LISTA_INT_H
#define LISTA_INT_H

int isEmpty(const list l); // restituisce true se la lista è vuota altrimenti false​

list add(list l, int elem); // aggiunge un elemento in coda alla lista​

list addAt(list l, int i, int elem); // aggiunge un elemento in posizione i​

void set(list l, int i, int elem); // sostituisce l'elemento in posizione i​

list removeAt(list l, int i); // rimuovi l'elemento in posizione i​

int get(const list l, int i); // restituisce l'elemento in posizione i​

list clear(list l); // rimuove tutti gli elementi dalla lista​

int find(const list l, int elem); // restituisce la prima posizione nella quale si trova elem nella lista, altrimenti restituisce -1​

int size(const list l); // restituisce il numero di elementi nella lista

#endif
#include "lista_int.h"
#include <stdio.h>

void printList(list l)
{
    int s = size(l);
    printf("\n");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", get(l, i));
    }
    printf("\n");
}

int main()
{
    list l = NULL;
    printf("Is empty: %d\n", isEmpty(l));
    l = add(l, 10);
    l = add(l, 19);
    l = add(l, -4);
    l = add(l, 42);
    l = add(l, 0);
    l = addAt(l, 4, 21);
    printf("Is empty: %d\n", isEmpty(l));
    printf("Size: %d\n", size(l));
    printList(l);
    l = removeAt(l, 2);
    printList(l);
    l = removeAt(l, 0);
    printList(l);
    l = removeAt(l, 2);
    printList(l);
    l = add(l, -25);
    l = add(l, 104);
    l = add(l, -93);
    printList(l);
    printf("Find 104: %d\n", find(l, 104));
    set(l, 3, -104);
    printList(l);
    l = addAt(l, 0, -1);
    printList(l);
    l = clear(l);
    printf("Is empty: %d\n", isEmpty(l));
}
#include <stdlib.h>
#include <stdio.h>

#ifndef LISTA_INT_C
#define LISTA_INT_C

typedef struct list_item
{
    int elem;
    struct list_item *next;
} item;

typedef item *list;

item *at(list l, int i);

item *end(list l);

int size(list l);

item *at(list l, int i)
{
    int pos = -1;
    item *p = l;
    while (pos < i && p != NULL)
    {
        pos++;
        if (pos < i)
        {
            p = (*p).next;
        }
    }
    if (pos == i)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

item *end(list l)
{
    while ((*l).next != NULL)
    {
        l = (*l).next;
    }
    return l;
}

int isEmpty(const list l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

list add(list l, int elem)
{
    if (l == NULL) // list vuota
    {
        (l) = (item *)malloc(sizeof(item));
        (*l).next = NULL;
        (*l).elem = elem;
    }
    else
    {
        item *n = (item *)malloc(sizeof(item));
        (*n).next = NULL;
        (*n).elem = elem;
        item *e = end(l);
        (*e).next = n;
    }
    return l;
}

list addAt(list l, int i, int elem)
{
    if (i == 0)
    {
        item *n = (item *)malloc(sizeof(item));
        (*n).next = l;
        (*n).elem = elem;
        l = n;
    }
    else
    {
        item *p = at(l, i - 1);
        if (p == NULL)
        {
            printf("[WARNING] Out of bound %d.\n", i);
        }
        else
        {
            item *n = (item *)malloc(sizeof(item));
            (*n).next = (*p).next;
            (*n).elem = elem;
            (*p).next = n;
        }
    }
    return l;
}

int size(const list l)
{
    int size = 0;
    item *p = l;
    while (p != NULL)
    {
        size++;
        p = (*p).next;
    }
    return size;
}

int get(list l, int i)
{
    item *p = at(l, i);
    if (p == NULL)
    {
        printf("[WARNING] Out of bound %d.\n", i);
    }
    else
    {
        return (*p).elem;
    }
}

list removeAt(list l, int i)
{
    if (i == 0)
    {
        item *tmp = (*l).next;
        free(l);
        l = tmp;
    }
    else
    {
        item *p = at(l, i - 1);
        if (p == NULL)
        {
            printf("[WARNING] Out of bound %d.\n", i);
        }
        else
        {
            item *tmp = (*p).next;
            (*p).next = (*p).next->next;
            free(tmp);
        }
    }
    return l;
}

int find(list l, int elem)
{
    int s = size(l);
    for (int i = 0; i < s; i++)
    {
        if (get(l, i) == elem)
        {
            return i;
        }
    }
    return -1;
}

void set(list l, int i, int elem)
{
    item *p = at(l, i);
    if (p == NULL)
        printf("[WARNING] Out of bound %d.\n", i);
    else
        (*p).elem = elem;
}

list clear(list l)
{
    item *p = l;
    while (p != NULL && (*p).next != NULL)
    {
        item *tmp = (*p).next;
        p = (*tmp).next;
        free(tmp);
    }
    free(l);
    l = NULL;
    return l;
}

#endif
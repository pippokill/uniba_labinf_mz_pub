#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void stampa(int *ptr, int size);

void navigate_and_modify(int *start, int size);

void reverse_with_pointers(int *start, int size);

int main()
{
    int a[SIZE];
    int *a_ptr = a;
    int seed = time(NULL);
    srand(seed);
    for (int i = 0; i < SIZE; i++)
    {
        (*a_ptr) = rand() % (101);
        a_ptr++;
    }
    stampa(a, SIZE);
    navigate_and_modify(a, SIZE);
    stampa(a, SIZE);
    reverse_with_pointers(a, SIZE);
    stampa(a, SIZE);
}

void stampa(int *ptr, int size)
{
    printf("\nArray:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", *ptr);
        ptr++;
    }
    printf("\n");
}

void navigate_and_modify(int *start, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((*start) % 2 == 0)
        {
            (*start) = (*start) * 2;
        }
        else
        {
            (*start) = -(*start);
        }
        start++;
    }
}

void reverse_with_pointers(int *start, int size)
{
    int* end = (start + size - 1);
    int p = size / 2;
    for (int i = 0; i < p; i++)
    {
        int a = (*start);
        (*start) = (*end);
        (*end) = a;
        start++;
        end--;
    }
}
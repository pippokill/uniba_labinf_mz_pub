#include <stdio.h>

// prototipi
void function1(int a);
void function2(int b);
void function3(int c);

int main(void)
{
    // inizializza un array di 3 puntatori a funzioni che ricevono
    // ognuna un argomento int e restituiscono void
    void (*f[3])(int) = {function1, function2, function3};

    printf("%s", "Inserisci un numero da 0 a 2, 3 per uscire: ");
    int choice = 0;
    scanf("%d", &choice);

    // elabora la scelta dell'utente
    while (choice >= 0 && choice < 3)
    {
        // invoca la funzione alla locazione choice nell'array f e passa
        // choice come argomento
        (*f[choice])(choice);

        printf("%s", "Inserisci un numero da 0 a 2, 3 per uscire: ");
        scanf("%d", &choice);
    }
}

void function1(int a)
{
    printf("Hai inserito %d e ho chiamato la funzione function1\n\n", a);
}

void function2(int b)
{
    printf("Hai inserito %d e ho chiamato la funzione function2\n\n", b);
}

void function3(int c)
{
    printf("Hai inserito %d e ho chiamato la funzione function3\n\n", c);
}
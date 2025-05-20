#include <stdio.h>
#include <stdlib.h>

// programma che esegue operazioni aritmetiche su due operandi interi

// prototipi
int esegui_operazione(int op1, int op2, int (*operazione)(int a, int b)); // punt. a funzione che implementa l'operazione
int somma(int a, int b);
int prodotto(int a, int b);
// funzione per la lettura degli operandi
void leggi_operandi(int ops[], int n);

void main()
{
    int o = -1;
    do
    {
        printf("\nChe operazione vuoi eseguire?\n");
        printf("1. Somma\n");
        printf("2. Prodotto\n");
        printf("3. Esci\n");
        printf("Scelta? ");
        scanf("%d", &o);
        int op2[2] = {0};
        switch (o)
        {
        case 1:
            leggi_operandi(op2, 2);
            printf("Risultato: %d\n", esegui_operazione(op2[0], op2[1], somma));
            break;
        case 2:
            leggi_operandi(op2, 2);
            printf("Risultato: %d\n", esegui_operazione(op2[0], op2[1], prodotto));
        case 3:
            break;
        default:
            o = -1;
            break;
        }
    } while (o != 3);
}

void leggi_operandi(int ops[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Inserisci operando %d: ", i + 1);
        scanf("%d", &ops[i]);
    }
}

int esegui_operazione(int op1, int op2, int (*operazione)(int a, int b))
{
    return operazione(op1, op2);
}

int somma(int a, int b)
{
    return a + b;
}

int prodotto(int a, int b)
{
    return a * b;
}

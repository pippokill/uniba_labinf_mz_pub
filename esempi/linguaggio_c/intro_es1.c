#include <stdio.h>

int main()
{
    int age = 0;
    printf("Inserisci la tua età: ");
    scanf("%d", &age);
    if (age < 0)
    {
        printf("valore non valido\n");
    }
    else if (age < 18)
    {
        printf("utente minorenne\n");
    }
    else if (age > 146)
    {
        printf("valore non valido\n");
    }
}
#include <stdio.h>
#include <string.h>

int main() {
    char string[]="prova_stringa";

    // Trova la prima occorrenza della stringa e restituisce la parte rimanente
    printf("Parte rimanente dopo la s: %s\n", strchr(string, 's'));

    // Restituisce il numero di caratteri prima della prima occorrenza di quel carattere
    printf("Lunghezza della stringa prima della s %d\n", strcspn(string, "s"));

    int lenght = strlen(string);
    printf("%d\n", lenght);

}
#include <stdio.h>

#define LENGTH 10

int main() {
    char string[LENGTH];
    printf("Inserisci una stringa: ");
    scanf("%s", string);
    // limitare la lunghezza dell'input poiché il C non effettua controlli sulla lunghezza dell'array
    //scanf("%9s", string);
    printf("String letta: ");
    puts(string);
}
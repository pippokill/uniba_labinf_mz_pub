#include <stdio.h>

int main()
{
    int a = 5;
    float b = 3.0;

    int *aPtr;
    float *bPtr;

    //aPtr = a;  // errore
    aPtr = &a; // OK
    bPtr = &b; // OK

    printf("\n a: %d \t &a: %X", a, aPtr);
    printf("\n b: %.2f \t &b: %X\n", b, bPtr);
}
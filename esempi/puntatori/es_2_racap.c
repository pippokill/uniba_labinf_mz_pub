#include <stdio.h>

int main()
{
    int a = 5;
    float b = 3.0;

    int *aPtr;
    float *bPtr;

    aPtr = &a; // OK
    bPtr = &b; // OK

    printf("\n Valore di a: %d\tIndirizzo di a: %X", a, aPtr);
    printf("\n Valore di b: %.2f\tIndirizzo di b: %X", b, bPtr);

    printf("\n Valore di aPtr: %X\tIndirezione di aPtr: %d", aPtr, *aPtr);
    printf("\n Valore di bPtr: %X\tIndirezione di bPtr: %.2f\n", bPtr, *bPtr);
}
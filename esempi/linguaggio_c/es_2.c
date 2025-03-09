#include <stdio.h>

int main(void)
{
    char charVariable;
    unsigned char unsignedCharVariable;
    short shortVariable;
    unsigned short unsignedShortVariable;
    int integerVariable;
    unsigned int unsignedIntVariable;
    long longVariable;
    unsigned long unsignedLongVariable;
    float floatVariable;
    double doubleVariable;
    long double longDoubleVariable;

    printf("Size of char: %u \n", sizeof(charVariable));
    printf("Size of unsigned char: %u \n", sizeof(unsignedCharVariable));
    printf("Size of short: %u \n", sizeof(shortVariable));
    printf("Size of unsigned short: %u \n", sizeof(unsignedShortVariable));
    printf("Size of integer: %u \n", sizeof(integerVariable));
    printf("Size of unsigned integer: %u \n", sizeof(unsignedIntVariable));
    printf("Size of long: %u \n", sizeof(longVariable));
    printf("Size of unsigned long: %u \n", sizeof(unsignedLongVariable));
    printf("Size of float: %u \n", sizeof(floatVariable));
    printf("Size of double: %u \n", sizeof(doubleVariable));
    printf("Size of long double: %u \n", sizeof(longDoubleVariable));
}
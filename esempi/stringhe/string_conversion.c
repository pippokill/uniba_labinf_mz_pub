#include <stdlib.h>
#include <stdio.h>

int main()
{
    double d;
    d = atof("99.0");
    printf("The string 99.0 converted in double is %.3f\nThe converted value divided by 2 is %.3f\n", d, d / 2.0);
}
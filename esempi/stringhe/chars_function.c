#include <stdio.h>
#include <ctype.h>

int main()
{
    char a = 'a';
    char up = 'A';
    char n = '1';
    char s = '#';

    // isalpha
    if (isalpha(a))
        printf("\n%c is alphabetic", a);
    else
        printf("\n%c is not alphabetic", a);
    if (isalpha(n))
        printf("\n%c is alphabetic", n);
    else
        printf("\n%c is not alphabetic", n);

    // isalnum
    if (isalnum(a))
        printf("\n%c is alpha-numeric", a);
    else
        printf("\n%c is not alpha-numeric", a);
    if (isalnum(n))
        printf("\n%c is alpha-numeric", n);
    else
        printf("\n%c is not alpha-numeric", n);
    if (isalnum(s))
        printf("\n%c is alpha-numeric", s);
    else
        printf("\n%c is not alpha-numeric", s);

    // islower
    if (islower(a))
        printf("\n%c is lower-case", a);
    else
        printf("\n%c is not lower-case", a);
    if (islower(up))
        printf("\n%c is lower-case", up);
    else
        printf("\n%c is not lower-case", up);

    printf("\n%c to upper-case: %c\n", a, toupper(a));
}
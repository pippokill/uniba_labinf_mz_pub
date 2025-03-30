#ifndef MY_MATH_IMPL

#define MY_MATH_IMPL

int somma(int a, int b)
{
    return a + b;
}

int prodotto(int a, int b)
{
    return a * b;
}

int quadrato(int a)
{
    return a * a;
}
int dispari(int a)
{
    if (a % 2 == 0)
        return 0;
    else
        return 1;
}

int sottrazione(int a, int b)
{
    return a - b;
}

float divisione(int a, int b)
{
    return a / b;
}

int cubo(int a)
{
    return a * a * a;
}

int pari(int a)
{
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}

#endif

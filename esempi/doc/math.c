#ifndef MY_MATH_IMPL

#define MY_MATH_IMPL

/**
* @brief Somma tra due numeri
* @param a 
* @param b 
* @return Pre-cond: Nessuna, Post-cond: a+b
*/
int somma(int a, int b)
{
    return a + b;
}

/**
* @brief Prodotto tra due numeri
* @param a 
* @param b 
* @return Pre-cond: Nessuna, Post-cond: a*b
*/
int prodotto(int a, int b)
{
    return a * b;
}

/**
* @brief Quadrato di un numero
* @param a 
* @return Pre-cond: Nessuna, Post-cond: a*a
*/
int quadrato(int a)
{
    return a * a;
}

/**
* @brief Dispari
* @param a 
* @return Pre-cond: Nessuna, Post-cond: 1 se a dispari, altrimenti 0
*/
int dispari(int a)
{
    if (a % 2 == 0)
        return 0;
    else
        return 1;
}

/**
* @brief Sottrazione
* @param a 
* @param b 
* @return Pre-cond: Nessuna, Post-cond: a-b
*/
int sottrazione(int a, int b)
{
    return a - b;
}

/**
* @brief Divisione. Non viene effettuato il controllo sul divisore diverso da 0.
* @param a 
* @param b 
* @return Pre-cond: b diverso da 0, Post-cond: a/b
*/
float divisione(int a, int b)
{
    return a / b;
}

/**
* @brief Cubo
* @param a 
* @return Pre-cond: Nessuna, Post-cond: a*a*a
*/
int cubo(int a)
{
    return a * a * a;
}

/**
* @brief Pari
* @param a 
* @return Pre-cond: Nessuna, Post-cond: 1 se a pari, altrimenti 0
*/
int pari(int a)
{
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}

#endif

 #include <stdio.h>

 int main() {
    int array[10];
    int* p_array;
    p_array=&array[0];

    printf("Nome dell'array:\t%X\n", array);
    printf("Indirizzo del primo elemento:\t%X\n", &array[0]);
    printf("Puntatore all'array:\t%X\n", p_array);
 }
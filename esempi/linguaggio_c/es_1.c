#include <stdio.h>

int main()

{
    int integer1;
    int integer2;
    int sum;
    printf("Enter value : ");
    scanf("%d", &integer1);
    printf("Enter value : ");
    scanf("%d", &integer2);
    sum = integer1 + integer2;
    printf("Sum : % d\n", sum);
    return 0;
}
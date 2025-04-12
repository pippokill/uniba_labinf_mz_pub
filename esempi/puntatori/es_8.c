#include <stdio.h>

int main()
{
    unsigned int i;
    int a[5] = {1, 2, 3, 4, 5};
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", *(a+i));
    }
    printf("\n");
    double f[5]={0.4534, 0.7632, 0.1243, 0.5632,0.54};
    for (i = 0; i < 5; i++)
    {
        printf("%.4f\t", *(f+i));
    }
    printf("\n");
    void* ptrF=&f[0];
    printf("\n");
    printf("\n%d\n", sizeof(double));
    printf("\n%X\n", f);
    printf("\n%X\n", &f[4]);
    double* address=ptrF+4*sizeof(double);
    printf("%.4f\t", *address);
    printf("\n");
}
/*
7) Modifique o programa anterior para imprimir os números em ordem crescente.
*/

#include <stdio.h>

int main ()
{
    int n1, n2, n3;

    printf("Forneca 3 numeros inteiros diferentes: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 < n2 && n2 < n3)
    {
        printf("A ordem crescente e: %d %d %d", n1, n2, n3);
    }
    if (n1 < n3 && n3 < n2)
    {
        printf("A ordem crescente e: %d %d %d", n1, n3, n2);
    }
    if (n2 < n1 && n1 < n3)
    {
        printf("A ordem crescente e: %d %d %d", n2, n1, n3);
    }
    if (n2 < n3 && n3 < n1)
    {
        printf("A ordem crescente e: %d %d %d", n2, n3, n1);
    }
    if (n3 < n1 && n1 < n2)
    {
        printf("A ordem crescente e: %d %d %d", n3, n1, n2);
    }
    if (n3 < n2 && n2 < n1)
    {
        printf("A ordem crescente e: %d %d %d", n3, n2, n1);
    }

    return 0;
}

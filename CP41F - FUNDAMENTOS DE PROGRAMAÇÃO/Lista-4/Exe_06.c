/*
6) Escreva um programa que receba três números e determina qual é o maior
*/

#include <stdio.h>

int main ()
{
    int n1, n2, n3;

    printf("Forneca 3 numeros inteiros: ");
    scanf("%d %d %d", &n1, &n2, &n3);


    if (n3 >= n2 && n3 >= n1)
    {
        printf("O numero maior: %d", n3);
    }
    else
    {
        if (n2 >= n1 && n2 >= n3)
        {
            printf("O numero maior: %d", n2);
        }
        else
        {
            printf("O numero maior: %d", n1);
        }
    }

    return 0;
}

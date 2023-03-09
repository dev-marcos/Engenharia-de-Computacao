/*
4) Escreva um programa que receba três valores ponto flutuante de precisão dupla (a, b,
c) e responda se a soma “a+b” é igual a “c”. Teste com a = 0,1 , b = 0,2 e c = 0,3.
*/

#include <stdio.h>
#include <math.h>

int fequal(double a, double b)
{
    //a funcao fabs é correspondnete ao módulo do valor
    return fabs(a-b) < 0.000000001;
}

int main ()
{
    double a=2.4, b=0.00, c=0.00;

    printf("Informe 3 numeros: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (fequal((a+b),c))
    {
        printf("A soma de a+b e igual a C!");
    }
    else
    {
        printf("A soma de a+b e diferente de C!");
    }
    return 0;
}

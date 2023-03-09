/*
5) Crie um programa que receba o tamanho de tr�s lados de um tri�ngulo e determine se
as entradas representam um tri�ngulo equil�tero, escaleno ou is�sceles.
*/

/*
Equilatero: 3 lados iguaos;
Escaleno: nenhum lado igual
Isoscele: 2 lados iguais;

*/

#include <stdio.h>

int main (){
    int a=0, b=0, c=0;

    printf("Forneca os 3 lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);

    if((a==b) && (a==c) && (b==c))
    {
        printf("Triangulo equilatero!");
    }
    else
    {
        if((a==b) || (a==c) || (b==c))
        {
            printf("Triangulo isosceles!");
        }
        else
        {
            printf("Triangulo escaleno!");
        }
    }
    return 0;
}

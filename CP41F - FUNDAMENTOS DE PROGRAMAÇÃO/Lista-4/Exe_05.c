/*
5) Crie um programa que receba o tamanho de três lados de um triângulo e determine se
as entradas representam um triângulo equilátero, escaleno ou isósceles.
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

/*
9) Faça um programa que imprima uma árvore de Natal, considerando uma altura
especificada pelo usuário. Para h=3:
 I
*I*
**I**
*/

#include <stdio.h>

int main(){

    int altura = 0;

    printf("Qual a altura da arvore? ");
    scanf ("%d", &altura);

    int i, j;

    for(i=0; i <= altura; i++){

        for (j = 0; j < altura-i; j++)
            printf(" ");

        for (j = 0; j < i; j++)
            printf("*");

        printf("I");

        for (j = 0; j < i; j++)
            printf("*");

        printf("\n");
    }
}


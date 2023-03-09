/*
 * 13) Escreva um programa que aceite como entrada um valor em uma base e imprima em outra:
 *  b) Octal para decimal
*/

#include <stdio.h>

int main()
{
    unsigned char a = 0;
    printf("Insira o valor em Octal:");
    scanf("%o", &a);
    printf("Em decimal: %d", a);
}


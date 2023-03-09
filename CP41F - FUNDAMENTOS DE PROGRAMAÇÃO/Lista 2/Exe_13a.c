/*
 * 13) Escreva um programa que aceite como entrada um valor em uma base e imprima em outra:
 *  a) Hexadecimal para decimal
*/

#include <stdio.h>

int main()
{
    unsigned char a = 0;
    printf("Insira o valor em Hexadecimal:");
    scanf("%X", &a);
    printf("Em decimal: %d", a);
}


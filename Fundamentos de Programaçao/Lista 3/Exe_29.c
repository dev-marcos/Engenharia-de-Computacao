/*

29)	Escreva um programa que receba um valor inteiro e imprima seu
resultado em binário, utilizando apenas operadores binários.

*/

#include <stdio.h>
//10100

int main()
{
    unsigned int dec, b1, b2, b3, b4, b5, b6, b7, b8;

    printf("Insira um numero decimal (entre 0 e 255):");
    scanf("%d", &dec);
    b1 = dec & 1;
    b2 = (dec >> 1) & 1;
    b3 = (dec >> 2) & 1;
    b4 = (dec >> 3) & 1;
    b5 = (dec >> 4) & 1;
    b6 = (dec >> 5) & 1;
    b7 = (dec >> 6) & 1;
    b8 = (dec >> 7) & 1;

    printf("Seu numero binario: %d%d%d%d %d%d%d%d", b8, b7, b6, b5, b4, b3, b2, b1);


    return 0;
}

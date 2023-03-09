/*
 * 17)	Escreva um programa que receba oito digitos binários (0 ou 1),
 * representando um valor binário de oito bits, e escreva o valor
 * correspondente em decimal, octal e hexadecimal.
 *
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int decimal = 0;
    char binario[8];
    printf("Insira o valor binario(bit a bit):");

    scanf("%d %d %d %d %d %d %d %d", &binario[0], &binario[1], &binario[2],
          &binario[3], &binario[4], &binario[5], &binario[6],&binario[7]);

    decimal = decimal + 1 * binario[7];
    decimal = decimal + 2 * binario[6];
    decimal = decimal + 4 * binario[5];
    decimal = decimal + 8 * binario[4];
    decimal = decimal + 16 * binario[3];
    decimal = decimal + 32 * binario[2];
    decimal = decimal + 64 * binario[1];
    decimal = decimal + 128 * binario[0];


    printf("Decimal: %d\n", decimal);
    printf("Octal: %o\n", decimal);
    printf("Hexadecimal: %x\n", decimal);
    return 0;



}


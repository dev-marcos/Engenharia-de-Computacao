/*
2) Faça um programa que calcule e escreva a quantidade de grãos de milho que se pode
colocar num tabuleiro de xadrez, conforme regra definida no quadro abaixo:
1 2 4 8 16 32 ...
Calcule a quantidade de grãos em cada quadro do tabuleiro e também o somatório total.

*/


#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long int casa[84];
    unsigned long long int total=0;
    int i=0;
    for (i=0; i<64; i++){
        casa[i] = pow(2, i);
        total += casa[i];
        printf("Casa: %d -> Valor: %llu\n", i+1, casa[i]);
    }
    printf("Total: %llu\n", total);
}

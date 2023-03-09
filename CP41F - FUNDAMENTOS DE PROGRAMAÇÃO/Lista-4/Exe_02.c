/*
2) Suponha que um caixa automático disponha apenas de notas de 1, 10 e 50 reais.
Considerando que alguém está fazendo um saque, implemente um programa que mostre
o número mínimo de notas que o caixa deve entregar ao cliente. Exemplo:
Qual o valor do saque?
72
Você receberá
1 nota(s) de R$ 50,00
2 nota(s) de R$ 10,00
2 nota(s) de R$ 1,00
*/

#include <stdio.h>

int main()
{
    int saque=0;
    int n50=0;
    int n10=0;
    int n1=0;

    printf("Qual o valor do saque?\n");
    scanf("%d", &saque);

    n50 = saque/50;
    n10 = (saque-(n50*50))/10;
    n1  = (saque-(n50*50) - (n10*10));

    printf("Notas de 50: %d\n", n50);
    printf("Notas de 10: %d\n", n10);
    printf("Notas de 1:  %d\n", n1);
}

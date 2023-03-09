/*
3) Faça um programa que leia um valor inteiro de até 4 algarismos e calcule a soma dos
algarismos desse número. Caso o valor informado seja maior que 4 algarismos, emita
um erro. Exemplo:
Informe um número:
3267
Soma dos algarismos do número:
18
*/

#include <stdio.h>

int main (){

    int numero = 0;
    int n1=0, n2=0, n3=0, n4=0;

    printf("Forneca um numero inteiro de 4 algarismo: ");
    scanf("%d", &numero);

    if (numero > 9999){
        printf("Tamanho acima do permitido!");
    }else{
        n1 = numero / 1000;
        n2 = numero / 100;
        n3 = numero / 10;
        n4 = numero;

 /*   char str[100];
int a = 255;
int i;

sprintf(str,"%d",a);

for(i=0;i<strlen(str);++i)
 printf("%c ",str[i]);

*/
1234
1234
1234/10
1230
4




    }

    return 0;
}

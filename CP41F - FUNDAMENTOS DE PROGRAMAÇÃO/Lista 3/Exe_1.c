/*
1) Qual o valor de “char a = 1200”? Qual o nome do erro que leva a esse
comportamento?
*/


#include <stdio.h>


/*

1200 = 0100 1011 0000
char =      0000 0000
176  = 0000 1011 0000
sinal=      1

signed char: -127 a 127


*/

int main()
{
    char a = 1200;
    printf("%d", a);
    return 0;
}

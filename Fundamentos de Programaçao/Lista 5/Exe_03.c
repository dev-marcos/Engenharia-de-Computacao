/*
3) Fazer um programa para calcular o n�mero de dias decorridos entre duas datas
(considerar tamb�m a ocorr�ncia de anos bissextos e o n�mero correto de dias de cada
m�s).
*/


#include <stdio.h>

int validaData(char data[10])
{
    int dia, int mes, int ano

    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
    {
        if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
        {
            return 1;
        }
        if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
        {
            return 1;
        }
        if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
        {
            return 1;
        }
        if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
        {
            return 1;
        }
        elsevalidaData
        {
            return 0;
        }
    }else{
        return 0;
    }
}




int main()
{


    char dtInicial[10];
    char dtFinal[10];

    do
    {
        printf("Informe a primeira data (dd/mm/aaaa): ");
        scanf("%s", &dtInicial);

    } while (!validaData(dtInicial));

    do
    {
       printf("Informe a segunda data (dd/mm/aaaa): ");
        scanf("%s", &dtFinal);

    } while (!validaData(dtFinal));



    printf("%s", dtInicial);









}


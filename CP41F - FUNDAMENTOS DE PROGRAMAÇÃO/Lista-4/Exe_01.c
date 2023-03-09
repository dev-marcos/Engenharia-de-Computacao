/*
1) Implemente um programa para uma revendedora de carros que calcule o salário de
cada vendedor. Considere que todos os carros têm o mesmo valor, e que a revendedora
paga:
a) um salário fixo de dois salários mínimos a seus vendedores
b) uma comissão fixa de R$ 50,00 por carro que for vendido
c) caso o vendedor tenha vendido mais de 10 carros, uma comissão variável de 5% do
valor total de suas vendas.
*/

#include <stdio.h>

int main ()
{

    int    carros_vendidos   = 0;
    double valor_carro       = 50000.00;
    double comissao_fixa     = 0.00;
    double comissao_variavel = 0.00;
    double salario_final     = 0.00;
    double salario_base      = 0.00;
    double salario_minimo    = 1000.00;

    printf("Quantos carros o vendedor vendeu? ");
    scanf("%d", &carros_vendidos);

    if (carros_vendidos > 10)
    {
        comissao_variavel =  (valor_carro * carros_vendidos * 0.05);
    }

    comissao_fixa = (carros_vendidos * 50.00);
    salario_base  = (salario_minimo * 2);
    salario_final = (salario_base + comissao_variavel + comissao_fixa);

    printf("Salario do vendedor: %0.2f\n", salario_final);


    return 0;
}

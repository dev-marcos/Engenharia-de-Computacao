#include <stdio.h>
#include <stdlib.h>


int procuraMaior(int *v, int N){
    int maior=0, i=1;

    while (v[maior] < v[i] && i<N){
        maior = i;
        i++;
    }
    return maior;
}

int procuraNumero(int *v, int num, int N){

    int maior = procuraMaior(v, N);

    int ini1 = 0;
    int fim1 = maior;
    int meio1;
    int ini2 = maior+1;
    int fim2 = N;
    int meio2;
    while (ini1 <= fim1 || ini2 <= fim2){
        meio1 = (ini1 + fim1)/2;
        meio2 = (ini2 + fim2)/2;

        if (num == v[meio1])
           return meio1;

        if (num == v[meio2])
           return meio2;

        if (num < v[meio1])
           fim1 = meio1-1;
        else
           ini1 = meio1+1;

        if (num > v[meio2])
           fim2 = meio2-1;
        else
           ini2 = meio2+1;
    }
    return -1;
}

int main()
{
    int N,*v, i, num;
    printf("Tamanho do vetor> ");
    scanf("%d",&N);

    v = (int *)malloc(N*sizeof(int));

    printf("Vetor> ");
    for (i=0; i<N; i++){
        scanf("%d", &v[i]);
    }

    printf("Posicao M = %d\n", procuraMaior(v, N));

    printf("Valor a buscar> ");
    scanf("%d",&num);

    if(procuraNumero(v, num, N)>=0)
        printf("%d esta no vetor dado\n", num);
    else
        printf("%d nao esta no vetor dado\n", num);


    return 0;
}

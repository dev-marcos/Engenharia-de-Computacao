/* PROGRAMA PARA A QUESTAO 6 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void troca(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void gera(int *v, int *w, int N) {
    int i;
    for (i=0;i<N;i++)
        v[i] = w[i] = rand()%1000000 + 1;
}

void selectionSort(int *v, int N) {
/* Baseada no pseudocodigo da Aula 8*/

    int i, pos_memor, j;
    for (i=0; i<(N-1);i++){
        pos_memor=i;
        for (j=(i+1); j<N; j++){
            if (v[j] < v[pos_memor])
                pos_memor = j;
        }
        troca(&v[i], &v[pos_memor]);
    }
}


void mergeSort(int *v, int ini, int fim) {
/* Baseada no pseudocodigo da Aula 9 */
    if (ini < fim){
        int metade = (fim+ini)/2; //Seja v=[A/B]
        mergeSort(v, ini, metade);
        mergeSort(v, metade+1, fim);

        int i = ini, j = metade+1, k = 0, *vAux;

        vAux = (int *)malloc((fim-ini+1)*sizeof(int));

        while(i <= metade && j <= fim){
            if(v[i] < v[j]) {
                vAux[k] = v[i];
                i++;
            } else {
                vAux[k] = v[j];
                j++;
            }
            k++;
        }

        while(i <= metade){ //Insira o resto de A(Se houver)
            vAux[k] = v[i];
            k++;
            i++;
        }

        while(j <= fim) { //Insira o resto de B(Se houver)
            vAux[k] = v[j];
            k++;
            j++;
        }

        for(k = ini; k <= fim; k++){
            v[k] = vAux[k-ini];
        }
        free(vAux);
    }
}

int main() {
    int *v, *w;
    int tam[2] = {50000, 100000}, i, N;
    double comeco, fim, tempo[2][2];
    srand(time(NULL));
    for (i=0;i<2;i++) {
        N = tam[i];
        v = (int *)malloc(N*sizeof(int));
        w = (int *)malloc(N*sizeof(int));
        gera(v, w, N);
        comeco = ((double)clock())/CLOCKS_PER_SEC;
        selectionSort(v, N);
        fim = ((double)clock())/CLOCKS_PER_SEC;
        tempo[i][0] = fim - comeco;

        printf("N = %d, selectionSort: %.4lf segundos\n", N, tempo[i][0]);
        comeco = ((double)clock())/CLOCKS_PER_SEC;
        mergeSort(w, 0, N-1);
        fim = ((double)clock())/CLOCKS_PER_SEC;
        tempo[i][1] = fim - comeco;

        printf("N = %d, mergeSort: %.4lf segundos\n\n", N, tempo[i][1]);
        free(v);
        free(w);
    }
    printf("Taxa selectionSort: %.2lf vezes\n", tempo[1][0]/tempo[0][0]);
    printf("Taxa mergeSort: %.2lf vezes\n\n", tempo[1][1]/tempo[0][1]);
    printf("[RESPOSTA ITEM C] \n");
    printf("Atraves da analise de complexidade de algoritmos, e possivel \n");
    printf("determinar que o metodo de ordenacao Selection Sort possui \n");
    printf("Teta de O(N^2) em sua complexidade de tempo o que mostra que \n");
    printf("conforme a entrada aumenta o seu tempo ira crescer de forma \n");
    printf("exponencial (quadratica). Enquanto o algoritmo Merge Sorte possui \n");
    printf("Teta de O(N lg(N)) crescendo de forma logaritmica vezes N. Dessa forma\n");
    printf("e possivel concluir que MergeSort e melhor do que SelectionSort\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Head{
    uint8_t tamanho;
    bool bit[32];
} Head;


typedef struct No{
    char c;
    struct No *esquerda;
    struct No *direita;
} No;

void freeTree(No *no){

    if (no){
        freeTree(no->esquerda);
        freeTree(no->direita);
        free(no);
    }else
        return;
}


void Descomprimir(const char *entrada, const char *saida){

    FILE *fEntrada = fopen(entrada, "rb");
    if(fEntrada == NULL){
        printf("O sistema nao pode encontrar o arquivo especificado.\n\n");
        exit(1);
    }

    FILE *fSaida   = fopen(saida,   "w");
    if(fSaida == NULL){
        printf("O sistema nao pode armazenar no destino especificado.\n\n");
        exit(1);
    }

    //Cria um cabe�ario para armazenar os codigos utilizado pela codificacao
    Head head[29];

    //Cria a arvore de Huffman
    No *Raiz;
    Raiz=(No *)malloc(sizeof (No));
    Raiz->direita=NULL;
    Raiz->esquerda=NULL;
    Raiz->c=0;

    // Faz a mesma coisa para os 29 blocos
    for (int i=0; i<29; i++){

        // Le o 1 byte que cotem o tamanho do codigo
        fread (&head[i].tamanho, sizeof(uint8_t), 1, fEntrada);

        // La�o para ler os 4 bytes que contem o c�digo em si
        for (int j=0; j<4; j++){
            uint8_t byte;
            fread (&byte, sizeof(uint8_t), 1, fEntrada);

            // La�o para converter o bloco lido em bin�rio no cabe�ario
            // Ele armazena j� de forma invertida, pois o medoto de convers�o
            // por meio do mod e div � mais facil.
            for(int k=8; k>0; k--){
                head[i].bit[(j*8)+(k-1)]=byte%2;
                byte=byte/2;
            }
        }
        if (i<=25)
            printf("%c: ",i+97);
        if (i==26)
            printf("%c: ",32);
        if (i==27)
            printf("\\n: ");
        if (i==28)
            printf("EOF: ");

        //Aqui preciso montar o arvore
        No *novo;
        //printf("%x \n", Raiz);
        //printf("%x \n", novo);

        novo = Raiz;
        //printf("%x \n", novo);
        for(int altura=0; altura<head[i].tamanho; altura++){
            printf("%d",head[i].bit[altura]);
            if (head[i].bit[altura]){
                //direta

                if (novo->direita != NULL){

                    novo = novo->direita;

                }else{
                    No *aux;
                    aux=(No *)malloc(sizeof (No));
                    aux->direita=NULL;
                    aux->esquerda=NULL;
                    aux->c=0;
                    novo->direita = aux;
                    novo = novo->direita;
                }
           }else{
            //esquerda
                if (novo->esquerda != NULL){
                    novo = novo->esquerda;
                }else{
                    No *aux;
                    aux=(No *)malloc(sizeof (No));
                    aux->direita=NULL;
                    aux->esquerda=NULL;
                    aux->c=0;
                    novo->esquerda = aux;
                    novo = novo->esquerda;
                }
           }
       }
       if (i<=25)
            novo->c = (i+97);
        if (i==26)
            novo->c = 32;
        if (i==27)
            novo->c = 10;
        if (i==28)
            novo->c = -1;

       printf("\n");
    }

    uint8_t byte;


    No *novo;
    novo = Raiz;

    bool eof = true;
    int a[8];

    while (fread (&byte, sizeof(uint8_t), 1, fEntrada) == 1 && eof ) {

        for(int i=8; i>0; i--){
            a[i-1]=byte%2;
            byte=byte/2;
        }

        for(int i=0; i<8; i++){
            if(novo->c != 0){
                if (novo->c != EOF)
                    fwrite(&novo->c,  sizeof(char), 1, fSaida);
                else
                    eof = false;

                novo = Raiz;
            }

            if(a[i])
                novo = novo->direita;
            else
                novo = novo->esquerda;
        }
    }

    //freeTree(Raiz);

    fclose(fEntrada);
    fclose(fSaida);
}

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("A sintaxe do comando esta incorreta.\n\n");
        printf("descompacta [origem] [destino].\n\n");
        printf("origem\tEspecifica o arquivo compactado.\n");
        printf("destino\tEspecifica o nome do novo arquivo gerado.\n\n");
        return 0;
    }
    Descomprimir(argv[1], argv[2]);
    //Descomprimir("faroeste.hzip","faroeste.txt");
    return 0;
}

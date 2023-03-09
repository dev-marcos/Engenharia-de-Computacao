#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void decodifica(No * Raiz, FILE * fEntrada, FILE * fSaida){
    
}

void Descomprimir(const char *entrada, const char *saida){

    FILE *fEntrada = fopen("pessoas.dat", "r+b");
    if(fEntrada == NULL){
        printf("O sistema nao pode encontrar o arquivo especificado.\n\n");
        exit(1);
    }

    FILE *fSaida   = fopen(saida,   "wb");
    if(fSaida == NULL){
        printf("O sistema nao pode armazenar no destino especificado.\n\n");
        exit(1);
    }

    //criei uma estrutura para armazenar o header que vem do arquivo de entrada,
    //achei que assim, seria uma solucao mais simples para resolver o exercicio
    Head head[29];
    
    // Antes de transformar tudo em funcao, o geraHeader, printHeader e geraArvore, rodavam
    // dentro do mesmos for. Entretanto, mudei para ficar mais facil a compreensao

    //Le o arquivo de entrada e armazena os codigos na variavel do head
    gerarHeader(&head[0], fEntrada);

    //imprime o conteudo do head conforme o enunciado que foi passado
    printHead(&head[0]);

    //gera a Arvore de Huffman com os codigos do head
    No *Raiz = geraArvore(&head[0]);

    //Gera o arquivo de saida
    decodifica(Raiz, fEntrada, fSaida);

    //Esvazia a raiz da memoria
    freeTree(Raiz);

    //fecha os arquivos
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

    return 0;
}

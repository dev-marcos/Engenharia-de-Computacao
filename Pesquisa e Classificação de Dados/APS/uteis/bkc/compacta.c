#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include<math.h>
//#include<malloc.h>

typedef struct No{
    char data ;
    int frequencia;
    struct No *esquerda;
    struct No *direita;
} No ;

typedef struct Head{
    uint8_t tamanho;
    bool bit[32];
} Head;


typedef struct nodeLista
{
    No          *n;
    struct nodeLista    *proximo;
} nodeLista;

typedef struct lista
{
    nodeLista   *head;
    int         elementos;
} lista;


nodeLista *novoNodeLista(No *nArv){

    nodeLista *novo;
    if ( (novo = malloc(sizeof(*novo))) == NULL )
        return NULL;

    novo->n = nArv;

    novo->proximo = NULL;

    return novo;
}

No *novoNo(char c, int frequencia, No *esquerda, No *direita){

    No *novo;

    if ( ( novo = malloc(sizeof(*novo)) ) == NULL ) return NULL;


    novo->data = c;
    novo->frequencia = frequencia;
    novo->esquerda = esquerda;
    novo->direita = direita;

    return novo;
}

void insereLista(nodeLista *n, lista *l){
    if (!l->head){
        l->head = n;
    }


    else if (n->n->frequencia < l->head->n->frequencia){
        n->proximo = l->head;
        l->head = n;
    }else{

        nodeLista *aux = l->head->proximo;

        nodeLista *aux2 = l->head;

        while (aux && aux->n->frequencia <= n->n->frequencia){
            aux2 = aux;
            aux = aux2->proximo;
        }
        aux2->proximo = n;
        n->proximo = aux;
    }
    l->elementos++;
}

No *popMinLista(lista *l){
    nodeLista *aux = l->head;
    No *aux2 = aux->n;
    l->head = aux->proximo;
    free(aux);
    aux = NULL;
    l->elementos--;

    return aux2;
}


#define COUNT 5
void print2DUtil(No *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->direita, space);

    // Print current node after space
    // count
    //printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->frequencia);

    // Process left child
    print2DUtil(root->esquerda, space);
}


bool pegaCodigo(No *n, char c, char *buffer, uint8_t tamanho)
{

    // Caso base da recurs�o:
    // Se o n� for folha e o seu valor for o buscado, colocar o caractere terminal no buffer e encerrar

    if (!(n->esquerda || n->direita) && n->data == c)
    {
        buffer[tamanho] = '\0';
        return true;
    }
    else
    {
        bool encontrado = false;

        // Se existir um n� � esquerda
        if (n->esquerda)
        {
            // Adicione '0' no bucket do buffer correspondente ao 'tamanho' nodeAtual
            buffer[tamanho] = '0';

            // fazer recurs�o no n� esquerdo
            encontrado = pegaCodigo(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita)
        {
            buffer[tamanho] = '1';
            encontrado = pegaCodigo(n->direita, c, buffer, tamanho + 1);
        }
        if (!encontrado)
        {
            buffer[tamanho] = '\0';
        }
        return encontrado;
    }

}

void getHeader(Head *head, No *Raiz){
    char buffer[1024] = {0};
    char c;

    for (int i=0; i<29; i++){

        if (i<=25)
            c = i+97;
        if (i==26)
            c = 32;
        if (i==27)
            c = 10;
        if (i==28)
            c = -1;
        pegaCodigo(Raiz, c, buffer, 0);
       // printf("%c - %s \n", c, buffer);

       head[i].tamanho = 0;

        while(buffer[head[i].tamanho] != '\0'){
                if (buffer[head[i].tamanho]=='0')
                    head[i].bit[head[i].tamanho] = 0;

                if (buffer[head[i].tamanho]=='1')
                    head[i].bit[head[i].tamanho] = 1;

                head[i].tamanho++;

        }

    }
}



void Comprimir(const char *entrada, const char *saida){

    FILE *fEntrada = fopen(entrada, "r");
    if(fEntrada == NULL){
        printf("O sistema nao pode encontrar o arquivo especificado.\n\n");
        exit(1);
    }

    FILE *fSaida   = fopen(saida,   "wb");
    if(fSaida == NULL){
        printf("O sistema nao pode armazenar no destino especificado.\n\n");
        exit(1);
    }

    //Cria Lista de frequencia

    No no[29];
    for (int i=0; i<29; i++){

        if (i<=25) no[i].data = i+97;//caractere
        if (i==26) no[i].data = 32;//Quebra de Linha
        if (i==27) no[i].data = 10;//Espa�o
        if (i==28) no[i].data = -1;//EOF

        no[i].esquerda   = NULL;
        no[i].direita    = NULL;
        no[i].frequencia = 0;

    }


    char c;
     while (fread(&c, sizeof(char), 1, fEntrada) >= 1){
        if (c>=97 && c<=122) no[c-97].frequencia++; //caractere
        if (c==32) no[26].frequencia++; //Espa�o
        if (c==10) no[27].frequencia++; //Quebra de Linha
    }
    no[28].frequencia = 1;
    rewind(fEntrada);

    lista l = {NULL, 0};

    //Imprime bloco de frequencia
    for (int m=0;m<29; m++){
        if (m<=26)
            printf("%c: %d\n",no[m].data, no[m].frequencia);
        if (m==27)
            printf("\\n: %d\n", no[m].frequencia);
        if (m==28)
            printf("EOF: %d\n", no[m].frequencia);

        insereLista(novoNodeLista(&no[m]), &l);
    }
    printf("---\n");

    //Cria a arvore de Huffman
    while (l.elementos > 1){

        No *NoEsq = popMinLista(&l);
        No *NoDir = popMinLista(&l);

        No *soma = novoNo(0, NoEsq->frequencia + NoDir->frequencia, NoEsq, NoDir);

        insereLista(novoNodeLista(soma), &l);
    }

    No *Raiz;
    Head head[29]  = {0, 0};
    Raiz = popMinLista(&l);

    getHeader(&head[0], Raiz);

    //Neste Ponto nao preciso mais da arvore,
    //freeTree(Raiz);

    //Vou imprimir o header no arquivo;

    for (int i=0; i<29; i++){
        if (i<=25)
            printf("%c: ",i+97);
        if (i==26)
            printf("%c: ",32);
        if (i==27)
            printf("\\n: ");
        if (i==28)
            printf("EOF: ");
        for (int k=0; k<head[i].tamanho; k++)
            printf("%d",head[i].bit[k]);

        printf("\n");

        fwrite(&head[i].tamanho, 1, sizeof(uint8_t), fSaida);

        uint8_t byte = 0;

        for (int j=0; j<32; j++){

            if (head[i].bit[j])
                byte = byte + pow(2, (7 - (j % 8)));

            if ((j+1) % 8 == 0){
                    fwrite(&byte, 1, sizeof(uint8_t), fSaida);
                    byte = 0;
                }
        }
    }


    int contadorCaracteres=0;
    int contHead = 0;
    uint8_t byte = 0;



    while (fread (&c, sizeof(uint8_t), 1, fEntrada) == 1) {

        if (c>=97 && c<=122) contHead = (c-97); //caractere
        if (c==32) contHead = 26; //Espaco
        if (c==10) contHead = 27; //Quebra de Linha

        for(int i=0; i<head[contHead].tamanho;i++){
            if (head[contHead].bit[i])
                byte = byte + pow(2, (7 - (contadorCaracteres % 8)));


            if ((contadorCaracteres+1) % 8 == 0){
                   // printf("%X",byte);
                    fwrite(&byte, 1, sizeof(uint8_t), fSaida);
                    byte = 0;
            }
            contadorCaracteres++;
        }
    }
    //Neste ponto eu preciso colocar o EOF, 
    for(int i=0; i<head[28].tamanho;i++){
        if (head[28].bit[i])
            byte = byte + pow(2, (7 - (contadorCaracteres % 8)));


        if (((contadorCaracteres+1) % 8 == 0) || i == (head[28].tamanho-1)){
                //printf("%X",byte);
                fwrite(&byte, 1, sizeof(uint8_t), fSaida);
                byte = 0;
        }
        contadorCaracteres++;

    }


    fclose(fEntrada);
    fclose(fSaida);
}

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("A sintaxe do comando esta incorreta.\n\n");
        printf("compacta [origem] [destino].\n\n");
        printf("origem\tEspecifica o arquivo a ser compactado.\n");
        printf("destino\tEspecifica o nome do arquivo compactado.\n\n");
        return 0;
    }
    Comprimir(argv[1], argv[2]);
    //Comprimir("faroeste.txt","faroeste.bin");
    //Comprimir("legenda.txt","legenda.bin");


    return 0;
}

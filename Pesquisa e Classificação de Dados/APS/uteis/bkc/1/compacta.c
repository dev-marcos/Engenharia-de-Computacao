#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include<math.h>



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

No *novoNo(char c, int frequencia, No *esquerda, No *direita){

    No *novo;

    if ( ( novo = malloc(sizeof(*novo)) ) == NULL ) return NULL;


    novo->data = c;
    novo->frequencia = frequencia;
    novo->esquerda = esquerda;
    novo->direita = direita;

    return novo;
}


/*******TODA ESSA PARTE SERA SUBISTITUIDA POR HEAP************/

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

/********FIM DA PARTE DE CIMA E TALLLL***********/



char codigoToChar(uint8_t codigo){

    if (codigo<=25) return codigo+97; //caractere
    else if (codigo==26) return 32;   //Espaco
    else if (codigo==27) return 10;   //Quebra de Linha
    else if (codigo==28) return EOF;  //EOF
    else return 0;   
}

uint8_t charToCodigo(char c){
    if (c>=97 && c<=122) return (c-97); //caractere
    if (c==32) return 26;               //Espaco
    if (c==10) return 27;               //Quebra de Linha
    if (c==EOF) return 28;              //EOF
}

void geraListaFrequencia(No *no, FILE *fEntrada){

    for (int i=0; i<29; i++){
        no[i].data       = codigoToChar(i);
        no[i].esquerda   = NULL;
        no[i].direita    = NULL;
        no[i].frequencia = 0;
    }

    char caractere;

     while (fread(&caractere, sizeof(char), 1, fEntrada) >= 1){
        no[charToCodigo(caractere)].frequencia++;
    }

    no[charToCodigo(EOF)].frequencia = 1; //Adiciona 1 para frequencia do EOF

    rewind(fEntrada); //Coloca o SEEK no comeco
}

void imprimeFrequencia(No *no){
    for (int m=0;m<29; m++){
        if (m<=26)
            printf("%c: %d\n",no[m].data, no[m].frequencia);
        if (m==27)
            printf("\\n: %d\n", no[m].frequencia);
        if (m==28)
            printf("EOF: %d\n", no[m].frequencia);

    }
    printf("---\n");
}

//Trocar para Min-HEAP
No * montaArvore(No * no){
    lista l = {NULL, 0};

    for (int m=0;m<29; m++){
        insereLista(novoNodeLista(&no[m]), &l);
    }

    //Cria a arvore de Huffman
    while (l.elementos > 1){

        No *NoEsq = popMinLista(&l);
        No *NoDir = popMinLista(&l);

        No *novo = novoNo(0, NoEsq->frequencia + NoDir->frequencia, NoEsq, NoDir);

        insereLista(novoNodeLista(novo), &l);
    }
    return popMinLista(&l);
}

//ARRUMAR/
bool codigoCaractere(No *n, char c, char *buffer, uint8_t tamanho){

    if (!(n->esquerda || n->direita) && n->data == c){
        buffer[tamanho] = '\0';
        return true;
    }else{
        bool encontrado = false;

        if (n->esquerda){

            buffer[tamanho] = '0';


            encontrado = codigoCaractere(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita){
            buffer[tamanho] = '1';
            encontrado = codigoCaractere(n->direita, c, buffer, tamanho + 1);
        }
        if (!encontrado){
            buffer[tamanho] = '\0';
        }
        return encontrado;
    }

}

//Arrumar
void gerarHeader(Head *head, No *Raiz){
    char buffer[1024] = {0};
    char c;

    for (int i=0; i<29; i++){

        c = codigoToChar(i);

        codigoCaractere(Raiz, c, buffer, 0);//ARRUMAR TAMBEM
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

void freeTree(No *no){

    if (no!=NULL){
        freeTree(no->esquerda);
        freeTree(no->direita);
        free(no);
    }else
        return;
}

void printFileHeader(Head *head, FILE *fSaida){

    for (int i=0; i<29; i++){
        if (i<=26)
            printf("%c: ",codigoToChar(i));
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
}


void escreveCodigoArquivo(FILE *fEntrada, FILE *fSaida, Head *head){

    int contByte=0;
    uint8_t codigo = 0;
    uint8_t byte = 0;
    char c;

    while (fread (&c, sizeof(uint8_t), 1, fEntrada) == 1) {

        codigo = charToCodigo(c);

        // rodo o for do caractere encontrado pela quantidade 
        // de vezes do tamanho do codigo
        for(int i=0; i<head[codigo].tamanho;i++){ 
            //Verifico se o bit é 1 para somar no byte
            if (head[codigo].bit[i])
            //Daria para fazer com operadores binario, mas acho assim mais mais facil
                byte = byte + pow(2, (7 - (contByte % 8))); 

            //quando atinge 8 e gravado o byte e zerado para comecar de novo
            if ((contByte+1) % 8 == 0){
                    fwrite(&byte, 1, sizeof(uint8_t), fSaida);
                    byte = 0;
            }
            contByte++; //Controle de quantidade de bytes gravado
        }
    }

    //Neste ponto eu preciso colocar o EOF, e o mesmo codigo do anterior, mas eu forco o caractere EOF
    for(int i=0; i<head[charToCodigo(EOF)].tamanho;i++){
        if (head[28].bit[i])
            byte = byte + pow(2, (7 - (contByte % 8)));


        if (((contByte+1) % 8 == 0) || i == (head[28].tamanho-1)){
                fwrite(&byte, 1, sizeof(uint8_t), fSaida);
                byte = 0;
        }
        contByte++;

    }
}

void Comprimir(const char *entrada, const char *saida){

    FILE *fEntrada = fopen(entrada, "rb");
    if(fEntrada == NULL){
        printf("O sistema nao pode encontrar o arquivo especificado.\n\n");
        exit(1);
    }

    FILE *fSaida   = fopen(saida,   "wb");
    if(fSaida == NULL){
        printf("O sistema nao pode armazenar no destino especificado.\n\n");
        exit(1);
    }

    No no[29];
    
    
    //Cria Lista de frequencia
    geraListaFrequencia(&no[0], fEntrada);

    //Imprime bloco de frequencia
    imprimeFrequencia(&no[0]);

    //Crio um ponteiro para receber a arvore de Huff criada
    No *Raiz = montaArvore(&no[0]); //PRECISO IMPLEMENTAR A MIN-HEAP

    Head head[29]  = {0, 0};

    gerarHeader(&head[0], Raiz); //ARRUMAR ESSA FUNCAO

    //Neste Ponto nao preciso mais da arvore, só uso o head
    freeTree(Raiz);

    //Imprimir o header no arquivo e terminal;
    printFileHeader(&head[0], fSaida);

    //a funcao que vai escrever o arquivo
    escreveCodigoArquivo(fEntrada, fSaida, &head[0]);

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
    return 0;
}

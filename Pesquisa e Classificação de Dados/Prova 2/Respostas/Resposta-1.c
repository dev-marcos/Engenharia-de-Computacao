#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int key;
    struct No *esq;
    struct No *dir;
} No;

No *novoNo(int n, No *esq, No *dir){
    No *novo;
    if ((novo = malloc(sizeof(No))) == NULL ) 
		return NULL;

    novo->key = n;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

No *verificaPosOrdem(int *v, int tam){

    if (tam>0){
        tam--;

        int tamEsq=0;

        while(v[tamEsq]<v[tam]) tamEsq++;

        int tamDir = (tam - tamEsq); //Definindo tamanho da esquerda

        No *no = novoNo(v[tam],                            //Pega o ultimo elemento
                    verificaPosOrdem(&v[0],      tamEsq),  //Cria o Filho da esquerda
                    verificaPosOrdem(&v[tamEsq], tamDir)); //Cria o Filho da direita
        return no;
    }else return NULL;
}


int altura(No *no){
	if (no!=NULL) {
        int esq = altura(no->esq);
        int dir = altura(no->dir);
        
        if (esq > dir)
             return esq + 1;
        else return dir + 1; 
    }else return -1;
}

int verificaAVL(No *no){
	int esq, dir, AVL;
	AVL = 1;

	if(no!=NULL){
		AVL = verificaAVL(no->esq);
		if(AVL) 
            AVL = verificaAVL(no->dir);
		if(AVL){
			esq = altura(no->esq);
			dir = altura(no->dir);
			if(esq-dir <= 1 && esq-dir >= -1) 
                AVL = 1;  
			else 
                AVL = 0;
		}
	}
	return(AVL);
}


int main(){

    int tamanho=0;
    int v[100]={0};

    scanf("%d", &tamanho);

    for(int i=0; i<tamanho; i++){
        scanf("%d", &v[i]);
    }

    No * arvore = verificaPosOrdem(v, tamanho);

    if (verificaAVL(arvore))
        printf("eh AVL\n");
    else 
        printf("nao eh AVL\n");

    return 0;
}

 

 

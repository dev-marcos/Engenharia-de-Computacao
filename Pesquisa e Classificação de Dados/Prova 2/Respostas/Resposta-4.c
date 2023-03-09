#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TABELA 1024

void createFile(){
    //Se o arquivo abrir no modo leitura, signfica que ele existe
    FILE *arquivo = fopen("pessoas.dat", "r");
    if(arquivo){ 
        fclose(arquivo);
    }else{

        FILE *arquivo = fopen("pessoas.dat", "wb");
        uint8_t byte = 0x00;
        for (int i=0; i<TABELA; i++){
            //Apenas para garantir que nas flag tera 0x00
            fseek(arquivo, 1024*i, SEEK_SET);
            fwrite(&byte, sizeof(uint8_t), 1, arquivo);
        }
        //Vou na ultima posicao do arquivo e escrevo 0x00, 
        //Assim ele cria o tamanho exato que precisamos
        fseek(arquivo, ((1024*TABELA) - 1) , SEEK_SET);
        fwrite(&byte, sizeof(uint8_t), 1, arquivo);
        fclose(arquivo); 
    }    
}

int hash (int idade, char * nome) {
long long valor = idade * 13;

   for (int i = 1; nome[i] != '\0'; i++) 
      valor = (valor * 31 + nome[i]);
   return valor % TABELA;
}

void writeRecord(int idade, char * nome){

    FILE *f = fopen("pessoas.dat", "r+b");
    if(f == NULL){
        printf("O sistema nao pode encontrar o arquivo especificado.\n\n");
        exit(1);
    }

    int chave = hash(idade, &nome[0]);

    for (int i= 0; i<TABELA;i++){
        uint8_t flag;
        fseek(f, 1024*((chave+i)%TABELA), SEEK_SET);     
        fread (&flag, sizeof(uint8_t), 1, f);

        if (!flag){
            //Faco mod, para quando chegar no final, comecar de novo
            fseek(f, 1024*((chave+i)%TABELA), SEEK_SET);
            flag = 0x01;
            fwrite(&flag,  sizeof(uint8_t), 1, f);  
            fwrite(&idade,  sizeof(uint8_t), 1, f); 
 
            //Fiz um for para percorrer o nome e ir gravando byte a byte
            for (int letra=0; nome[letra]!='\0'; letra++)
                fwrite(&nome[letra],  sizeof(char), 1, f); 

            break; //Paro de executar quando gravar o nome na tabela
        }
        if(i==(TABELA-1)){
            printf("Tabela Lotada!");
            break;  //Paro de executar quando nao encontra uma posicao livre
        }
    }

    
    fclose(f);
}


void lerRegistros(){
    FILE *f = fopen("pessoas.dat", "r+");
    for (int i= 0; i<TABELA;i++){
        uint8_t flag;
        fseek(f, 1024*i, SEEK_SET);     
        fread (&flag, sizeof(uint8_t), 1, f);

        if (flag){
            uint8_t idade;
            fread (&idade, sizeof(uint8_t), 1, f);
            
            char nome[1000];

            fread(&nome[0], sizeof(char), 1000, f); 

            printf("Chave: %d \tIdade: %d \tNome: %s\n",i,idade, nome);
        }
    }
    fclose(f);
}

int main(){
    createFile();
    printf("Quantidade de registro a inserir:");
    int tamanho=0;

    scanf("%d", &tamanho);
    int idade;
    char nome[1000];
    for(int i=0; i<tamanho; i++){
        printf("Insira a idade e nome, respectivamente:\n");
        scanf("%d %s", &idade, &nome[0]);
        
        writeRecord(idade, &nome[0]);
    }


    printf("\nEscolhi esta funcao hash porque, ela considera a idade multiplicada por \n");
    printf("um numero primo como valor inicial e realiza a conversao da string para inteiro,\n");
    printf("trocando a base 256, por outro numero primo, e por fim realiza o espalhamento\n");
    printf("por meio do resto da divisao.\n");
    //lerRegistros();


    return 0;
}

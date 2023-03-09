#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int diferencaArquivos(const char *arquivo1, const char *arquivo2){
    FILE *farquivo1 = fopen(arquivo1, "rb");
    FILE *farquivo2 = fopen(arquivo2, "rb");

    char ch1, ch2;
    int diff=0;
    do{
        ch1 = fgetc(farquivo1);
        ch2 = fgetc(farquivo2);

        if (ch1 != ch2){
                diff++;
                printf("%d - %d \n", ch1,ch2);
        }

    } while (ch1 != EOF && ch2 != EOF);

    if (!(ch1 == EOF && ch2 == EOF))
        diff++;

    fclose(farquivo1);
    fclose(farquivo2);
    return diff;
}



void teste(){
    system("compacta.exe teste/faroeste.txt teste/saida/faroeste.bin");
    system("descompacta.exe teste/saida/faroeste.bin teste/saida/faroeste.txt");


    system("compacta.exe teste/legenda.txt teste/saida/legenda.bin");
    system("descompacta.exe teste/saida/legenda.bin teste/saida/legenda.txt");


    system("compacta.exe teste/eliminacao.txt teste/saida/eliminacao.bin");
    system("descompacta.exe teste/saida/eliminacao.bin teste/saida/eliminacao.txt");


    system("compacta.exe teste/misterio.txt teste/saida/misterio.bin");
    system("descompacta.exe teste/saida/misterio.bin teste/saida/misterio.txt");

    int a = diferencaArquivos("teste/saida/faroeste.txt", "teste/faroeste.txt");
    int b = diferencaArquivos("teste/saida/legenda.txt", "teste/legenda.txt");
    int c = diferencaArquivos("teste/saida/eliminacao.txt", "teste/eliminacao.txt");
    int d = diferencaArquivos("teste/saida/misterio.txt", "teste/misterio.txt");

    printf("\n\n ----LOG DE TESTE----- \n\n");

    if (a>0) printf("O arquivo faroeste possui %d diferenca(s)\n", a);
        else printf("teste faroeste: OK!\n");

    if (b>0) printf("O arquivo legenda possui %d diferenca(s)\n", b);
        else printf("teste legenda: OK!\n");

    if (c>0) printf("O arquivo eliminacao possui %d diferenca(s)\n", c);
        else printf("teste eliminacao: OK!\n");

    if (d>0) printf("O arquivo misterio possui %d diferenca(s)\n", d);
        else printf("teste misterio: OK!\n");

    printf("\n\n -------------------- \n\n");
}
int main(){

    teste();
    return 0;
}

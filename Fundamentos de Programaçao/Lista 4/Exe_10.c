/*
10) Construa um programa que seja capaz de concluir qual dentre os animais seguintes
foi escolhido atrav�s de perguntas e respostas. Animais poss�veis: le�o, cavalo, homem,
macaco, baleia, avestruz, ping�im, pato, �guia, tartaruga, crocodilo e cobra.
Exemplo:
� mam�fero: Sim
� quadr�pede: Sim
� carn�voro: N�o
� herb�voro: Sim
Ent�o o animal escolhido foi o cavalo.
Utilize as seguintes classifica��es:

---------------------------------------------------|
|           |              | carn�voro | le�o      |
|           | quadr�pede   |-----------|-----------|
|           |              | herb�voro | cavalo    |
|           |--------------|-----------|-----------|
|           |              | on�voro   | homem     |
| mam�feros | b�pede       |-----------|-----------|
|           |              | frut�fero | macaco    |
|           |--------------|-----------|-----------|
|           | voadores     |           | morcego   |
|           |--------------|-----------|-----------|
|           | aqu�ticos    |           | baleia    |
|-----------|--------------|-----------|---------- |
|           |              | tropical  | avestruz  |
|           | n�o-voadoras |-----------|-----------|
|           |              | polar     | ping�im   |
| aves      |--------------|-----------|-----------|
|           | nadadoras    |           | pato      |
|           |--------------|-----------|-----------|
|           | de rapina    |           | �guia     |
|-----------|--------------|-----------|-----------|
|           | com casco    |           | tartaruga |
|           |--------------|-----------|-----------|
| r�pteis   | carn�voros   |           | crocodilo |
|           |--------------|-----------|-----------|
|           | sem patas    |           |cobra      |
---------------------------------------------------|
*/

#include <stdio.h>

int main (){
    char escolha=0;
    printf("O animal e mam�fero: (s/n)");
    scanf("%c", &escolha);
    if (escolha=='s')
    {
        printf("O animal e quadr�pede: (s/n)");
        scanf("%c", &escolha);
        if (escolha=='s')
        {

        }
        else
        {
            printf("O animal e b�pede: (s/n)");
            scanf("%c", &escolha);
            if (escolha=='s')
            {

            }
            else
            {
                printf("O animal e voadores: (s/n)");
                scanf("%c", &escolha);
                if (escolha=='s')
                {

                }
                else
                {
                    printf("O animal e aqu�ticos: (s/n)");
                    scanf("%c", &escolha);
                    if (escolha=='s')
                    {

                    }
                    else
                    {
                        printf("Animal nao encontrado!");
                    }

                }
            }
        }
    }
    else
    {
        printf("O animal e aves: (s/n)");
        scanf("%c", &escolha);
        if (escolha=='s')
        {

        }
        else
        {
            printf("O animal e r�pteis: (s/n)");
            scanf("%c", &escolha);
            if (escolha=='s')
            {

            }
            else
            {


            }
        }
    }

    return 0;
}

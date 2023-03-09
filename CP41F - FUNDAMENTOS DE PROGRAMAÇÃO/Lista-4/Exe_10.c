/*
10) Construa um programa que seja capaz de concluir qual dentre os animais seguintes
foi escolhido através de perguntas e respostas. Animais possíveis: leão, cavalo, homem,
macaco, baleia, avestruz, pingüim, pato, águia, tartaruga, crocodilo e cobra.
Exemplo:
É mamífero: Sim
É quadrúpede: Sim
É carnívoro: Não
É herbívoro: Sim
Então o animal escolhido foi o cavalo.
Utilize as seguintes classificações:

---------------------------------------------------|
|           |              | carnívoro | leão      |
|           | quadrúpede   |-----------|-----------|
|           |              | herbívoro | cavalo    |
|           |--------------|-----------|-----------|
|           |              | onívoro   | homem     |
| mamíferos | bípede       |-----------|-----------|
|           |              | frutífero | macaco    |
|           |--------------|-----------|-----------|
|           | voadores     |           | morcego   |
|           |--------------|-----------|-----------|
|           | aquáticos    |           | baleia    |
|-----------|--------------|-----------|---------- |
|           |              | tropical  | avestruz  |
|           | não-voadoras |-----------|-----------|
|           |              | polar     | pingüim   |
| aves      |--------------|-----------|-----------|
|           | nadadoras    |           | pato      |
|           |--------------|-----------|-----------|
|           | de rapina    |           | águia     |
|-----------|--------------|-----------|-----------|
|           | com casco    |           | tartaruga |
|           |--------------|-----------|-----------|
| répteis   | carnívoros   |           | crocodilo |
|           |--------------|-----------|-----------|
|           | sem patas    |           |cobra      |
---------------------------------------------------|
*/

#include <stdio.h>

int main (){
    char escolha=0;
    printf("O animal e mamífero: (s/n)");
    scanf("%c", &escolha);
    if (escolha=='s')
    {
        printf("O animal e quadrúpede: (s/n)");
        scanf("%c", &escolha);
        if (escolha=='s')
        {

        }
        else
        {
            printf("O animal e bípede: (s/n)");
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
                    printf("O animal e aquáticos: (s/n)");
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
            printf("O animal e répteis: (s/n)");
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

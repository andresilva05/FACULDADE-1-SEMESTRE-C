// 4. Faça um programa que leia um nome e imprima suas 3 primeiras letras.
// Exemplo: para o nome = “marcelo”, a saída será “mar”
#include <stdio.h>
#include <string.h>

// Função que imprime as três primeiras letras do nome recebido
void imprimiTresPrimLetras(char nome[]);

int main()
{
    char nome[10];   // Vetor para armazenar o nome digitado (até 9 caracteres + '\0')
    int sair = 1, c; // Variável para controlar o loop principal (1 = continuar, 0 = sair)

    do
    {
        // Loop para garantir que o nome tenha pelo menos 3 letras
        do
        {
            printf("Digite um nome com pelo menos tres letras: \n");
            scanf("%s", nome); // Lê o nome do usuário

            if (strlen(nome) >= 3)
            {
                // Se o nome tem 3 ou mais letras, chama a função para imprimir as 3 primeiras
                imprimiTresPrimLetras(nome);
            }
            else
            {
                // Caso o nome tenha menos de 3 letras, avisa o usuário e pede para tentar novamente
                printf("Nome nao tem 3 letras, tente novamente!\n\n");
            }

        } while (strlen(nome) < 3); // Repete enquanto o nome for menor que 3 letras

        // Pergunta ao usuário se deseja continuar ou sair
        printf("1 para continuar programa.\n0 para sair!\n");
        scanf("%d", &sair);

        // Validação da entrada para aceitar somente 0 ou 1
        while (sair != 1 && sair != 0)
        {
            printf("Opcao invalida, tente novamente!\n");
            scanf("%d", &sair);
        }
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

    } while (sair != 0); // Repete o programa enquanto não for pedido para sair (sair == 0)
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    printf("Encerrando programa!\n");

    return 0;
}

// Função que imprime as três primeiras letras da string recebida
void imprimiTresPrimLetras(char nome[])
{
    int i;
    printf("As tres primeiras letras do nome digitado sao: (");
    for (i = 0; i <= 2; i++)
    {
        // Imprime um caractere por vez
        printf("%c", nome[i]);
    }
    printf(")\n\n");
}

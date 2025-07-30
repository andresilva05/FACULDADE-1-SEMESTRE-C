// 7. Faça uma função que receba uma frase e retorne quantas vogais (a, e, i, o, u) possui essa palavra.
// Exemplo: em “instituto federal” a resposta será 7.

#include <stdio.h>
#include <string.h>
#define TAM 100

// Função que conta e retorna a quantidade de vogais na string recebida
int verificaQtdVogais(char palavra[]);

int main()
{
    int sair = 1, c;
    char palavra[TAM];

    do
    {
        // Loop que garante a entrada correta do usuário
        while (1)
        {
            printf("Digite uma palavra ate 100 caracteres (incluindo espacos): \n");
            fgets(palavra, sizeof(palavra), stdin); // Lê até TAM-1 caracteres, incluindo espaços

            // Se não encontrou '\n', significa que a string ultrapassou o limite do buffer
            if (strchr(palavra, '\n') == NULL)
            {
                printf("Quantidade de caracteres excedeu o limite, tente novamente!\n");

                // Limpa o restante do buffer (caracteres extras deixados pela entrada longa)
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue; // Volta para pedir a entrada novamente
            }

            // Remove o '\n' do final da string, se presente
            palavra[strcspn(palavra, "\n")] = '\0';

            // Chama a função para contar e exibir a quantidade de vogais
            printf("\nQuantidade de vogais em sua frase eh: %d\n\n", verificaQtdVogais(palavra));
            break; // Sai do loop de entrada após sucesso
        }

        // Pergunta ao usuário se deseja continuar ou sair
        printf("1 para continuar o programa.\n0 para sair!\n");
        scanf("%d", &sair);

        // Validação da opção digitada
        while (sair != 1 && sair != 0)
        {
            printf("Opcao invalida, tente novamente!\n");
            scanf("%d", &sair);
        }

        // Limpa o buffer após usar scanf (para evitar problemas na próxima leitura com fgets)
        while ((c = getchar()) != '\n' && c != EOF)
            ;

    } while (sair != 0); // Repete enquanto o usuário quiser continuar

    printf("Encerrando programa!\n");
    return 0;
}

int verificaQtdVogais(char palavra[])
{
    int i, j, ehVogal = 0;
    int tamanho = strlen(palavra);
    char vogais[] = "aeiouAEIOU"; // Lista de vogais para comparar

    // Percorre cada caractere da string
    for (i = 0; i < tamanho; i++)
    {
        // Verifica se o caractere atual é uma vogal
        for (j = 0; j < strlen(vogais); j++)
        {
            if (palavra[i] == vogais[j])
            {
                ehVogal++; // Incrementa o contador de vogais
                break;     // Já encontrou a vogal, pode sair do laço interno
            }
        }
    }
    return ehVogal;
}

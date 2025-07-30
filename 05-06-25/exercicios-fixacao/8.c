// 8. Faça um programa em que troque todas as ocorrências de uma letra L1 pela letra L2 em uma string. A
// string e as letras L1 e L2 devem ser fornecidas pelo usuário.
// Entrada
// A entrada consiste em uma variável (texto) do tipo de dados string e em duas variáveis (l1 e l2),
// declaradas como tipo de dados char.
// Exemplo: para o texto “criptografar uma mensagem” com l1 = “a” e l2 = “x”, a resposta será
// “criptogrxfxr umx mensxgem”
#include <stdio.h>
#include <string.h>

#define TAM 100 // Define o tamanho máximo da string

// Função que troca todas as ocorrências da letra l1 por l2
void trocaLetraFrase(char texto[], char l1, char l2);

int main()
{
    char texto[TAM], L1, L2;
    int c, sair = 1;

    do
    {
        while (1) // Loop para garantir uma entrada válida
        {
            printf("Digite um texto ate 100 caracteres (incluindo espacos): \n");
            fgets(texto, sizeof(texto), stdin); // Lê a linha (com espaços)

            // Verifica se o usuário digitou mais de 99 caracteres (sem contar \0)
            if (strchr(texto, '\n') == NULL)
            {
                printf("Quantidade de caracteres excedeu o limite, tente novamente!\n");

                // Limpa o restante do buffer
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                continue; // Repete a entrada
            }

            // Remove o '\n' do final, se existir
            texto[strcspn(texto, "\n")] = '\0';

            // Solicita a letra a ser trocada
            printf("Digite letra que deseja ser trocada (ex: A)\n");
            scanf(" %c", &L1); // O espaço evita ler o '\n'

            // Solicita a nova letra
            printf("Digite letra que deseja inserir (ex: B)\n");
            scanf(" %c", &L2); // Também com espaço

            // Chama a função que realiza a troca
            trocaLetraFrase(texto, L1, L2);
            break; // Sai do loop de entrada
        }

        // Pergunta se o usuário deseja continuar
        printf("1 para continuar o programa.\n0 para sair!\n");
        scanf("%d", &sair);

        // Validação para aceitar apenas 0 ou 1
        while (sair != 1 && sair != 0)
        {
            printf("Opcao invalida, tente novamente!\n");
            scanf("%d", &sair);
        }

        // Limpa o buffer do teclado após o scanf
        while ((c = getchar()) != '\n' && c != EOF)
            ;

    } while (sair != 0); // Repete enquanto o usuário quiser

    printf("Encerrando programa!\n");
    return 0;
}

// Função que troca todas as ocorrências de l1 por l2 no texto
void trocaLetraFrase(char texto[], char l1, char l2)
{
    int i;
    int tamanho = strlen(texto);

    for (i = 0; i < tamanho; i++)
    {
        if (texto[i] == l1)
        {
            texto[i] = l2;
        }
    }

    // Mostra a frase modificada
    printf("Frase com letra trocada: %s\n\n", texto);
}

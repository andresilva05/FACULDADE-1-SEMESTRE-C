// 6. Faça uma função que receba uma string e retorne essa string sem suas vogais.
// Exemplo: em “criptografar uma mensagem” a resposta será “crptgrfr m mnsgm”.

#include <stdio.h>
#include <string.h>
#define TAM 100

// Função que imprime a string sem vogais
void imprimiSemVogais(char stringUsuario[]);

int main()
{
    char string[TAM]; // Vetor para armazenar a entrada do usuário
    int sair = 1, c;  // Variável de controle do programa

    do
    {
        do
        {
            // Solicita ao usuário que digite uma string
            printf("Digite o que quiser ate 100 caracteres (incluido espacos): \n");
            fgets(string, sizeof(string), stdin); // Lê a linha inteira (com espaços)

            // Remove o '\n' do final da string, caso exista
            string[strcspn(string, "\n")] = '\0';

            if (strlen(string) <= 100)
            {
                imprimiSemVogais(string); // Chama a função para imprimir sem vogais
            }
            else
            {
                // Caso a string exceda o limite
                printf("Quantidade de caracteres excedeu o limite, tente novamente!\n");
            }

        } while (strlen(string) > TAM - 1); // Repete se exceder o limite

        // Pergunta se o usuário quer continuar
        printf("1 para continuar programa.\n0 para sair!\n");
        scanf("%d", &sair);

        // Validação para aceitar apenas 0 ou 1
        while (sair != 1 && sair != 0)
        {
            printf("Opcao invalida, tente novamente!\n");
            scanf("%d", &sair);
        }

        // Limpa o buffer do teclado após o scanf
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

    } while (sair != 0); // Continua enquanto o usuário desejar

    printf("Encerrando o programa!\n");

    return 0;
}

// Função que imprime a string sem vogais
void imprimiSemVogais(char stringUsuario[])
{
    char vogais[] = "aeiouAEIOU";        // Lista de vogais para comparar
    int tamanho = strlen(stringUsuario); // Tamanho da string digitada
    int i, j, k = 0;                     // Índices e contador de consoantes

    char consoantes[tamanho + 1]; // Vetor para armazenar a string sem vogais (+1 para '\0')

    for (i = 0; i < tamanho; i++)
    {
        int ehVogal = 0; // Flag para saber se o caractere é vogal

        // Verifica se o caractere atual é uma vogal
        for (j = 0; j < strlen(vogais); j++)
        {
            if (stringUsuario[i] == vogais[j])
            {
                ehVogal = 1;
                break; // Pode sair do loop se já encontrou uma vogal
            }
        }

        // Se não for vogal, adiciona no vetor de consoantes
        if (ehVogal == 0)
        {
            consoantes[k] = stringUsuario[i];
            k++;
        }
    }

    consoantes[k] = '\0'; // Finaliza a string com o caractere nulo

    printf("Frase sem vogais: %s\n", consoantes); // Exibe o resultado
}

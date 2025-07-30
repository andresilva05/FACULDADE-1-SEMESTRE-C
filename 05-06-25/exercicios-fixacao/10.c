#include <stdio.h> // Biblioteca padrão de entrada e saída

#define TAM 100 // Define o tamanho máximo das strings como 100

// Protótipo da função de criptografia
void criptografarMensagem(char mensagem[], char mensagem_criptografada[]);

int main()
{
    char mensagem[TAM];               // Vetor para armazenar a mensagem original
    char mensagem_criptografada[TAM]; // Vetor para armazenar a mensagem criptografada
    int sair;                         // Variável para controle do loop (sair ou continuar)

    do
    {
        // Solicita ao usuário que digite uma mensagem
        printf("Digite a mensagem a ser criptografada: ");
        fgets(mensagem, TAM, stdin); // Lê a string com espaços (inclui o '\n' no final)

        // Remove o caractere '\n' (quebra de linha) que o fgets pode adicionar
        int i = 0;
        while (mensagem[i] != '\0')
        {
            if (mensagem[i] == '\n')
            {
                mensagem[i] = '\0'; // Substitui o '\n' por fim de string
                break;
            }
            i++;
        }

        // Chama a função para criptografar a mensagem
        criptografarMensagem(mensagem, mensagem_criptografada);

        // Exibe a mensagem criptografada
        printf("\nMensagem criptografada: %s\n", mensagem_criptografada);

        // Pergunta ao usuário se deseja continuar ou sair
        printf("\nDigite 1 para continuar ou 0 para sair!\n");
        scanf("%d", &sair);

        // Limpa o buffer do teclado (remove qualquer caractere extra, como o '\n')
        while (getchar() != '\n')
            ;
    } while (sair != 0); // Repete enquanto o usuário quiser continuar

    printf("Encerrando programa!\n");
    return 0;
}

// Função que criptografa a mensagem original usando a cifra de César com deslocamento de 3 posições
void criptografarMensagem(char mensagem[], char mensagem_criptografada[])
{
    int i = 0;

    // Percorre cada caractere da mensagem original
    while (mensagem[i] != '\0')
    {
        char letra = mensagem[i];

        // Se a letra estiver entre 'a' e 'z', aplica a criptografia
        if (letra >= 'a' && letra <= 'z')
        {
            // Desloca a letra 3 posições para frente no alfabeto
            mensagem_criptografada[i] = ((letra - 'a' + 3) % 26) + 'a';
        }
        else
        {
            // Se não for letra minúscula, copia o caractere original
            mensagem_criptografada[i] = letra;
        }

        i++;
    }

    // Finaliza a string criptografada com o caractere nulo '\0'
    mensagem_criptografada[i] = '\0';
}

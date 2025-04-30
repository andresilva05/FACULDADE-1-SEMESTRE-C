#include <stdio.h>

int main()
{
    // declaração de variáveis e constantes

    const int MAX = 40;
    char nome[MAX];

    // exibe mensagem solicitando que o usuario informe o nome
    printf("Digite seu nome: ");
    // leitura do nome
    gets(nome);
    printf("\n Seja bem-vindo(a), %s!\n", nome);
    getchar();
    return 0;
}

                                        //OUTRO EXEMPLO SOBRE CONSTANTES 

#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf, etc.)
#include <conio.h>   // Biblioteca necessária para usar getch() (somente no Windows)

int main() {
    char nome[40];  // Declara um vetor de caracteres para armazenar o nome (até 39 caracteres + '\0')
    char sexo, letra; // Declara duas variáveis do tipo char para armazenar sexo e uma letra

    // Pede para o usuário digitar o nome
    printf("Qual é o seu nome? ");
    gets(nome);  // Lê uma linha de texto do teclado (⚠ gets() é inseguro e pode causar problemas)

    // Pede para o usuário informar o sexo
    printf("Qual é o seu sexo (M ou F)? ");
    sexo = getchar();  // Lê um único caractere e espera o Enter

    // Pede para o usuário digitar uma letra qualquer
    printf("Digite uma letra qualquer: ");
    letra = getch();   // Lê um único caractere sem precisar pressionar Enter

    // Exibe os dados digitados pelo usuário
    printf("\nOlá %s!\n", nome);
    printf("Sexo: %c\n", sexo);
    printf("Letra: %c\n", letra);

    return 0;  // Retorna 0 indicando que o programa foi executado com sucesso
}

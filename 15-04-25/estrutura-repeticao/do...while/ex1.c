// 1. Exemplo Fácil: Contagem Regressiva
// Aqui, o programa pede para o usuário digitar um número e faz uma contagem regressiva até 1.

#include <stdio.h>

int main()
{
    int num;

    // Lê um número positivo
    printf("Digite um número positivo: ");
    scanf("%d", &num);

    // Faz a contagem regressiva até 1
    do
    {
        printf("%d ", num);
        num--;
    } while (num > 0);

    printf("\nFim da contagem!\n");
    return 0;
}

// Explicação:
// Esse exemplo é bem simples. O programa começa a contagem a partir de um número positivo e vai diminuindo até atingir 1, sempre mostrando o número atual.

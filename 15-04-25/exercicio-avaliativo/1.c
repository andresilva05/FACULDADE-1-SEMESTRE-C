// Exercício 1. Fazer um programa em C para ler um número inteiro positivo (n), calcular e
// escrever o fatorial do número lido. Se o programa ler um número negativo, deve solicitar a
// leitura de um novo número. Sabe-se que:
// n! = n x (n-1) x... x 1

#include <stdio.h>

int main()
{

    int n, fatorial = 1, resultado = 0, i;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &n);

    if (n > 0)
    {
        for (i = n; i >= 1; i--)
        {

            fatorial = i * fatorial;

            resultado = fatorial;
        }
    }
    else
    {
        printf("Digite um numero inteiro:\n");
        scanf("%d", &n);

        for (i = n; i >= 1; i--)
        {

            fatorial = i * fatorial;

            resultado = fatorial;
        }
    }

    printf("O fatorial do numero %d, eh: %d \n", n, resultado);

    return 0;
}

// #include <stdio.h>

// int main() {
//     int n, fatorial = 1;

//     // Solicita um número positivo até que seja digitado corretamente
//     do {
//         printf("Digite um numero inteiro positivo: ");
//         scanf("%d", &n);
//         if (n < 0) {
//             printf("Valor invalido! Tente novamente.\n");
//         }
//     } while (n < 0);   Continua pedindo até que o número seja positivo

//     // Calcula o fatorial
//     for (int i = n; i >= 1; i--) {
//         fatorial *= i;
//     }

//     // Exibe o resultado
//     printf("O fatorial de %d eh: %d\n", n, fatorial);

//     return 0;
// }

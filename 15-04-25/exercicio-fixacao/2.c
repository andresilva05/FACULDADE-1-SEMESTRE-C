// Exercício 2. Escreva
// um programa para imprimir uma sequência de 6 inteiros consecutivos onde nenhum deles é
// par. O primeiro número será informado pelo usuário.

#include <stdio.h>

int main()
{

    int numero;
    int i;

    printf("Digite o primeiro numero da sequencia: ");
    scanf("%d", &numero);

    if (numero % 2 == 0)
        numero++;

    for (i = 1; i <= 6; i++)
    {
        printf("\n %d", numero);
        numero += 2;
    }

    return 0;
}
// Exercício 7. Dada uma lista de números inteiros, digitada pelo usuário, calcule e imprima:
// - O maior número ímpar divisível por 3.
// - A média dos números pares.
// - Todos os números múltiplos do primeiro número digitado, até 100.
// O fim da lista será indicado por um número negativo.

#include <stdio.h>

int main()
{
    int i, num, maiorImpar = 0, primeiroNum, armazenou = 0, par = 0;
    float mediaPar, somaPar = 0;

    while (num >= 0)
    {
        printf("Digite o numero (digite um numero negativo para sair): \n");
        scanf("%d", &num);

        if (armazenou == 0)
        {
            primeiroNum = num;
            armazenou = 1;
        }

        if (num % 2 == 1 && num % 3 == 0)
        {
            if (num > maiorImpar)
            {
                maiorImpar = num;
            }
        }

        if (num % 2 == 0)
        {
            par++;
            somaPar += num;
        }
    }

    if (par > 0)
    {
        mediaPar = somaPar / par;
        printf("A media dos numeros pares eh: %.2f\n", mediaPar);
    }
    else
    {
        printf("Nao foram digitados numeros pares.\n");
    }

    printf("Maior numero impar divisivel por 3 eh: %d\n", maiorImpar);

    // Imprime múltiplos do primeiro número
    for (i = 1; i * primeiroNum <= 100; i++)
    {
        printf("Os numeros multiplos de %d sao: %d\n", primeiroNum, i * primeiroNum);
    }

    return 0;
}

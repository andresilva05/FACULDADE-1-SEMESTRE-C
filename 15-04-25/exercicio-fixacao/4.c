// Exercício 4. Faça um programa que leia números inteiros até que seja digitado um número
// negativo, e calcule a média dos números positivos digitados.

#include <stdio.h>

int main()
{
    int numero = 0, qtd = 0;
    float media, soma = 0;
    while (numero >= 0)
    {
        printf("\n digite um numero: ");
        scanf("%d", &numero);

        if (numero > 0)
        {
            soma = soma + numero;
            qtd = qtd + 1;
        }
    }
    media = (soma / qtd);

    printf("A soma dos numeros eh = %.2f\nA quantidade de numeros digitados eh = %d \nA media = %.2f", soma, qtd, media);
    return 0;
}
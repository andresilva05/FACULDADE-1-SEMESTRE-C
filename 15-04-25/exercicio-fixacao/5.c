// Exercício 5. Faça um programa que leia 5 números inteiros e ao final informe a quantidade de
// números ímpares e pares lidos. Calcule também a soma dos números pares, a soma dos
// números ímpares e informe qual desses valores é o maior

#include <stdio.h>

int main()
{

    int num, impar = 0, par = 0, somaPar = 0, somaImpar = 0;

    for (int i = 1; i <= 5; i++)
    {
        printf("Digite um numero: \n");
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            par++;
            somaPar += num;
        }
        else
        {
            impar++;
            somaImpar += num;
        }
    }
    printf("\n Pares: quantidade= %d soma: %d", par, somaPar);
    printf("\n Impares: quantidade= %d soma: %d", impar, somaImpar);
    if (somaPar > somaImpar)
    {
        printf("\n Soma dos pares eh maior!");
    }
    else
    {
        printf("\n Soma dos impares eh maior!");
    }

    return 0;
}
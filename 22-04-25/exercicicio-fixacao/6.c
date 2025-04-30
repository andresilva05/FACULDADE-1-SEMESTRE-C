// Exercício 6. Fazer um programa em C para ler um número e, através de uma função, verifique se
// este é ou não um número primo. Sabe-se que um número primo é aquele que é somente divisível
// por 1 e por ele mesmo.

#include <stdio.h>

int NumeroPrimo(int num);

int main()
{

    int numero;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);

    if (NumeroPrimo(numero))
    {
        printf("Numero eh primo.\n");
    }
    else
    {
        printf("Numero nao eh primo.\n");
    }
    return 0;
}

int NumeroPrimo(int num)
{

    for (int i = 2; i < num; i++) // Começa do 2 até num-1
    {
        if (num % i == 0) // Se for divisível por algum número entre 2 e num-1
        {
            return 0; // Não é primo
        }

        return 1; // É primo
    }
}
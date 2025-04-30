// Exercício 7. Fazer um programa em C para gerar e escrever os 4 (quatro) primeiros números
// perfeitos. Um número perfeito é aquele que é igual à soma dos seus divisores. Por exemplo:
// 6 = 1 + 2 + 3
// 28 = 1 + 2 + 4 + 7 + 14
// O cálculo que indica se um número é perfeito (ou não) deve ser feito em uma função.

#include <stdio.h>

int NumeroPerfeito(int num);
int AchaDivisorNum(int num);

int main()
{
    int numero = 2; // Começa do 2, porque 1 não é perfeito
    int contadorDePerfeitos = 0;

    printf("Os 4 primeiros numeros perfeitos sao:\n\n");

    while (contadorDePerfeitos < 4)
    {
        if (NumeroPerfeito(numero))
        {
            printf("%d\n", numero);
            contadorDePerfeitos++;
        }
        numero++;
    }

    return 0;
}

int AchaDivisorNum(int num)
{
    int i, somaDivisores = 0;
    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            somaDivisores += i;
            // i é divisor de num
        }
    }
    return somaDivisores;
}

int NumeroPerfeito(int num)
{
    if (num == AchaDivisorNum(num))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
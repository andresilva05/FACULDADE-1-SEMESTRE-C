// 1. Dado um vetor A definido como int A[10], preenchê-lo com os números inteiros 1,2,3, ...,10.

#include <stdio.h>

int main()
{
    // Declaração de um vetor de 5 posições do tipo inteiro e uma variável auxiliar 'i'
    int A[10], i;

    // Atribuição de valores manualmente para cada posição do vetor
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;
    A[5] = 6;
    A[6] = 7;
    A[7] = 8;
    A[8] = 9;
    A[9] = 10;

    // Laço para percorrer e exibir os valores do A
    for (i = 0; i < 10; i++)
    {
        printf("%d ", A[i]); // Imprime cada valor seguido de um espaço
    }

    return 0; // Indica que o programa terminou com sucesso
}

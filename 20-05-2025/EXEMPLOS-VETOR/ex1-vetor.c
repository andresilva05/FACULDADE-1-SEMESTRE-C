#include <stdio.h> // Biblioteca padrão para entrada e saída de dados

int main()
{
    // Declaração de um vetor de 5 posições do tipo inteiro e uma variável auxiliar 'i'
    int vetor[5], i;

    // Atribuição de valores manualmente para cada posição do vetor
    vetor[0] = 0;
    vetor[1] = 10;
    vetor[2] = 20;
    vetor[3] = 30;
    vetor[4] = 40;

    // Laço para percorrer e exibir os valores do vetor
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]); // Imprime cada valor seguido de um espaço
    }

    return 0; // Indica que o programa terminou com sucesso
}

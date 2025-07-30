#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados

int main()
{
    int vetor[5], i; // Declaração de um vetor com 5 posições e uma variável auxiliar 'i'

    // Laço para preencher o vetor com valores fornecidos pelo usuário
    for (i = 0; i < 5; i++)
    {
        printf("\n Valor [%d]:", i); // Solicita ao usuário o valor para a posição i
        scanf("%d", &vetor[i]);      // Lê o valor digitado e armazena no vetor
    }

    // Impressão dos dados armazenados no vetor
    printf("Exibicao dos dados armazenados no conjunto:\n[");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]); // Exibe os valores do vetor separados por espaço
    }
    printf("]\n"); // Fecha a exibição

}
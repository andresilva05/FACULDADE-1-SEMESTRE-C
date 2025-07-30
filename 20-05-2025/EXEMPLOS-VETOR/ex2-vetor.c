#include <stdio.h>  // Inclusão da biblioteca padrão de entrada e saída

int main()
{
    int vetor[5], i;  // Declaração de um vetor com 5 posições e uma variável auxiliar 'i'

    // Inicialização do vetor com múltiplos de 10
    for (i = 0; i < 5; i++)
    {
        vetor[i] = i * 10;  // Cada posição recebe o valor do índice multiplicado por 10
    }

    // Impressão dos valores armazenados no vetor
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);  // Imprime cada valor seguido de um espaço
    }

    return 0;  // Finaliza o programa com status de sucesso
}

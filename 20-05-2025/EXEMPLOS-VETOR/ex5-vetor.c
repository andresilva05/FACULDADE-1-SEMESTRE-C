#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados

// Protótipos das funções
void imprimir_vetor(int vetor[]);        // Função para imprimir os elementos do vetor na ordem original
void imprimirVetor_inverso(int vetor[]); // Função para imprimir os elementos do vetor em ordem inversa

int main()
{
    int vetor[5]; // Declaração de um vetor de 5 inteiros
    int i;        // Variável auxiliar usada como índice

    // Preenchimento do vetor com valores informados pelo usuário
    for (i = 0; i < 5; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita valor para a posição 'i'
        scanf("%d", &vetor[i]);       // Lê e armazena o valor digitado no vetor
    }

    // Exibição dos elementos do vetor na ordem original
    imprimir_vetor(vetor);

    // Exibição dos elementos do vetor na ordem inversa
    imprimirVetor_inverso(vetor);

    return 0; // Finaliza o programa com sucesso
}

// Função que imprime os elementos do vetor na ordem em que foram inseridos
void imprimir_vetor(int vetor[])
{
    int i;
    printf("Exibicao dos dados armazenados no conjunto:\n [ ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]); // Imprime o valor da posição i
    }
    printf("]\n"); // Fecha o colchete e adiciona uma quebra de linha
}

// Função que imprime os elementos do vetor em ordem inversa (do último para o primeiro)
void imprimirVetor_inverso(int vetor[])
{
    int i;
    printf("Inverso dos dados armazenados no conjunto:\n [ ");
    for (i = 4; i >= 0; i--) // Laço começa do índice 4 e vai até 0
    {
        printf("%d ", vetor[i]); // Imprime o valor da posição i
    }
    printf("]\n"); // Fecha o colchete e adiciona uma quebra de linha
}

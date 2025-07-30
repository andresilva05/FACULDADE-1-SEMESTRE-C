#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados
#define TAM 5      // Definição de uma constante chamada TAM com valor 5

// Protótipos das funções
void imprimir_vetor(int vetor[]);        // Função que imprime os elementos do vetor na ordem original
void imprimirVetor_inverso(int vetor[]); // Função que imprime os elementos do vetor em ordem inversa

int main()
{
    int vetor[TAM]; // Declaração de um vetor de inteiros com tamanho TAM (5)
    int i;          // Variável auxiliar usada como índice

    // Preenchimento do vetor com valores digitados pelo usuário
    for (i = 0; i < TAM; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita o valor da posição i
        scanf("%d", &vetor[i]);       // Lê e armazena o valor no vetor
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
    for (i = 0; i < TAM; i++) // Percorre o vetor da primeira à última posição
    {
        printf("%d ", vetor[i]); // Imprime o valor da posição i
    }
    printf("]\n"); // Fecha a exibição com colchete e quebra de linha
}

// Função que imprime os elementos do vetor em ordem inversa
void imprimirVetor_inverso(int vetor[])
{
    int i;
    printf("Inverso dos dados armazenados no conjunto:\n [ ");
    for (i = TAM - 1; i >= 0; i--) // Percorre o vetor da última à primeira posição
    {
        printf("%d ", vetor[i]); // Imprime o valor da posição i
    }
    printf("]\n"); // Fecha a exibição com colchete e quebra de linha
}

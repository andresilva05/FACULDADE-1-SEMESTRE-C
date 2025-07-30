// 1. Escreva um programa que leia um vetor e o decomponha em dois outros vetores, um contendo os
// elementos de ordem ímpar e o outro contendo os elementos de ordem par. Por exemplo, se o vetor
// dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7}, o vetor deve gerar os vetores a = {3, 6, 1, 2, 7} e b = {5, 8, 4, 3}.

#include <stdio.h>

// Define o tamanho do vetor principal
#define TAM 10

// Define o tamanho dos vetores A e B, que vão receber elementos de posições pares e ímpares respectivamente
#define TAM_A 10
#define TAM_B 10

// Protótipos das funções
void preencherVetor(int vetor[]);
void retornaVetorImparPar(int vetor[], int vetorA[], int vetorB[]);

int main()
{
    int vetor[TAM]; // Vetor principal com 10 elementos
    int A[TAM_A];   // Vetor para armazenar elementos das posições pares (índices pares)
    int B[TAM_B];   // Vetor para armazenar elementos das posições ímpares (índices ímpares)

    preencherVetor(vetor);             // Preenche o vetor principal com dados do usuário
    retornaVetorImparPar(vetor, A, B); // Separa os elementos em A e B e imprime os dois vetores

    return 0; // Finaliza o programa
}

// Função para preencher o vetor principal
void preencherVetor(int vetor[])
{
    int i;
    // Percorre todas as posições do vetor (0 a TAM-1)
    for (i = 0; i < TAM; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita valor para o índice i
        scanf("%d", &vetor[i]);       // Lê e armazena o valor na posição i
    }
}

// Função que separa os elementos do vetor principal em dois vetores:
// um contendo elementos de índices pares (vetorA) e outro com índices ímpares (vetorB),
// e imprime esses dois vetores
void retornaVetorImparPar(int vetor[], int vetorA[], int vetorB[])
{
    int i;
    int vetA = 0; // Contador para posição atual em vetorA
    int vetB = 0; // Contador para posição atual em vetorB

    // Percorre todo o vetor principal
    for (i = 0; i < TAM; i++)
    {
        if (i % 2 == 0) // Se o índice for par
        {
            vetorA[vetA] = vetor[i]; // Copia o elemento para vetorA na posição vetA
            vetA++;                  // Incrementa contador de vetorA
        }
        else // Se o índice for ímpar
        {
            vetorB[vetB] = vetor[i]; // Copia o elemento para vetorB na posição vetB
            vetB++;                  // Incrementa contador de vetorB
        }
    }

    // Imprime vetor A (elementos de índices pares)
    printf("A = {");
    for (i = 0; i < vetA; i++)
    {
        printf("%d", vetorA[i]);
        if (i < vetA - 1) // Para não imprimir vírgula no final
            printf(", ");
    }
    printf("}\n");

    // Imprime vetor B (elementos de índices ímpares)
    printf("B = {");
    for (i = 0; i < vetB; i++)
    {
        printf("%d", vetorB[i]);
        if (i < vetB - 1) // Para não imprimir vírgula no final
            printf(", ");
    }
    printf("}\n");
}

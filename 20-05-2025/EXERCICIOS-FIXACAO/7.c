// 7. Dado dois vetores A e B contendo 10 elementos inteiros cada, gerar e exibir um vetor C do mesmo
// tamanho cujos elementos sejam a soma dos respectivos elementos de A e B.
// Exemplo:
// 0 1 2 8 9
// A = 23 37 30 . . . 45 35
// B = 30 32 46 . . . 33 42
// C = 53 69 76 . . . 88 77


#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados

// Protótipos das funções
void preencherVetor(int vetorA[], int vetorB[]);                 // Preenche os vetores A e B
void geraVetorC(int vetorA[], int vetorB[], int vetorC[]);       // Gera o vetor C como soma de A e B

int main()
{
    int A[10], B[10], C[10]; // Declaração dos vetores A, B e C com 10 elementos cada

    // Chamada da função para preencher os vetores A e B
    preencherVetor(A, B);

    // Chamada da função para gerar o vetor C (soma dos vetores A e B)
    geraVetorC(A, B, C);

    // Impressão do vetor C
    printf("\nC = [ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", C[i]);
    }
    printf("]\n"); // Fecha o colchete e quebra linha

    return 0; // Encerra o programa
}

// ==========================
// Função para preencher os vetores A e B
// ==========================
void preencherVetor(int vetorA[], int vetorB[])
{
    for (int i = 0; i < 10; i++) // Laço que percorre cada posição dos vetores de 0 até 9
    {
        // Solicita ao usuário que informe um valor para o vetor A na posição i
        printf("\nValor Vetor A [%d]: ", i);
        scanf("%d", &vetorA[i]);

        // Solicita ao usuário que informe um valor para o vetor B na posição i
        printf("Valor Vetor B [%d]: ", i);
        scanf("%d", &vetorB[i]);
    }
}

// ==========================
// Função que gera o vetor C como soma dos vetores A e B
// ==========================
void geraVetorC(int vetorA[], int vetorB[], int vetorC[])
{
    for (int i = 0; i < 10; i++)
    {
        vetorC[i] = vetorA[i] + vetorB[i]; // Soma os elementos de A e B e armazena em C
    }
}

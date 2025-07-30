// 6. Dado um vetor A contendo 5 elementos inteiros, gerar e exibir um vetor B cujos elementos estão na
// ordem inversa de A.
// Exemplo:
// 0 1 3 4
// A = 23 37 . . . 20 26
// B = 26 20 . . . 37 23

#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados

// Protótipos das funções que serão usadas no programa
void preencherVetor(int vetor[]);        // Função para preencher o vetor com dados informados pelo usuário
void imprimir_vetor(int vetor[]);        // Função para imprimir os elementos do vetor na ordem normal
void imprimirVetor_inverso(int vetor[]); // Função para imprimir os elementos do vetor na ordem inversa

int main()
{
    int vetor[5]; // Declaração de um vetor com 5 elementos inteiros

    // Chamada da função para preencher o vetor com valores informados pelo usuário
    preencherVetor(vetor);

    // Chamada da função para exibir o vetor na ordem original
    imprimir_vetor(vetor);

    // Chamada da função para exibir o vetor na ordem inversa
    imprimirVetor_inverso(vetor);

    return 0; // Encerra o programa
}

// ==========================
// Função para preencher o vetor
// ==========================
void preencherVetor(int vetor[])
{
    int i;
    // Laço que percorre cada posição do vetor de 0 até 4
    for (i = 0; i < 5; i++)
    {
        // Solicita ao usuário que informe um valor para cada posição do vetor
        printf("\n Valor [%d]: ", i);
        scanf("%d", &vetor[i]); // Lê e armazena o valor na posição correspondente
    }
}

// ==========================
// Função para imprimir o vetor na ordem normal
// ==========================
void imprimir_vetor(int vetor[])
{
    int i;
    printf("A = [ ");
    // Laço que percorre o vetor na ordem direta, do primeiro ao último elemento
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]); // Imprime cada valor seguido de espaço
    }
    printf("]\n"); // Fecha o vetor e pula uma linha
}

// ==========================
// Função para imprimir o vetor na ordem inversa
// ==========================
void imprimirVetor_inverso(int vetor[])
{
    int i;
    printf("B = [ ");
    // Laço que percorre o vetor de trás para frente (do último índice para o primeiro)
    for (i = 4; i >= 0; i--)
    {
        printf("%d ", vetor[i]); // Imprime cada valor na ordem inversa
    }
    printf("]\n"); // Fecha o vetor e pula uma linha
}

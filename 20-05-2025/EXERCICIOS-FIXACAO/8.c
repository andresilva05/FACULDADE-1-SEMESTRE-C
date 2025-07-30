// 8. Dado dois vetores A e B contendo 10 elementos inteiros cada, gerar e exibir um vetor C de 20 elementos,
// cujos elementos sejam a intercalação dos elementos de A e B.
// Exemplo:
//      0 1 2 8 9
// A = 23 37 30 . . . 38 55
// B = 30 32 46 . . . 43 49
// 0 1 2 3 4 5 17 18 19
// C = 23 30 37 32 30 46 . . . 43 55 49

#include <stdio.h>

#define TAM 10   // Tamanho dos vetores A e B
#define TAM_C 20 // Tamanho do vetor C, que é o dobro

// Função para preencher um vetor com valores digitados pelo usuário
void preencherVetor(int vetor[], char nome[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o valor %d do vetor %s: ", i, nome);
        scanf("%d", &vetor[i]);
    }
}

// Função para exibir um vetor
void exibirVetor(int vetor[], int tamanho, char nome[])
{
    printf("\nVetor %s: ", nome);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para gerar o vetor C intercalando os vetores A e B
void intercalarVetores(int vetorA[], int vetorB[], int vetorC[])
{
    int i, j = 0;

    for (i = 0; i < TAM; i++)
    {
        vetorC[j] = vetorA[i]; // Pega um elemento de A
        j++;
        vetorC[j] = vetorB[i]; // Pega um elemento de B
        j++;
    }
}

int main()
{
    int vetorA[TAM], vetorB[TAM], vetorC[TAM_C];

    // Preenchendo os vetores A e B
    preencherVetor(vetorA, "A");
    preencherVetor(vetorB, "B");

    // Gerando o vetor C com intercalação
    intercalarVetores(vetorA, vetorB, vetorC);

    // Exibindo os vetores
    exibirVetor(vetorA, TAM, "A");
    exibirVetor(vetorB, TAM, "B");
    exibirVetor(vetorC, TAM_C, "C (Intercalado)");

    return 0;
}

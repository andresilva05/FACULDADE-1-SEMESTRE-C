// 3. Fazer um programa que leia um vetor A contendo 8 números inteiros, calcule e exiba:
// a) O maior elemento;
// b) A posição (índice) do maior elemento.

#include <stdio.h>

void maiorElemento(int maiorVetor[]);
int main()
{
    int A[8]; // Declaração de um vetor de 5 inteiros
    int i;    // Variável auxiliar usada como índice

    // Preenchimento do vetor com valores informados pelo usuário
    for (i = 0; i < 8; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita valor para a posição 'i'
        scanf("%d", &A[i]);           // Lê e armazena o valor digitado no vetor
    }

    maiorElemento(A);

    return 0; // Finaliza o programa com sucesso
}

// Função que imprime os elementos do vetor na ordem em que foram inseridos
void maiorElemento(int maiorVetor[])
{

    int maiorNumero = maiorVetor[0];
    int i, posicaoMaior = 0;

    for (i = 1; i < 8; i++)
    {
        if (maiorVetor[i] > maiorNumero)
        {
            maiorNumero = maiorVetor[i];
            posicaoMaior = i;
        }
    }
    printf("Maior numero: %d\n", maiorNumero);
    printf("Posicao do maior numero eh: %d", posicaoMaior);
}
// Escreva uma função que, dado um vetor ordenado, forneça a maior diferença entre dois elementos
// consecutivos, fornecendo também as posições dos elementos que geraram esta maior diferença.
// Por exemplo, se o vetor dado for v = {3, 5, 9, 16, 17, 20, 26, 31}, a função deve fornecer como maior
// diferença o valor 7 (16 - 9) e as posições 4 e 3
#include <stdio.h>

#define TAM 8 // Define o tamanho do vetor

// Protótipos das funções
void preencherVetor(int vetor[]);
void maior_diferenca(int vetor[]);

// Função principal
int main()
{
    int vetor[TAM]; // Declara o vetor com tamanho definido

    preencherVetor(vetor); // Chama a função para preencher o vetor

    maior_diferenca(vetor); // Chama a função para calcular a maior diferença

    return 0;
}

// Função para preencher o vetor com valores fornecidos pelo usuário
void preencherVetor(int vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]); // Lê cada elemento do vetor
    }
}

// Função que calcula a maior diferença entre dois elementos consecutivos
void maior_diferenca(int vetor[])
{
    int i;
    int maiorDiferenca = 0; // Armazena a maior diferença encontrada
    int diferenca;          // Diferença temporária entre dois elementos
    int posicao1, posicao2; // Armazenam as posições dos elementos que geram a maior diferença

    // Percorre o vetor até o penúltimo elemento
    for (i = 0; i < TAM - 1; i++)
    {
        // Calcula a diferença entre o elemento atual e o próximo
        diferenca = vetor[i + 1] - vetor[i];

        // Verifica se essa diferença é maior que a maior encontrada até agora
        if (diferenca > maiorDiferenca)
        {
            maiorDiferenca = diferenca; // Atualiza a maior diferença

            // Guarda as posições dos elementos que geraram essa maior diferença
            posicao1 = i;     // Posição do elemento atual
            posicao2 = i + 1; // Posição do próximo elemento
        }
    }

    // Exibe o resultado
    printf("\nMaior diferenca: %d\n", maiorDiferenca);
    printf("Entre as posicoes: %d (direita) e %d (esquerda)\n", posicao2, posicao1);
}

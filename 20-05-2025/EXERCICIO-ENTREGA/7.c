// 7. O(s) valor(es) de maior frequência de uma relação de valores numéricos é(são) chamado(s) moda
// da relação. Escreva um programa que leia um conjunto de notas escolares maiores do que zero e
// menores do que ou iguais a 10, com uma casa decimal, e forneça a(s) moda(s) desta relação. Por
// exemplo, se a relação de notas for v = {8,0; 3,5, 4,5; 8,0; 6,0; 4,5; 6,0; 3,5; 2,5; 6,0; 9,0} o programa
// deve fornecer o valor 6,0 (frequência 3).

#include <stdio.h>

#define TAM 11
// Função para preencher o vetor com notas válidas (0 < nota <= 10)
void preencherVetor(float vetor[])
{
    int i;

    for (i = 0; i < TAM; i++) // Percorre todas as posições do vetor
    {
        do
        {
            printf("Digite a nota [%d]: ", i);
            scanf("%f", &vetor[i]); // Lê a nota como float

            // Verifica se a nota é inválida (maior que 10 ou menor/igual a 0)
            if (vetor[i] > 10 || vetor[i] <= 0)
            {
                printf("Valor invalido! Digite uma nota entre 0 e 10.\n");
            }

        } while (vetor[i] > 10 || vetor[i] <= 0);
        // Repete a leitura enquanto a nota for inválida
    }
}

void forneceModa(float vetor[]);

int main()
{
    float vetor[TAM];

    preencherVetor(vetor); // Preenche o vetor com notas válidas
    forneceModa(vetor);    // Calcula e imprime a(s) moda(s)

    return 0;
}

// Função para calcular e mostrar a(s) moda(s) do vetor
void forneceModa(float vetor[])
{
    int i, j, frequencia = 0;

    // vetorAuxiliar guarda quantas vezes cada elemento aparece
    int vetorAuxiliar[TAM] = {0}; // inicializa com zero

    // Conta a frequência de cada elemento
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (vetor[i] == vetor[j])
            {
                vetorAuxiliar[i]++;
            }
        }
    }

    // Encontra a maior frequência
    for (i = 0; i < TAM; i++)
    {
        if (vetorAuxiliar[i] > frequencia)
        {
            frequencia = vetorAuxiliar[i];
        }
    }

    printf("\nMaior frequencia: %d\n", frequencia);

    // Vetor para controlar quais modas já foram impressas (evitar repetição)
    int jaImprimi[TAM] = {0};

    // Imprime todas as modas (valores com frequência máxima) uma única vez
    for (i = 0; i < TAM; i++)
    {
        if (vetorAuxiliar[i] == frequencia && !jaImprimi[i])
        {
            printf("Valor com essa frequencia: %.1f\n", vetor[i]);

            // Marca todas as posições com o mesmo valor para não imprimir de novo
            for (int k = i; k < TAM; k++)
            {
                if (vetor[k] == vetor[i])
                {
                    jaImprimi[k] = 1;
                }
            }
        }
    }
}
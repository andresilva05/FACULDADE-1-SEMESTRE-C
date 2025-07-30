// '📝 Exercício 5 – Menor Valor por Linha na Matriz
// Escreva um programa em C que leia os valores de uma matriz, determine o menor valor de cada linha e informe o índice da coluna correspondente a esse menor valor.

// ✅ O que o programa deve fazer:
// Para cada linha da matriz:

// Encontrar o menor valor daquela linha.

// Informar a posição da coluna (índice) onde esse menor valor se encontra.

// 📥 Exemplo de Entrada:
// Suponha que a matriz seja de tamanho 3x4:

// Linha 1: 3   7   4   6
// Linha 2: 5   2   5   4
// Linha 3: 2   6   5   1
// 📤 Saída Esperada:
// A saída do programa deve mostrar algo como:

// Linha     Menor Valor     Coluna
// 1         3               1
// 2         2               2
// 3         1               4
// 🧠 Observação: os índices de colunas e linhas podem começar em 0 ou 1, dependendo da forma que você quiser apresentar ao usuário. Se quiser manter intuitivo, comece a contagem em 1 (como no exemplo acima).

#include <stdio.h>
#define LINHA 3
#define COLUNA 4

void retornaMenorValorMatriz(int matriz[LINHA][COLUNA]);

int main()
{
    int i, j, matriz[LINHA][COLUNA];

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("\nValor[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    retornaMenorValorMatriz(matriz);
}

void retornaMenorValorMatriz(int matriz[LINHA][COLUNA])
{
    int i, j, colunaMenorValor;

    printf("Linha     Menor Valor     Coluna\n");
    for (i = 0; i < LINHA; i++)
    {
        int menor = matriz[i][0];
        colunaMenorValor = 0;
        for (j = 0; j < COLUNA; j++)
        {

            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                colunaMenorValor = j;
            }
        }
        printf(" %d             %d              %d\n", i, menor, colunaMenorValor);
    }
}
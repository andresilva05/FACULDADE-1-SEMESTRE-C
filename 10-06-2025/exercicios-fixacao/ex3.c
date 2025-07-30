// 3. Moda de uma matriz

// Escreva uma função que receba uma matriz M x N de valores inteiros e retorne a moda (o valor que ocorre com maior frequência) dessa matriz.

// 4. Médias das linhas de uma matriz

// Escreva uma função que receba uma matriz M x N de valores inteiros e calcule a média aritmética de cada linha, retornando um vetor com essas médias.

// Exemplo:

// Matriz original (4 linhas x 3 colunas):

// 3 7 4
// 6 5 4
// 5 4 2
// 6 5 1
// Vetor de médias retornado:

// 4.67 5.00 3.67 4.00

#include <stdio.h>

#define LINHA 4
#define COLUNA 3

// Protótipos das funções
int calculaModa(int matriz[LINHA][COLUNA]);
void calculaMediaLinhas(int matriz[LINHA][COLUNA], float medias[LINHA]);

int main()
{
    int matriz[LINHA][COLUNA] = {
        {3, 7, 4},
        {6, 5, 4},
        {5, 4, 2},
        {6, 5, 1}};
    float medias[LINHA];
    int moda, i;

    // Calcula a moda da matriz
    moda = calculaModa(matriz);
    printf("Moda da matriz: %d\n", moda);

    // Calcula a média de cada linha
    calculaMediaLinhas(matriz, medias);

    printf("Médias das linhas:\n");
    for (i = 0; i < LINHA; i++)
    {
        printf("Linha %d: %.2f\n", i + 1, medias[i]);
    }

    return 0;
}

// Função que calcula a moda da matriz
int calculaModa(int matriz[LINHA][COLUNA])
{
    int i, j, k, l;
    int valor, count;
    int moda = matriz[0][0];
    int maxCount = 0;

    // Percorre todos os elementos da matriz para contar frequências
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            valor = matriz[i][j];
            count = 0;

            // Conta quantas vezes o valor atual aparece na matriz
            for (k = 0; k < LINHA; k++)
            {
                for (l = 0; l < COLUNA; l++)
                {
                    if (matriz[k][l] == valor)
                    {
                        count++;
                    }
                }
            }

            // Atualiza a moda se encontrar valor com maior frequência
            if (count > maxCount)
            {
                maxCount = count;
                moda = valor;
            }
        }
    }

    return moda;
}

// Função que calcula as médias das linhas da matriz
void calculaMediaLinhas(int matriz[LINHA][COLUNA], float medias[LINHA])
{
    int i, j;
    int soma;

    for (i = 0; i < LINHA; i++)
    {
        soma = 0;

        // Soma os elementos da linha i
        for (j = 0; j < COLUNA; j++)
        {
            soma += matriz[i][j];
        }

        // Calcula média e armazena no vetor medias
        medias[i] = (float)soma / COLUNA;
    }
}

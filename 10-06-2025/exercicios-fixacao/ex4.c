#include <stdio.h>
#define LINHA 3  // Define quantidade de linhas da matriz
#define COLUNA 4 // Define quantidade de colunas da matriz

// Função para entrada de valores na matriz
void entradaValores(float matriz[LINHA][COLUNA])
{
    int i, j;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            // Solicita ao usuário o valor para a posição [i][j]
            printf("\nValor [%d] [%d]:", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

// Protótipo da função que irá calcular e exibir a média de cada linha
float calculaMedia(float matriz[LINHA][COLUNA]);

int main()
{
    float matriz[LINHA][COLUNA]; // Declara a matriz 3x4
    entradaValores(matriz);      // Chama a função para preencher a matriz
    calculaMedia(matriz);        // Chama a função para calcular e mostrar as médias
    return 0;
}

// Função que calcula a média de cada linha da matriz
float calculaMedia(float matriz[LINHA][COLUNA])
{
    int i, j;
    float media = 0.0; // Variável para armazenar a média de uma linha
    float soma = 0.0;  // Variável para somar os elementos de uma linha

    printf("\nDados armazenados na matriz:\n");

    // Primeiro, imprime todos os valores da matriz
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            // Exibe cada valor da matriz com 2 casas decimais
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    // Agora, calcula e imprime a média de cada linha
    for (i = 0; i < LINHA; i++)
    {
        soma = 0.0; // Zera a soma antes de começar uma nova linha

        for (j = 0; j < COLUNA; j++)
        {
            soma = soma + matriz[i][j]; // Soma os elementos da linha
        }

        media = soma / COLUNA; // Calcula a média da linha atual

        // Imprime o número da linha e a média correspondente
        printf("Linha [%d] <- ", i);
        printf(" Media: %.2f \n", media);
    }
}

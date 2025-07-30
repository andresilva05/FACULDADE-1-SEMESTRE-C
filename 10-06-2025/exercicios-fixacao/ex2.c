#include <stdio.h>

// Define o tamanho fixo da matriz: 4 linhas por 3 colunas
#define M 4
#define N 3

// Protótipos das funções que trabalham com números reais (float)
float maiorValor(float matriz[M][N]);
float menorValor(float matriz[M][N]);
void calculaAmplitude(float matriz[M][N]);

int main()
{
    // Declara a matriz 4x3 com números reais já preenchidos
    float matriz[M][N] = {
        {10.5, 5.2, 8.3},
        {9.1, 11.4, 4.6},
        {12.0, 20.8, 1.7},
        {2.2, 3.9, 7.3}};

    /*
    // Se quiser fazer leitura manual da matriz pelo usuário, descomente esse trecho:
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("\nValor [%d][%d]: ", i, j); // Mostra em qual posição da matriz será armazenado o valor
            scanf("%f", &matriz[i][j]);        // Lê e armazena o valor digitado na posição [i][j]
        }
    }
    */

    // Exibe o maior e o menor valor da matriz
    printf("Maior valor eh: %.2f\n", maiorValor(matriz));
    printf("Menor valor eh: %.2f\n", menorValor(matriz));

    // Chama a função para calcular e exibir a amplitude
    calculaAmplitude(matriz);

    return 0;
}

// Função que retorna o maior valor encontrado na matriz
float maiorValor(float matriz[M][N])
{
    // Inicializa o maior valor como o primeiro elemento da matriz
    float maior = matriz[0][0];

    // Percorre todas as posições da matriz
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Se o valor atual for maior que o armazenado, atualiza
            if (maior < matriz[i][j])
            {
                maior = matriz[i][j];
            }
        }
    }

    return maior; // Retorna o maior valor encontrado
}

// Função que retorna o menor valor encontrado na matriz
float menorValor(float matriz[M][N])
{
    // Inicializa o menor valor como o primeiro elemento da matriz
    float menor = matriz[0][0];

    // Percorre todas as posições da matriz
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Se o valor atual for menor que o armazenado, atualiza
            if (menor > matriz[i][j])
            {
                menor = matriz[i][j];
            }
        }
    }

    return menor; // Retorna o menor valor encontrado
}

// Função que calcula e exibe a amplitude (diferença entre maior e menor)
void calculaAmplitude(float matriz[M][N])
{
    float maior = maiorValor(matriz); // Obtém o maior valor da matriz
    float menor = menorValor(matriz); // Obtém o menor valor da matriz
    float amplitude = maior - menor;  // Calcula a diferença (amplitude)

    // Exibe a amplitude com duas casas decimais
    printf("Amplitude eh: %.2f\n", amplitude);
}

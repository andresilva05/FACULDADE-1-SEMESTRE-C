// 1.Fazer um programa que leia uma matriz A de dimensão 4 x 3 contendo números inteiros, calcule e exiba:

// a) o maior valor;

// b) a posição (índices) do maiorelemento.

// Entrada: o usuario deve entrar com uma matriz de numeros inteitos, chamada de A.

// A dimensão de A é 4x3, ou seja, a declaração será de int A[4][3];

// O usuário deverá digitar os valores de cada posição de A;

// Saída: O programa deve percorrer a matriz A, achar o maior valor e indicar os indices.

#include <stdio.h> // Biblioteca padrão para entrada e saída

#define LINHA 4  // Define a constante para o número de linhas da matriz
#define COLUNA 3 // Define a constante para o número de colunas da matriz

// Declaração da função que irá encontrar e mostrar o maior valor e seus índices
void maiorValor(int A[LINHA][COLUNA]);

int main()
{
    int A[LINHA][COLUNA]; // Declara a matriz A com tamanho 4x3

    // Leitura dos valores da matriz pelo usuário
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("\n Valor [%d][%d]: ", i, j); // Mostra em qual posição da matriz será armazenado o valor
            scanf("%d", &A[i][j]);               // Lê e armazena o valor digitado na posição [i][j]
        }
    }

    // Chamada da função que calcula o maior valor e sua posição
    maiorValor(A);

    return 0; // Fim do programa
}

// Função que encontra o maior valor e sua posição na matriz
void maiorValor(int A[LINHA][COLUNA])
{
    // Inicializa o maior valor como o primeiro elemento da matriz
    int i, j, maior = A[0][0], linhaMaior = 0, colunaMaior = 0;

    // Percorre todas as posições da matriz
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            // Se encontrar um valor maior do que o atual...
            if (maior < A[i][j])
            {
                maior = A[i][j]; // Atualiza o maior valor
                linhaMaior = i;  // Salva o índice da linha
                colunaMaior = j; // Salva o índice da coluna
            }
        }
    }

    // Exibe o maior valor encontrado e sua posição
    printf("Maior valor eh: %d\n", maior);
    printf("Indice: [%d][%d]\n", linhaMaior, colunaMaior);
}

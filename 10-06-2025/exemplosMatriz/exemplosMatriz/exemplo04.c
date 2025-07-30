#include <stdio.h> // Biblioteca padrão para entrada e saída de dados

// Definindo o tamanho da matriz usando constantes
#define LINHA 5  // Número de linhas da matriz
#define COLUNA 2 // Número de colunas da matriz

// Declaração das funções que serão usadas
void inicializarMatriz(int mat[LINHA][COLUNA]); // Função para preencher a matriz com valores digitados
void imprimirMatriz(int mat[LINHA][COLUNA]);    // Função para exibir os valores da matriz

int main()
{
   int mat[LINHA][COLUNA]; // Declaração da matriz 5x2

   // Chamada da função para preencher a matriz com dados do usuário
   inicializarMatriz(mat);

   // Chamada da função para imprimir a matriz na tela
   imprimirMatriz(mat);

   return 0; // Finaliza o programa com sucesso
}

// Função que lê os valores da matriz a partir da entrada do usuário
void inicializarMatriz(int mat[LINHA][COLUNA])
{
   // Percorre todas as posições da matriz
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         // Solicita ao usuário o valor para a posição [i][j]
         printf("\n Valor [%d][%d]: ", i, j);
         scanf("%d", &mat[i][j]); // Lê o valor e armazena na matriz
      }
   }
}

// Função que imprime os valores armazenados na matriz
void imprimirMatriz(int mat[LINHA][COLUNA])
{
   printf("\nDados armazenados na matriz:\n");

   // Percorre e imprime cada valor da matriz
   for (int i = 0; i < LINHA; i++)
   {
      for (int j = 0; j < COLUNA; j++)
      {
         // Exibe o valor armazenado na posição [i][j]
         printf("%d ", mat[i][j]);
      }
      // Quebra de linha após imprimir cada linha da matriz
      printf("\n");
   }
}

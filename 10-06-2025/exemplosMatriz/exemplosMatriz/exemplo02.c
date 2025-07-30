#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

// Definindo constantes para o tamanho da matriz
#define LINHA 5  // Número de linhas
#define COLUNA 2 // Número de colunas

int main()
{
   int i, j;               // Variáveis para controlar os loops
   int mat[LINHA][COLUNA]; // Declaração da matriz 5x2

   // Leitura dos valores da matriz
   for (i = 0; i < LINHA; i++)
   { // Loop externo percorre as linhas
      for (j = 0; j < COLUNA; j++)
      {                                       // Loop interno percorre as colunas
         printf("\n Valor [%d][%d]: ", i, j); // Pede o valor para cada posição
         scanf("%d", &mat[i][j]);             // Armazena o valor lido na posição correspondente da matriz
      }
   }

   // Exibição dos valores armazenados na matriz
   printf("\nDados armazenados na matriz:\n");
   for (i = 0; i < LINHA; i++)
   { // Percorre as linhas
      for (j = 0; j < COLUNA; j++)
      {                            // Percorre as colunas
         printf("%d ", mat[i][j]); // Imprime o valor da matriz na posição [i][j]
      }
      printf("\n"); // Quebra de linha para mostrar a matriz como uma tabela
   }

   return 0; // Indica que o programa terminou com sucesso
}

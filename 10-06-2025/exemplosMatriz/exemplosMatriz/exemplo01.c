#include <stdio.h> // Biblioteca padrão de entrada e saída (necessária para usar printf)

// Definindo constantes para o tamanho da matriz
#define LINHA 5  // Número de linhas da matriz
#define COLUNA 2 // Número de colunas da matriz

int main()
{
   int i, j; // Variáveis para controle dos loops

   // Declaração e inicialização da matriz 5x2 com valores inteiros
   int mat[LINHA][COLUNA] = {
       {0, 1},
       {10, 11},
       {20, 21},
       {30, 31},
       {40, 41}};

   // Exibindo os dados da matriz
   printf("\nDados armazenados na matriz\n");

   // Loop externo percorre as linhas da matriz
   for (i = 0; i < LINHA; i++)
   {
      // Loop interno percorre as colunas da matriz
      for (j = 0; j < COLUNA; j++)
      {
         // Exibe o valor armazenado na posição [i][j] da matriz
         printf("%d ", mat[i][j]);
      }
      // Quebra de linha após imprimir cada linha da matriz
      printf("\n");
   }

   return 0; // Fim do programa
}

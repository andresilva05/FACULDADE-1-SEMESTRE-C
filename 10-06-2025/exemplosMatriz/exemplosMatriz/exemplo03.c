#include <stdio.h> // Biblioteca padrão para entrada e saída (necessária para printf)

// Definindo constantes para facilitar manutenção do código
#define LINHA 5  // Número de linhas da matriz
#define COLUNA 2 // Número de colunas da matriz

// Declaração da função que irá imprimir os valores da matriz
void imprimirMatriz(int mat[LINHA][COLUNA]);

int main()
{
   // Inicialização da matriz 5x2 com valores fixos
   int mat[LINHA][COLUNA] = {
       {0, 1},
       {10, 11},
       {20, 21},
       {30, 31},
       {40, 41}};

   // Chamada da função para exibir os valores da matriz
   imprimirMatriz(mat);

   return 0; // Finaliza o programa com sucesso
}

// Função que percorre e imprime todos os valores da matriz
void imprimirMatriz(int mat[LINHA][COLUNA])
{
   printf("\nDados armazenados na matriz:\n");

   // Laço externo percorre cada linha
   for (int i = 0; i < LINHA; i++)
   {
      // Laço interno percorre cada coluna da linha atual
      for (int j = 0; j < COLUNA; j++)
      {
         // Imprime o valor da posição [i][j]
         printf("%d ", mat[i][j]);
      }
      // Quebra de linha para mostrar a próxima linha da matriz
      printf("\n");
   }
}

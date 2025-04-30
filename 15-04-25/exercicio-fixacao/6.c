#include <stdio.h> // Biblioteca necessária para funções de entrada e saída
#include <math.h>  // Biblioteca para usar a função sqrt() (raiz quadrada)

//Consegui fazer até media, o desvio não.

int main()
{
  int qtdNum = 0;                                              // Variável para contar a quantidade de números positivos digitados
  float media, soma = 0, num, desvioPadrao, somaQuadrados = 0; // Variáveis para armazenar a média, soma, o número atual, desvio padrão e soma dos quadrados

  // Laço while que continuará até que o usuário digite 0 (condição de parada)
  while (num > 0) // Condição para entrar no loop (num deve ser maior que 0)
  {
    printf("Digite um numero (digite 0 para sair): \n"); // Solicita ao usuário que digite um número
    scanf("%f", &num);              // Lê o número digitado pelo usuário e armazena na variável num

    soma = soma + num;          // Soma o número digitado à variável soma
    somaQuadrados += num * num; // Soma o quadrado do número à variável somaQuadrados

    if (num > 0) // Verifica se o número digitado é positivo
    {
      qtdNum++; // Se for positivo, incrementa a quantidade de números digitados
    }
  }

  // Se pelo menos um número positivo foi digitado, realiza os cálculos
  if (qtdNum > 0)
  {
    media = soma / qtdNum;                                           // Calcula a média dos números digitados
    desvioPadrao = sqrt((somaQuadrados / qtdNum) - (media * media)); // Calcula o desvio padrão usando a fórmula

    // Exibe a soma, média e desvio padrão com a formatação apropriada
    printf("Soma: %.0f\n", soma);                  // Exibe a soma total com 0 casas decimais
    printf("Media: %.2f\n", media);                // Exibe a média com 2 casas decimais
    printf("Desvio Padrao: %.2f\n", desvioPadrao); // Exibe o desvio padrão com 2 casas decimais
  }
  else
  {
    printf("Nenhum número foi digitado.\n"); // Caso o usuário não tenha digitado nenhum número positivo
  }

  return 0; // Retorna 0, indicando que o programa terminou com sucesso
}

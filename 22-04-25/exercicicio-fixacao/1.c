// Exercício 1. Escreva um programa que leia três números inteiros e indique qual o menor valor dentre
// eles. O cálculo deve ser feito em uma função.

// Assinatura: int Menor(int n1, int n2, int n3);

#include <stdio.h> // Biblioteca padrão de entrada e saída

// Declaração (protótipo) da função que retorna o menor de três inteiros
int Menor(int n1, int n2, int n3);

int main()
{
    int num1, num2, num3; // Declara três variáveis para armazenar os números digitados

    // Pede ao usuário que digite três números inteiros
    printf("Digite o valor de tres numeros inteiros (diferentes um do outro): \n");
    scanf("%d %d %d", &num1, &num2, &num3); // Lê os três números digitados

    // Chama a função menor() e imprime o menor dos três números
    printf("O menor numero eh = %d", Menor(num1, num2, num3));

    return 0; // Indica que o programa terminou com sucesso
}

// Implementação da função que retorna o menor entre três números
int menor(int n1, int n2, int n3)
{
    // Compara os três números para descobrir qual é o menor
    if (n1 < n2 && n1 < n3)
        return n1; // Retorna n1 se ele for menor que n2 e n3
    else if (n2 < n1 && n2 < n3)
        return n2; // Retorna n2 se ele for menor que n1 e n3
    else
        return n3; // Caso contrário, retorna n3 (ou se houver igualdade entre dois menores)
}

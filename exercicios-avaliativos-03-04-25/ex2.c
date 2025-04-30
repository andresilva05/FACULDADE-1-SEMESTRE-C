// Um programa para gerenciar os saques de um caixa eletrônico deve possuir um
// mecanismo para decidir o número de notas de cada valor que deve ser disponibilizado para o cliente
// que realizou o saque. O critério da distribuição ótima tenta distribuir as notas de menor valor em
// número mínimo possível.
// Por exemplo, considere que a máquina só dispõe de notas de R$ 50, de R$ 10, de R$ 5 e de
// R$ 1. Para uma quantia solicitada de R$ 87, o programa deve indicar uma nota de R$ 50,
// três notas de R$ 10, uma nota de R$ 5 e duas notas de R$ 1.
// Escreva um programa que receba o valor da quantia solicitada e retorne a distribuição das
// notas de acordo com o critério da distribuição ótima.

#include <stdio.h>

int main()
{
    // Definição dos valores das notas disponíveis
    int valueNota50 = 50;
    int valueNota10 = 10;
    int valueNota5 = 5;
    int valueNota1 = 1;

    // Variáveis para armazenar o valor solicitado e o restante do valor a ser distribuído
    int valueQuantia, resto;

    // Variáveis para armazenar a quantidade de cada nota
    int qtdNota50, qtdNota10, qtdNota5, qtdNota1;

    // Solicita ao usuário que informe o valor a ser sacado
    printf("Digite o valor da quantia solicitada: ");
    scanf("%d", &valueQuantia);

    qtdNota50 = valueQuantia / valueNota50;
    resto = valueQuantia % valueNota50;

    qtdNota10 = resto / valueNota10;
    resto = resto % valueNota10;

    qtdNota5 = resto / valueNota5;
    resto = resto % valueNota5;

    qtdNota1 = resto / valueNota1;

    printf("Quantidade de notas de R$ 50: %d\n", qtdNota50);
    printf("Quantidade de notas de R$ 10: %d\n", qtdNota10);
    printf("Quantidade de notas de R$ 5: %d\n", qtdNota5);
    printf("Quantidade de notas de R$ 1: %d\n", qtdNota1);
    return 0;
}
// Somar duas frações ordinárias, fornecendo o resultado em forma de fração

#include <stdio.h> // Biblioteca para entrada e saída de dados

int main()
{
    // Declaração das variáveis para as frações e o resultado
    int numerador1, denominador1; // Primeira fração
    int numerador2, denominador2; // Segunda fração
    int resultNum, resultDen;     // Resultado da soma (numerador e denominador)

    // Entrada da primeira fração
    printf("Fração 1 \n\n");
    printf("Digite o numero do numerador: \n");
    scanf("%d", &numerador1); // Lê o numerador da primeira fração

    printf("Digite o numero do denominador:\n");
    scanf("%d", &denominador1); // Lê o denominador da primeira fração

    // Entrada da segunda fração
    printf("Fração 2 \n\n");
    printf("Digite o numero do numerador: \n");
    scanf("%d", &numerador2); // Lê o numerador da segunda fração

    printf("Digite o numero do denominador:\n");
    scanf("%d", &denominador2); // Lê o denominador da segunda fração

    // Calcula o novo denominador comum (multiplicação dos dois)
    resultDen = denominador1 * denominador2;

    // Calcula o novo numerador ajustado com base no denominador comum
    // Exemplo: (resultDen / denominador1) dá o fator de multiplicação para ajustar a fração
    resultNum = (resultDen / denominador1 * numerador1) + (resultDen / denominador2 * numerador2);

    // Mostra o resultado final da soma das frações
    printf("O resultado será: %d / %d", resultNum, resultDen);

    return 0; // Encerra o programa
}

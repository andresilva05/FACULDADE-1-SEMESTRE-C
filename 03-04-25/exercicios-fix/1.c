// . Escreva programas para converter uma temperatura dada em graus Fahrenheit para
// graus Celsius.
#include <stdio.h> // Biblioteca para entrada e saída de dados

int main()
{
    int grausF;   // Variável para armazenar a temperatura em Fahrenheit (valor inteiro)
    float grausC; // Variável para armazenar a temperatura convertida para Celsius (valor com casas decimais)

    // Pede para o usuário digitar a temperatura em Fahrenheit
    printf("Digite a temperatura em Graus Fahrenheit: \n");
    scanf("%d", &grausF); // Lê o valor digitado e guarda em grausF

    // Converte Fahrenheit para Celsius usando a fórmula correta
    grausC = (grausF - 32) * 5 / 9;

    // Mostra a temperatura convertida com duas casas decimais
    printf("A temperatura em graus Celsius é: %.2f", grausC);

    return 0; // Indica que o programa terminou sem erros
}

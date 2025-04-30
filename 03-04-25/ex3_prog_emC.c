/* Programa que inverte um número com dois algarismos */
#include <stdio.h> // Biblioteca para entrada e saída de dados

int main()
{
    int num, unidades, dezenas, invertido; // Declaração das variáveis inteiras

    // Pede para o usuário digitar um número de dois algarismos (10 a 99)
    printf("Digite um inteiro com dois algarismos: ");
    scanf("%d", &num); // Lê o número digitado e armazena na variável num

    // Obtém o último dígito (unidade) usando o resto da divisão por 10
    unidades = num % 10;

    // Obtém o primeiro dígito (dezena) fazendo uma divisão inteira por 10
    dezenas = num / 10;

    // Monta o número invertido, colocando as unidades na posição da dezena
    invertido = unidades * 10 + dezenas;

    // Exibe o número original e o número invertido
    printf("O inverso de %d e' %d ", num, invertido);

    return 0; // Retorna 0 indicando que o programa terminou corretamente
}

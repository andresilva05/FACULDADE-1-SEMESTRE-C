// Um hotel deseja fazer uma promoção especial de final de semana, concedendo um
// desconto de 25% na diária. O hotel possui 40 apartamentos e o valor normal da diária por
// apartamento é R$ 267,00. Implemente um programa para calcular:

// a) Valor promocional da diária.

// b) Valor total a ser arrecadado caso a ocupação neste final de semana (2 diárias por
// apartamento) atinja 100%.

// c) Valor total a ser arrecadado caso a ocupação neste final de semana atinja 70%;

// d) Valor que o hotel deixará de arrecadar em virtude da promoção, caso a ocupação atinja
// 100%.

#include <stdio.h>

int main()
{
    // Definição do valor da diária normal
    float diaria = 267.00;

    // Variáveis para armazenar os cálculos da promoção e arrecadação
    float promocaoDiaria, desconto, arrecadacao, arrecadacao70, valorNaoArrecadado;

    // Número total de apartamentos disponíveis
    int ocupacao = 40;

    // Cálculo do desconto de 25% sobre a diária normal
    desconto = diaria * 0.25;

    // Cálculo do valor promocional da diária após o desconto
    promocaoDiaria = diaria - desconto;

    // Cálculo da arrecadação total caso a ocupação seja de 100% (2 diárias por apartamento)
    arrecadacao = (promocaoDiaria * 2) * ocupacao;

    // Cálculo da arrecadação total caso a ocupação seja de 70%
    arrecadacao70 = (ocupacao * 0.7) * (promocaoDiaria * 2);

    // Cálculo do valor que o hotel deixará de arrecadar por conta da promoção (caso 100% de ocupação)
    valorNaoArrecadado = ((diaria * 2) * ocupacao) - arrecadacao;

    // Exibe o valor da diária com desconto
    printf("Valor promocional da diária será: R$ %.2f\n", promocaoDiaria);

    // Exibe o valor total arrecadado com 100% de ocupação
    printf("Valor total a ser arrecadado caso a ocupação neste final de semana (2 diárias por apartamento) atinja 100%% eh: R$ %.2f\n", arrecadacao);

    // Exibe o valor total arrecadado com 70% de ocupação
    printf("Valor total a ser arrecadado caso a ocupação neste final de semana atinja 70%% eh: R$ %.2f\n", arrecadacao70);

    // Exibe quanto o hotel deixará de arrecadar devido à promoção (se atingir 100% de ocupação)
    printf("Valor que o hotel deixará de arrecadar em virtude da promoção, caso a ocupação atinja 100%% eh: R$ %.2f\n", valorNaoArrecadado);

    return 0;
}

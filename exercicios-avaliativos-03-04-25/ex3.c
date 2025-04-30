// Dado que um espetáculo teatral tem o custo de R$ 2700,00 e o preço do convite para
// esse espetáculo é R$ 30,00. Faça um programa para calcular e mostrar:

// A quantidade de convites que devem ser vendidos para que, pelo menos, o custo do
// espetáculo seja alcançado.

// A quantidade de convites que devem ser vendidos para que se tenha um lucro de 20%.

#include <stdio.h>

int main()
{
    // Custo total do espetáculo
    float custo = 2700.00;

    // Variável para armazenar o valor do lucro desejado (20% do custo)
    float lucro;

    // Preço de cada convite
    int convites = 30;

    // Variáveis para armazenar a quantidade de convites necessários
    int qtdConvites, lucroConvites;

    // Calcula a quantidade mínima de convites que devem ser vendidos para cobrir o custo
    qtdConvites = custo / convites;

    // Calcula 20% do custo do espetáculo para obter o lucro desejado
    lucro = custo * 0.2;

    // Calcula a quantidade de convites necessários para cobrir o custo + lucro
    lucroConvites = (lucro / 30) + qtdConvites;

    // Exibe a quantidade mínima de convites para cobrir o custo
    printf("A quantidade de convites que devem ser vendidos para que, pelo menos, o custo do espetáculo seja alcançado eh de: %d\n", qtdConvites);

    // Exibe a quantidade de convites para garantir um lucro de 20%
    printf("A quantidade de convites que devem ser vendidos para que se tenha um lucro de 20%% eh de : %d", lucroConvites);

    return 0;
}
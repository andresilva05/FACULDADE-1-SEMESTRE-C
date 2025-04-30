// Exercício 2. O custo ao consumidor de um carro novo é a soma do custo de fábrica com a
// porcentagem do distribuidor e dos impostos, ambos aplicados ao custo de fábrica. Faça um
// algoritmo para ler o custo de fábrica do carro, a porcentagem do distribuidor, a porcentagem
// dos impostos e exiba o custo ao consumidor. Caso o custo ao consumidor seja menor que
// R$100,000.00, conceda um desconto de $1,000.00.

#include <stdio.h>

int main()
{

    float custoFabrica, porcenDistribuidor, porcenImpostos, valueDistribuidor, valueImpostos;
    double custo;

    printf("Digite o custo de fabrica do automovel (em R$): ");

    scanf("%f", &custoFabrica);
    printf("Digite a porcentagem do distribuidor: ");
    printf("Digite a porcentagem do distribuidor: %% \n");
    scanf("%f", &porcenDistribuidor);
    printf("Digite a porcentagem dos impostos: ");
    scanf("%f", &porcenImpostos);

    valueDistribuidor = custoFabrica / 100 * porcenDistribuidor;
    valueImpostos = custoFabrica / 100 * porcenImpostos;

    custo = valueDistribuidor + valueImpostos + custoFabrica;

    if (custo < 100000.00)

    {
        custo = custo - 1000.00;
    }

    printf("O valor total do carro será: R$ %.2f\n", custo);

    return 0;
}
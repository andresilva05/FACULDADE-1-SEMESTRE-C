// Exercício 4. Uma companhia de carros paga a seus vendedores um salário de R$ 1000,00 por mês, mais uma comissão de R$ 500,00 para cada carro vendido e mais 5 % do valor das venda.Caso o vendedor seja gerente, ele ainda receberá um bônus de 1 % sobre as vendas.Faça um programa para calcular e exibir o salário do vendedor num dado mês,
//     recebendo como dados de entrada o CPF do vendedor, o número de carros vendidos, o valor total das vendas e caso seja gerente, o valor de seu bônus.

#include <stdio.h>

int main()
{

    char cpfVendedor[12], gerente;
    int numCarrosVendidos;
    float valueVendas;
    int salario = 1000;
    int comissao = 500;
    float salarioVendedor, porcValueVendas, bonusVendas;

    printf("Digite seu CPF: \n");
    scanf(" %s", &cpfVendedor);

    printf("Digite o numero de carros vendidos: \n");
    scanf("%d", &numCarrosVendidos);

    printf("Digite o valor total das vendas: R$ \n");
    scanf("%f", &valueVendas);

    porcValueVendas = valueVendas * 0.05;
    bonusVendas = valueVendas * 0.01;

    salarioVendedor = salario + (comissao * numCarrosVendidos) + porcValueVendas;

    printf("Eh gerente? (S/N):\n");
    scanf(" %c", &gerente);
    if (gerente == 'S' || gerente == 's')
    {
        salarioVendedor = salarioVendedor + bonusVendas;

        printf("Seu salario com bonus de gerente nesse mes eh de: R$ %.2f", salarioVendedor);
    }
    else
    {
        printf("Seu salario nesse mes eh de: R$ %.2f", salarioVendedor);
    }

    return 0;
}
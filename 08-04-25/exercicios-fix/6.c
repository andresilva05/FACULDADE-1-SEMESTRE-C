// Exercício 7. Uma empresa decidiu dar um aumento escalonado a seus funcionários de acordo com
// a seguinte regra: 13% para os salários inferiores ou iguais a R$ 200,00; 11% para os salários
// situados entre R$ 200,0 e R$ 400,00 (inclusive); 9 % para os salários entre R$ 400,00 e R$ 800,00
// (inclusive) e 7% para os demais salários. Escreva um programa que receba o salário atual de um
// funcionário e forneça o valor do seu novo salário.

#include <stdio.h>

int main()
{

    float salarioAtual, newSalario, trezePorc, onzePorc, novePorc, setePorc;

    printf("Digite seu salario atual: \nR$");
    scanf("%f", &salarioAtual);

    if (salarioAtual <= 200.00)
    {
        trezePorc = salarioAtual * 0.13;
        newSalario = salarioAtual + trezePorc;

        printf("Seu salario com aumento sera R$ %.2f.\n", newSalario);
    }
    else if (salarioAtual > 200.00 && salarioAtual <= 400.00)
    {
        onzePorc = salarioAtual * 0.11;
        newSalario = salarioAtual + onzePorc;
        printf("Seu salario com aumento sera, R$ %.2f.\n", newSalario);
    }
    else if (salarioAtual > 400.00 && salarioAtual <= 800.00)
    {
        novePorc = salarioAtual * 0.09;
        newSalario = salarioAtual + novePorc;
        printf("Seu salario com aumento, sera R$ %.2f.\n", newSalario);
    }
    else
    {
        setePorc = salarioAtual * 0.07;
        newSalario = salarioAtual + setePorc;

        printf("Seu salario com aumento, sera R$ %.2f.\n", newSalario);
    }
}
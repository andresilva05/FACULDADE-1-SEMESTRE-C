#include <stdio.h>

int main()
{
    double salario, aumento, novoSalario;
    printf("Digite o valor do salario atual: R$ ");

    scanf("%lf", &salario);

    if (salario <= 1200)
    {
        aumento = salario * 0.2;
    }
    if (salario > 1200 && salario <= 1500)
    {
        aumento = salario * 0.3;
    }
    if (salario > 1500)
    {
        aumento = salario * 0.1;
    }

    novoSalario = salario + aumento;
    printf("Valor do aumento: R$ %.2lf\n", aumento);
    printf("Valor do novo salario: R$ %.2lf\n", novoSalario);

    return 0;
}
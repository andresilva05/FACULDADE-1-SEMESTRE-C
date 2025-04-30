// Exercício 6. Escreva um programa que determine o número de dias de um mês de acordo com o
// mês e o ano informado pelo usuário.

#include <stdio.h>

int main()
{

    int mes, ano;

    printf("Digite um mes e ano, que lhe darei o total de dias do mes: \n");
    scanf("%d %d", &mes, &ano);

    if (mes >= 1 && mes <= 12)
    {
        if (((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) && (mes == 02))
        {
            printf("O mes que voce digitou tem 29 dias, pois, eh um ano bissexto!\n");
        }
        else if (mes == 2)
        {
            printf("O mes que voce digitou no ano de %d, tem 28 dias!\n", ano);
        }

        else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 10 || mes == 12)
        {
            printf("O mes que voce digitou no ano de %d, tem 31 dias!\n", ano);
        }
        else
        {
            printf("O mes que voce digitou no ano de %d, tem 30 dias!\n", ano);
        }
    }
    else
    {
        printf("Digite um mes valido!");
    }

    return 0;
}
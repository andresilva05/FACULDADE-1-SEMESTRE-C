// 2. Escreva uma função que receba duas variáveis do tipo data, cada uma representando uma data válida, e devolva o número de dias que decorreram entre as duas datas.
#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} Data;

int ehBissexto(int ano);
int totalDias(Data d);
int diferencaDias(Data d1, Data d2);

int main()
{
    Data data1, data2;
    int diferenca;

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);

    diferenca = diferencaDias(data1, data2);

    printf("Diferenca de dias: %d\n", diferenca);

    return 0;
}

int ehBissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1; // É bissexto
    }
    else
    {
        return 0; // Não é bissexto
    }
}

int totalDias(Data d)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    int i;

    // Soma os dias dos anos anteriores
    for (i = 1; i < d.ano; i++)
    {
        if (ehBissexto(i))
        {
            total += 366;
        }
        else
        {
            total += 365;
        }
    }

    // Soma os dias dos meses anteriores no ano atual
    for (i = 0; i < d.mes - 1; i++)
    {
        total += diasPorMes[i];
    }

    // Se o ano for bissexto e o mês for depois de fevereiro, soma 1 dia a mais
    if (ehBissexto(d.ano) && d.mes > 2)
    {
        total += 1;
    }

    // Soma os dias do mês atual
    total += d.dia;

    return total;
}

int diferencaDias(Data d1, Data d2)
{
    int dias1 = totalDias(d1);
    int dias2 = totalDias(d2);

    if (dias1 > dias2)
    {
        return dias1 - dias2;
    }
    else
    {
        return dias2 - dias1;
    }
}

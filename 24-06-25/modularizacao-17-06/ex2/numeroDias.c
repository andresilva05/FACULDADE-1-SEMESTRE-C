#include "numeroDias.h"

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
    // Quantidade de dias em cada mês (sem considerar ano bissexto ainda)
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    int i;

    // Soma os dias de todos os anos anteriores ao ano atual
    for (i = 1; i < d.ano; i++)
    {
        if (ehBissexto(i))
        {
            total = total + 366; // Ano bissexto tem 366 dias
        }
        else
        {
            total = total + 365; // Ano normal tem 365 dias
        }
    }

    // Soma os dias dos meses anteriores ao mês atual, dentro do ano atual
    for (i = 0; i < d.mes - 1; i++)
    {
        total = total + diasPorMes[i];
    }

    // Se o ano for bissexto e o mês atual for depois de fevereiro, soma mais 1 dia
    if (ehBissexto(d.ano) && d.mes > 2)
    {
        total = total + 1;
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

#include "data.h"

int verificaData(Data x)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias;

    // Verifica valores básicos de dia, mês e ano
    if (x.dia < 1 || x.dia > 31 || x.mes < 1 || x.mes > 12 || x.ano < 1)
    {
        return 0; // Data inválida
    }

    // Define o máximo de dias para o mês informado
    maxDias = diasPorMes[x.mes - 1];

    // Se for fevereiro e ano bissexto, máximo é 29
    if (x.mes == 2 && ehBissexto(x.ano))
    {
        maxDias = 29;
    }

    // Verifica se o dia não ultrapassa o máximo do mês
    if (x.dia > maxDias)
    {
        return 0; // Data inválida
    }

    return 1; // Data válida
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

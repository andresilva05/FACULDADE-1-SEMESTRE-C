// 3. Escreva uma função que verifique se uma variável do tipo data tem um valor válido.

#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} Data;

int verificaData(Data x);
int ehBissexto(int ano);

int main()
{

    Data d;
    printf("Digite uma data (dd mm aaaa): ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    if (verificaData(d))
    {
        printf("Data valida!\n");
    }
    else
    {
        printf("Data invalida!\n");
    }
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

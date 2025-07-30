#include <stdio.h>
#include "data.h"

// Função que lê uma data do usuário, validando até que seja correta
Data lerData()
{
    Data x;

    // Enquanto a data for inválida, continua pedindo
    while (!verificaData(x))
    {
        printf("Entre com a data de nascimento no FORMATO (dd mm aaaa): ");
        // Lê dia, mês e ano da data
        scanf("%d %d %d", &x.dia, &x.mes, &x.ano);
        limparBufferEntrada(); // Limpa o buffer para evitar problemas em leituras futuras
    }

    return x; // Retorna a data válida lida
}

// Função para imprimir a data no formato dia/mês/ano
void imprimirData(Data x)
{
    printf(" %d/%d/%d", x.dia, x.mes, x.ano);
}

// Função que verifica se a data passada é válida
int verificaData(Data x)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias;

    // Verifica se dia, mês e ano estão dentro de valores básicos válidos
    if (x.dia < 1 || x.dia > 31 || x.mes < 1 || x.mes > 12 || x.ano < 1)
    {
        return 0; // Data inválida
    }

    // Obtém o número máximo de dias para o mês informado
    maxDias = diasPorMes[x.mes - 1];

    // Se for fevereiro e o ano for bissexto, ajusta o máximo de dias para 29
    if (x.mes == 2 && ehBissexto(x.ano))
    {
        maxDias = 29;
    }

    // Verifica se o dia não ultrapassa o máximo permitido para o mês
    if (x.dia > maxDias)
    {
        return 0; // Data inválida
    }

    return 1; // Data válida
}

// Função que verifica se o ano é bissexto
int ehBissexto(int ano)
{
    // Ano bissexto: múltiplo de 4, não múltiplo de 100, ou múltiplo de 400
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1; // É bissexto
    }
    else
    {
        return 0; // Não é bissexto
    }
}

// Função que verifica se uma string contém algum caractere diferente de espaço
int verificaTextoString(char texto[])
{
    int i;
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] != ' ')
        {
            return 1; // contém conteúdo válido (não está vazia ou só espaços)
        }
    }
    return 0; // string vazia ou só espaços
}

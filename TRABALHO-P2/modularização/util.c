#include <stdio.h>
#include "util.h"
#include "vendas.h"

// Função para limpar o buffer do teclado (stdin), evitando problemas em entradas futuras
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // descarta todos os caracteres até o fim da linha
    }
}

// Função que verifica se a data passada é válida
int verificaData(Venda vendas)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias;

    // Verifica se dia, mês e ano estão dentro de valores básicos válidos
    if (vendas.dia < 1 || vendas.dia > 31 || vendas.mes < 1 || vendas.mes > 12 || vendas.ano < 1)
    {
        return 0; // Data inválida
    }

    // Obtém o número máximo de dias para o mês informado
    maxDias = diasPorMes[vendas.mes - 1];

    // Se for fevereiro e o ano for bissexto, ajusta o máximo de dias para 29
    if (vendas.mes == 2 && ehBissexto(vendas.ano))
    {
        maxDias = 29;
    }

    // Verifica se o dia não ultrapassa o máximo permitido para o mês
    if (vendas.dia > maxDias)
    {
        return 0; // Data inválida
    }

    return 1; // Data válida
}

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
// Função que aguarda o usuário pressionar Enter
void aguardar_tecla()
{
    printf("\nPressione Enter para continuar...");
    getchar();
}

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}
int cpf_valido(char cpf[])
{
    int i;
    int todos_iguais = 1;

    for (i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            todos_iguais = 0;
            break;
        }
    }

    if (todos_iguais)
        return 0;

    int numeros[11];
    for (i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0;
        numeros[i] = cpf[i] - '0';
    }

    int soma = 0;
    for (i = 0; i < 9; i++)
    {
        soma += numeros[i] * (10 - i);
    }

    int primeiro_digito = (soma * 10) % 11;
    if (primeiro_digito == 10)
        primeiro_digito = 0;
    if (numeros[9] != primeiro_digito)
        return 0;

    soma = 0;
    for (i = 0; i < 10; i++)
    {
        soma += numeros[i] * (11 - i);
    }

    int segundo_digito = (soma * 10) % 11;
    if (segundo_digito == 10)
        segundo_digito = 0;
    if (numeros[10] != segundo_digito)
        return 0;

    return 1;
}

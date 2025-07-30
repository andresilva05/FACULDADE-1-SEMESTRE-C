#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

// Função para limpar o buffer de entrada do teclado
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Apenas consome os caracteres até encontrar '\n' ou EOF
    }
}

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Comando do Windows
#else
    system("clear"); // Comando do Linux/Mac
#endif
}

// Função que pausa o programa até que o usuário pressione Enter
void aguardar_tecla()
{
    printf("\nPressione Enter para continuar...");
    getchar(); // Aguarda um Enter
}

// Função que valida se um nome não é vazio nem feito apenas de espaços/tabs
int nome_valido(char nome[])
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\t')
            return 1; // Encontrou caractere válido
    }
    return 0; // Só havia espaços ou estava vazio
}

// Função que valida um CPF com base na regra oficial dos dígitos verificadores
int cpf_valido(char cpf[])
{
    int i;
    int todos_iguais = 1;

    // Verifica se todos os dígitos são iguais (CPF inválido)
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
    // Converte os caracteres do CPF em inteiros e valida se são dígitos
    for (i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0; // CPF com caractere inválido
        numeros[i] = cpf[i] - '0';
    }

    // Cálculo do primeiro dígito verificador
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

    // Cálculo do segundo dígito verificador
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

    return 1; // CPF válido
}

// Função que valida a data de uma venda
int verificaData(Venda vendas)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias;

    // Valida se dia, mês e ano estão em intervalos básicos válidos
    if (vendas.dia < 1 || vendas.dia > 31 || vendas.mes < 1 || vendas.mes > 12 || vendas.ano < 1)
    {
        return 0; // Data inválida
    }

    // Define o número máximo de dias para o mês informado
    maxDias = diasPorMes[vendas.mes - 1];

    // Ajusta para ano bissexto se for fevereiro
    if (vendas.mes == 2 && ehBissexto(vendas.ano))
    {
        maxDias = 29;
    }

    // Valida se o dia não excede o limite do mês
    if (vendas.dia > maxDias)
    {
        return 0; // Data inválida
    }

    return 1; // Data válida
}

// Função que verifica se um ano é bissexto
int ehBissexto(int ano)
{
    // Regras: múltiplo de 4 e não múltiplo de 100, ou múltiplo de 400
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1; // Ano bissexto
    }
    else
    {
        return 0; // Ano comum
    }
}

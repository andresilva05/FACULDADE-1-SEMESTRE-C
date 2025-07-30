// 6. Faça um programa em C para receber os valores das vendas de uma loja. Os dados devem ser armazenados em uma matriz 12x2,
// em que cada linha representa um mês do ano e cada coluna representa uma quinzena do mês.
// O programa deverá calcular e mostrar:
//
// a) O total vendido em cada mês do ano, mostrando o nome do mês por extenso;
//
// b) O total vendido em cada quinzena durante todo o ano, para que os proprietários da loja possam identificar a quinzena que mais teve vendas;
//
// c) O total vendido pela loja no ano.

#include <stdio.h>

#define LINHA 12  // Número de meses (pode alterar para 12 depois que terminar os testes)
#define COLUNA 2 // Duas quinzenas por mês

// Declaração das funções
void vendaMes(float quinzena[LINHA][COLUNA]);
void vendaQuinzena(float quinzena[LINHA][COLUNA]);

int main()
{
    int i, j;
    float valorVenda[LINHA][COLUNA]; // Matriz para armazenar os valores das vendas
    char meses[12][10] = {
        "janeiro", "fevereiro", "marco", "abril",
        "maio", "junho", "julho", "agosto",
        "setembro", "outubro", "novembro", "dezembro"};

    // Coleta dos valores de venda para cada mês e quinzena
    printf("Abaixo digite valores vendidos em cada mes do ano:\n");

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("\nDigite o valor do mes de %s, da %dª quinzena: ", meses[i], j + 1);
            scanf("%f", &valorVenda[i][j]);
        }
    }

    // Chamada das funções que realizam os cálculos
    vendaMes(valorVenda);
    vendaQuinzena(valorVenda);
}

// Função para calcular e exibir o total vendido em cada mês
void vendaMes(float quinzena[LINHA][COLUNA])
{
    int i, j;

    // Vetor com os nomes dos meses
    char meses[12][10] = {
        "janeiro", "fevereiro", "marco", "abril",
        "maio", "junho", "julho", "agosto",
        "setembro", "outubro", "novembro", "dezembro"};

    printf("\n");

    // Percorre cada mês (linha da matriz)
    for (i = 0; i < LINHA; i++)
    {
        float somaVendaMes = 0;

        // Soma as duas quinzenas do mês atual
        for (j = 0; j < COLUNA; j++)
        {
            somaVendaMes += quinzena[i][j];
        }

        // Mostra o total do mês com nome por extenso
        printf("\nSoma do mes de %s eh: R$%.2f", meses[i], somaVendaMes);
    }
}

// Função para calcular e exibir o total vendido por quinzena e o total do ano
void vendaQuinzena(float quinzena[LINHA][COLUNA])
{
    int i, j;
    float quinzena1 = 0, quinzena2 = 0, vendaAno;

    // Percorre cada coluna (quinzena)
    for (j = 0; j < COLUNA; j++)
    {
        float somaVendaQuinzena = 0;

        // Soma todas as vendas da quinzena j ao longo dos meses
        for (i = 0; i < LINHA; i++)
        {
            somaVendaQuinzena += quinzena[i][j];
        }

        // Armazena o total da quinzena correspondente
        if (j == 0)
        {
            quinzena1 = somaVendaQuinzena;
        }
        else
        {
            quinzena2 = somaVendaQuinzena;
        }

        // Exibe o resultado da quinzena
        printf("\nSoma da %dª quinzena eh: R$%.2f", j + 1, somaVendaQuinzena);
    }

    // Soma das duas quinzenas para obter o total do ano
    vendaAno = quinzena1 + quinzena2;

    // Exibe o total anual
    printf("\n\nVenda total do ano eh: R$%.2f\n", vendaAno);
}

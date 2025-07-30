// 7. Faça um programa em C para receber o estoque atual e o custo de três produtos de uma distribuidora, que são armazenados emquatro armazéns. Os dados devem ser armazenados em uma matriz 5x3, sendo que as 4 primeiras linhas contêm os estoques dos produtos nos armazéns e a última linha contém o custo de cada produto. O programa deverá calcular e mostrar:

// A quantidade de itens de produto armazenados em cada armazém;

// Qual armazém possui maior estoque do produto 2;

// Qual armazém possui menor estoque;

// Qual o custo total de cada produto;

// Qual o custo total de cada armazém.

#include <stdio.h>

#define LINHA 5  // 4 armazéns + 1 linha para custo
#define COLUNA 3 // 3 produtos

void qtdProdutoArmazem(float produtos[LINHA][COLUNA]);
void maiorEstoqueProduto2(float produtos[LINHA][COLUNA]);
void menorEstoque(float produtos[LINHA][COLUNA]);
void custoTotalProduto(float produtos[LINHA][COLUNA]);
void custoArmazem(float produtos[LINHA][COLUNA]);

int main()
{
    int i, j;
    float produtos[LINHA][COLUNA];

    printf("Linha / Coluna\t\tProduto 1\tProduto 2\tProduto 3\n\n");

    // Entrada dos estoques dos armazéns (4 linhas)
    for (i = 0; i < LINHA - 1; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("Armazem %d Produto %d: ", i + 1, j + 1);
            scanf("%f", &produtos[i][j]);
        }
        printf("\n");
    }

    // Entrada do custo dos produtos (linha 4)
    printf("Informe o custo (R$) de cada produto:\n");
    for (j = 0; j < COLUNA; j++)
    {
        printf("Produto %d: R$ ", j + 1);
        scanf("%f", &produtos[LINHA - 1][j]);
    }
    printf("\n");

    // Chamadas das funções que processam e exibem os dados
    qtdProdutoArmazem(produtos);
    maiorEstoqueProduto2(produtos);
    menorEstoque(produtos);
    custoTotalProduto(produtos);
    custoArmazem(produtos);

    return 0;
}

// A) Quantidade de itens de produto em cada armazém
void qtdProdutoArmazem(float produtos[LINHA][COLUNA])
{
    int i, j;
    float qtdProdutos;

    printf("\nQuantidade total de produtos em cada armazem:\n");

    for (i = 0; i < LINHA - 1; i++)
    {
        qtdProdutos = 0;
        for (j = 0; j < COLUNA; j++)
        {
            qtdProdutos += produtos[i][j];
        }
        printf("Armazem %d: %.0f produtos\n", i + 1, qtdProdutos);
    }
}

// B) Qual armazém possui maior estoque do produto 2
void maiorEstoqueProduto2(float produtos[LINHA][COLUNA])
{
    int i;
    float maiorEstoque = produtos[0][1]; // produto 2, índice 1
    int armazem = 0;

    for (i = 1; i < LINHA - 1; i++)
    {
        if (produtos[i][1] > maiorEstoque)
        {
            maiorEstoque = produtos[i][1];
            armazem = i;
        }
    }
    printf("\nArmazem %d possui o maior estoque do Produto 2: %.0f unidades\n", armazem + 1, maiorEstoque);
}

// C) Qual armazém possui menor estoque total
void menorEstoque(float produtos[LINHA][COLUNA])
{
    int i, j;
    float soma, menorEstoque, armazemMenor = 0;

    // Inicializa menorEstoque com a soma do primeiro armazém
    menorEstoque = 0;
    for (j = 0; j < COLUNA; j++)
    {
        menorEstoque += produtos[0][j];
    }

    for (i = 1; i < LINHA - 1; i++)
    {
        soma = 0;
        for (j = 0; j < COLUNA; j++)
        {
            soma += produtos[i][j];
        }
        if (soma < menorEstoque)
        {
            menorEstoque = soma;
            armazemMenor = i;
        }
    }

    printf("\nArmazem %d possui o menor estoque total: %.0f unidades\n", (int)armazemMenor + 1, menorEstoque);
}

// D) Custo total de cada produto (quantidade total * custo unitário)
void custoTotalProduto(float produtos[LINHA][COLUNA])
{
    int i, j;
    float somaProduto, custoTotal;

    printf("\nCusto total de cada produto:\n");
    for (j = 0; j < COLUNA; j++)
    {
        somaProduto = 0;
        for (i = 0; i < LINHA - 1; i++)
        {
            somaProduto += produtos[i][j];
        }
        custoTotal = somaProduto * produtos[LINHA - 1][j];
        printf("Produto %d: R$ %.2f\n", j + 1, custoTotal);
    }
}

// E) Custo total de cada armazém (soma dos custos de todos os produtos no armazém)
void custoArmazem(float produtos[LINHA][COLUNA])
{
    int i, j;
    float custoTotal;

    printf("\nCusto total de cada armazem:\n");
    for (i = 0; i < LINHA - 1; i++)
    {
        custoTotal = 0;
        for (j = 0; j < COLUNA; j++)
        {
            custoTotal += produtos[i][j] * produtos[LINHA - 1][j];
        }
        printf("Armazem %d: R$ %.2f\n", i + 1, custoTotal);
    }
}

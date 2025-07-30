#include "vendas.h"
#include "global.h"
#include <stdio.h>
#include "produtos.c"

void cadastroDeVendas()
{
    // Verifica se há produtos e clientes cadastrados antes de iniciar
    if (indice_produtos == 0)
    {
        printf("\nNao ha produtos cadastrados. Cadastre ao menos um produto antes de realizar uma venda.\n");
        return;
    }
    if (indice_clientes == 0)
    {
        printf("\nNao ha clientes cadastrados. Cadastre ao menos um cliente antes de realizar uma venda.\n");
        return;
    }

    char cpf_temp[12]; // Variável para armazenar o CPF temporariamente
    int i, cpf_existe, produto_existe, qtdProduto, qtd_Estoque;

    // Etapa 1 - Validação da data
    while (!verificaData(vendas[indice_vendas]))
    {
        printf("\nInforme a data da venda (dd mm aaaa): ");
        scanf("%d %d %d",
              &vendas[indice_vendas].dia,
              &vendas[indice_vendas].mes,
              &vendas[indice_vendas].ano);

        limpar_buffer_entrada(); // Limpa o buffer após a leitura
    }

    // Etapa 2 - Verificação do CPF
    do
    {
        printf("\nDigite seu CPF com 11 digitos (apenas numeros): ");
        scanf("%s", cpf_temp);
        limpar_buffer_entrada();
        cpf_existe = 0; // Reinicia a verificação
        for (i = 0; i < indice_clientes; i++)
        {
            if (strcmp(cpf_temp, clientes[i].cpf) == 0)
            {
                cpf_existe = 1;
                // Copia o CPF validado para a venda
                strcpy(vendas[indice_vendas].cpf_cliente, cpf_temp);
                break;
            }
        }
        if (!cpf_existe)
        {
            printf("\nCPF nao encontrado, tente novamente.\n");
        }

    } while (!cpf_existe);

    // Etapa 3 - Verificação do produto
    int idProduto;
    do
    {
        printf("\nDigite id do produto: ");
        scanf("%d", &idProduto);
        limpar_buffer_entrada();

        produto_existe = 0;

        for (i = 0; i < indice_produtos; i++)
        {
            if (idProduto == produtos[i].id && produtos[i].ativo == 1)
            {
                if (produtos[i].quantidade == 0)
                {
                    int opcao;
                    printf("\nProduto com estoque zerado. Nao e possivel realizar a venda desse item.\n");
                    printf("Deseja:\n");
                    printf("1. Tentar outro produto\n");
                    printf("2. Cancelar venda\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
                    limpar_buffer_entrada();

                    if (opcao == 2)
                    {
                        printf("\nVenda cancelada pelo usuario.\n");
                        return; // Sai da função de venda
                    }

                    produto_existe = 0; // continua no loop para tentar outro produto
                }
                else
                {
                    produto_existe = 1;
                    vendas[indice_vendas].id_produto = idProduto;
                }
                break;
            }
        }
        if (!produto_existe)
        {
            printf("\nProduto inexistente ou inativo. Tente novamente.\n");
        }

    } while (!produto_existe);

    // Etapa 4 - Validação da quantidade
    do
    {
        qtdProduto = 0;
        qtd_Estoque = 0;

        printf("\nQuantas unidades deseja vender?");
        scanf("%d", &qtdProduto);
        limpar_buffer_entrada();

        if (qtdProduto > 0)
        {
            for (i = 0; i < indice_produtos; i++)
            {
                if (produtos[i].id == idProduto)
                {
                    qtd_Estoque = produtos[i].quantidade;

                    if (qtdProduto <= qtd_Estoque)
                    {
                        // Quantidade válida, atualiza estoque e registra venda
                        vendas[indice_vendas].quantidade = qtdProduto;
                        produtos[i].quantidade -= qtdProduto;
                    }
                    else
                    {
                        printf("\nEstoque insuficiente. Estoque possui %d unidade(s)", produtos[i].quantidade);
                        qtdProduto = -1; // Força repetição do loop
                    }

                    break; // Produto já encontrado
                }
            }
        }
        else
        {
            printf("\nQuantidade de produtos nao pode ser 0!");
        }

    } while (qtdProduto <= 0 || qtdProduto > qtd_Estoque);

    // Etapa 5 - Geração do ID da venda e incremento do índice
    vendas[indice_vendas].id = indice_vendas + 1;
    indice_vendas++;

    printf("\nVenda registrada com sucesso!\n");
}
void listarVendas()
{

    int i, j, k, encontrouCliente;
    printf("\nVendas ate o momento");

    for (i = 0; i < indice_vendas; i++)
    {
        encontrouCliente = 0;
        printf("\n-----------------------------");
        printf("\nId da Venda: %d", vendas[i].id);
        printf("\nData da Venda: %02d/%02d/%04d", vendas[i].dia, vendas[i].mes, vendas[i].ano);

        for (j = 0; j < indice_clientes; j++)
        {
            if (strcmp(vendas[i].cpf_cliente, clientes[j].cpf) == 0)
            {
                printf("\nCliente:");
                printf("\n - Nome: %s", clientes[j].nome);
                printf("\n - CPF: %s", vendas[i].cpf_cliente);
                encontrouCliente = 1;
                break;
            }
        }
        for (k = 0; k < indice_produtos; k++)
        {
            if (vendas[i].id_produto == produtos[k].id)
            {
                printf("\nProduto:");
                printf("\n - ID: %d", produtos[k].id);
                printf("\n - Nome: %s", produtos[k].nome);
            }
        }
        if (encontrouCliente == 0)
        {
            printf("\nCliente: Não encontrado.");
        }
    }
    printf("\n-----------------------------\n");
}

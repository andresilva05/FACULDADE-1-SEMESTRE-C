#include "produtos.h"
#include "global.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

// Aqui implementa cadastrar_produto, listar_produtos, etc
// NaO inclua produtos.c dentro de outro .c!

// Função para cadastrar um novo produto no sistema
void cadastrar_produto()
{
    limpar_tela();
    printf("--- 1. Cadastro de Novo Produto ---\n");

    if (indice_produtos < MAX_PRODUTOS)
    {
        produtos[indice_produtos].id = id_atual++; // Gera ID único para o produto
        produtos[indice_produtos].ativo = 1;       // Marca o produto como ativo

        int nome_existente;
        do
        {
            // Solicita o nome do produto
            printf("Digite o nome do produto: ");
            fgets(produtos[indice_produtos].nome, TAM_MAX_NOME, stdin);
            produtos[indice_produtos].nome[strcspn(produtos[indice_produtos].nome, "\n")] = '\0'; // Remove o '\n'

            // Verifica se o nome é válido (não vazio ou só espaços)
            if (!nome_valido(produtos[indice_produtos].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            // Verifica se o nome já foi cadastrado
            nome_existente = 0;
            for (int i = 0; i < indice_produtos; i++)
            {
                if (strcmp(produtos[i].nome, produtos[indice_produtos].nome) == 0)
                {
                    nome_existente = 1;
                    printf("Erro: Nome do produto ja cadastrado. Escolha outro nome.\n");
                    break;
                }
            }
        } while (nome_existente != 0);

        // Cadastro da quantidade e do preço
        do
        {
            printf("\nDigite a quantidade inicial: ");
            scanf("%d", &produtos[indice_produtos].quantidade);
            limpar_buffer_entrada(); // Evita problemas no scanf

            printf("\nDigite o preco unitario (R$): ");
            scanf("%f", &produtos[indice_produtos].preco);
            limpar_buffer_entrada();

            // Valida se os valores são válidos
            if (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0)
            {
                printf("\nErro: R$Preco ou quantidade nao pode ser negativos");
            }
            else
            {
                printf("\nProduto '%s' cadastrado com sucesso! ID: %d\n", produtos[indice_produtos].nome, produtos[indice_produtos].id);
                indice_produtos++; // Avança para o próximo cadastro
            }

        } while (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0);
    }
    else
    {
        // Limite de produtos atingido
        printf("\nErro: Capacidade maxima de produtos atingida!\n");
    }
}

// Função que lista todos os produtos cadastrados
void listar_produtos()
{
    limpar_tela();
    printf("--- 2. Lista de Produtos Cadastrados ---\n");

    if (indice_produtos == 0)
    {
        printf("Nenhum produto cadastrado ainda.\n");
    }
    else
    {
        // Cabeçalho da tabela
        printf("%-5s | %-30s | %-10s | %-10s\n", "ID", "Nome", "Qtd.", "Preco (R$)");
        printf("------------------------------------------------------------------\n");

        for (int i = 0; i < indice_produtos; i++)
        {
            if (produtos[i].ativo == 1)
            {
                // Mostra o produto se ele estiver ativo
                printf("%-5d | %-30s | %-10d | R$ %-8.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            }
            else
            {
                // Caso esteja inativo (deletado)
                printf("%-5d | %-30s | %-10s | %-10s\n",
                       produtos[i].id, "Produto Deletado", "-", "-");
            }
        }
    }
}

// Função para atualizar o estoque de um produto
void atualizar_estoque()
{
    int id_produto;
    int quantidade_movimento;
    int encontrado = 0;

    limpar_tela();
    printf("--- 3. Atualizar Estoque ---\n");
    printf("Digite o ID do produto que deseja atualizar: ");
    scanf("%d", &id_produto);
    limpar_buffer_entrada();

    // Procura o produto pelo ID
    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].id == id_produto && produtos[i].ativo == 1)
        {
            printf("\nProduto selecionado: %s\n", produtos[i].nome);
            printf("Estoque atual: %d\n", produtos[i].quantidade);
            printf("Digite a quantidade a ser adicionada (ex: 10) ou removida (ex: -5): ");
            scanf("%d", &quantidade_movimento);
            limpar_buffer_entrada();

            // Verifica se o resultado final não fica negativo
            if ((produtos[i].quantidade + quantidade_movimento) >= 0)
            {
                produtos[i].quantidade += quantidade_movimento;
                printf("\nEstoque atualizado com sucesso! Novo estoque: %d\n", produtos[i].quantidade);
            }
            else
            {
                printf("\nErro: Operacao invalida. O estoque nao pode ficar negativo.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nErro: Produto com ID %d nao encontrado ou deletado.\n", id_produto);
    }
}

// Função para buscar um produto por ID ou por nome
void buscar_produto()
{
    char termo_busca[TAM_MAX_NOME];
    int id_busca = -1;
    int encontrado = 0;

    limpar_tela();
    printf("--- 4. Buscar Produto ---\n");
    printf("Digite o ID ou parte do nome do produto: ");
    fgets(termo_busca, TAM_MAX_NOME, stdin);
    termo_busca[strcspn(termo_busca, "\n")] = 0; // Remove o '\n'

    // Primeiro tenta buscar por ID (se for número)
    if (sscanf(termo_busca, "%d", &id_busca) == 1)
    {
        for (int i = 0; i < indice_produtos; i++)
        {
            if (produtos[i].id == id_busca)
            {
                if (produtos[i].ativo == 1)
                {
                    printf("\n--- Produto Encontrado por ID ---\n");
                    printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                           produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
                }
                else
                {
                    printf("\nProduto com ID %d foi deletado.\n", id_busca);
                }
                encontrado = 1;
                break;
            }
        }
    }

    // Se não achou por ID, procura por nome (mesmo parcial)
    if (!encontrado)
    {
        printf("\n--- Resultados da Busca por Nome '%s' ---\n", termo_busca);
        for (int i = 0; i < indice_produtos; i++)
        {
            if (produtos[i].ativo == 1 && strstr(produtos[i].nome, termo_busca) != NULL)
            {
                printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
                encontrado = 1;
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum produto encontrado com o termo '%s'.\n", termo_busca);
    }
}

// Calcula o valor total de todos os produtos ativos no estoque
void calcular_valor_total()
{
    double valor_total_estoque = 0.0;

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].ativo == 1)
        {
            valor_total_estoque += (double)produtos[i].quantidade * produtos[i].preco;
        }
    }

    limpar_tela();
    printf("--- 5. Valor Total do Estoque ---\n");
    printf("O valor total de todos os produtos em estoque e: R$ %.2f\n", valor_total_estoque);
}

// Mostra todos os produtos com estoque igual ou menor ao limite informado
void relatorio_estoque_baixo()
{
    int limite_estoque;
    int encontrou_item_baixo = 0;

    limpar_tela();
    printf("--- 6. Relatorio de Estoque Baixo ---\n");
    printf("Digite a quantidade limite para considerar o estoque baixo (ex: 5): ");
    scanf("%d", &limite_estoque);
    limpar_buffer_entrada();

    printf("\n--- Produtos com estoque igual ou inferior a %d ---\n", limite_estoque);

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].ativo == 1 && produtos[i].quantidade <= limite_estoque)
        {
            if (produtos[i].quantidade <= 0)
            {
                printf("ID: %d | Nome: %s | Estoque Atual: Sem estoque\n", produtos[i].id, produtos[i].nome);
            }
            else
            {
                printf("ID: %d | Nome: %s | Estoque Atual: %d\n", produtos[i].id, produtos[i].nome, produtos[i].quantidade);
            }
            encontrou_item_baixo = 1;
        }
    }

    if (!encontrou_item_baixo)
    {
        printf("Nenhum produto com estoque baixo encontrado.\n");
    }
}

// "Exclui" um produto do sistema (marca como inativo)
void excluirProduto()
{
    int id_deletado;
    int encontrado = 0;

    printf("Digite ID do produto que deseja deletar: ");
    scanf("%d", &id_deletado);
    limpar_buffer_entrada();

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].id == id_deletado)
        {
            // Verifica se o produto já foi vendido — se sim, não pode ser deletado
            for (int j = 0; j < indice_vendas; j++)
            {
                if (vendas[j].id_produto == id_deletado)
                {
                    printf("\n-Este produto ja foi vendido e nao pode ser excluido.");
                    return;
                }
            }

            // Se ainda está ativo, marca como inativo
            if (produtos[i].ativo == 1)
            {
                produtos[i].ativo = 0;
                printf("Produto com ID %d deletado com sucesso.\n", id_deletado);
            }
            else
            {
                printf("Produto com ID %d ja esta deletado.\n", id_deletado);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Produto nao encontrado.\n");
    }
}

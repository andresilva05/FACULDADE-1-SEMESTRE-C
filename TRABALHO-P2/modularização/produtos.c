#include "produtos.h"
#include "global.h"
#include <string.h>
#include <stdio.h>
#include "util.h"

void cadastrar_produto()
{
    limpar_tela();
    printf("--- 1. Cadastro de Novo Produto ---\n");

    if (indice_produtos < MAX_PRODUTOS)
    {
        produtos[indice_produtos].id = id_atual++; // Define ID único sequencial
        produtos[indice_produtos].ativo = 1;       // Marca como ativo

        int nome_existente;
        do
        {
            printf("Digite o nome do produto: ");
            fgets(produtos[indice_produtos].nome, TAM_MAX_NOME, stdin);
            produtos[indice_produtos].nome[strcspn(produtos[indice_produtos].nome, "\n")] = '\0'; // Remove o '\n'

            if (!nome_valido(produtos[indice_produtos].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

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

        do
        {
            printf("\nDigite a quantidade inicial: ");
            scanf("%d", &produtos[indice_produtos].quantidade);
            limpar_buffer_entrada(); // Limpa buffer após scanf

            printf("\nDigite o preco unitario (R$): ");
            scanf("%f", &produtos[indice_produtos].preco);
            limpar_buffer_entrada(); // Limpa buffer

            if (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0)
            {
                printf("\nErro: R$Preco ou quantidade nao pode ser negativos");
            }
            else
            {
                printf("\nProduto '%s' cadastrado com sucesso! ID: %d\n", produtos[indice_produtos].nome, produtos[indice_produtos].id);
                indice_produtos++; // Incrementa índice para próximo cadastro
            }

        } while (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0);
    }
    else
    {
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
                // Imprime os dados do produto ativo
                printf("%-5d | %-30s | %-10d | R$ %-8.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            }
            else
            {
                // Produto deletado, exibe mensagem alternativa
                printf("%-5d | %-30s | %-10s | %-10s\n",
                       produtos[i].id, "Produto Deletado", "-", "-");
            }
        }
    }
}
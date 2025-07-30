#ifndef PRODUTOS_H
#define PRODUTOS_H

// Define o número máximo de produtos que podem ser cadastrados
#define MAX_PRODUTOS 100

// Define o tamanho máximo para o nome de um produto
#define TAM_MAX_NOME 100

// Estrutura que representa um produto no sistema
typedef struct
{
    int id;                  // ID único do produto
    char nome[TAM_MAX_NOME]; // Nome do produto
    int quantidade;          // Quantidade em estoque
    float preco;             // Preço unitário do produto
    int ativo;               // Status: 1 = ativo, 0 = deletado (lógico)
} Produto;

// Protótipos das funções relacionadas aos produtos

// Função para cadastrar um novo produto
void cadastrar_produto();

// Função para listar todos os produtos cadastrados
void listar_produtos();

// Função para atualizar a quantidade de estoque de um produto
void atualizar_estoque();

// Função para buscar um produto por ID ou parte do nome
void buscar_produto();

// Função para calcular e exibir o valor total de todos os produtos no estoque
void calcular_valor_total();

// Função para listar os produtos com estoque abaixo de um determinado limite
void relatorio_estoque_baixo();

// Função para "excluir" um produto (marcar como inativo)
void excluirProduto();

#endif

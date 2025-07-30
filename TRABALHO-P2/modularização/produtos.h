#ifndef PRODUTOS_H
#define PRODUTOS_H

#define MAX_PRODUTOS 50  // Limite máximo de produtos no sistema
#define TAM_MAX_NOME 100 // Tamanho máximo para nomes (produtos e clientes)

// Estrutura que representa um Produto
typedef struct
{
    int id;                  // Identificador único do produto
    char nome[TAM_MAX_NOME]; // Nome do produto
    int quantidade;          // Quantidade disponível no estoque
    float preco;             // Preço unitário do produto
    int ativo;               // Flag para indicar se o produto está ativo (1) ou deletado (0)
} Produto;
Produto produtos[MAX_PRODUTOS]; // Vetor que armazena os produtos

void cadastrar_produto();
void listar_produtos();

#endif
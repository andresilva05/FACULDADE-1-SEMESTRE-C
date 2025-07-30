#ifndef VENDAS_H

#define VENDAS_H // Define VENDAS_H

#define MAX_VENDAS 100 // Define o número máximo de vendas que podem ser cadastradas

// Estrutura que representa uma venda
typedef struct
{
    int id;               // Identificador único da venda
    int dia, mes, ano;    // Data da venda
    char cpf_cliente[12]; // CPF do cliente que realizou a compra (11 dígitos + '\0')
    int id_produto;       // ID do produto vendido
    int quantidade;       // Quantidade vendida
} Venda;

// Declaração da função para cadastrar uma nova venda
void cadastroDeVendas();

// Declaração da função para listar todas as vendas cadastradas
void listarVendas();

#endif

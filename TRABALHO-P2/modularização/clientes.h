#ifndef CLIENTES_H
#define CLIENTES_H

#define TAM_MAX_NOME 100 // Tamanho máximo para nomes (produtos e clientes)
#define CLIENTES 10      // Limite máximo de clientes no sistema

// Estrutura que representa um Cliente
typedef struct
{
    char cpf[12];            // CPF do cliente (11 dígitos + '\0')
    char nome[TAM_MAX_NOME]; // Nome do cliente
    int qtdCompras;          // Quantidade total de compras realizadas (a implementar)
} Cliente;
Cliente clientes[CLIENTES]; // Vetor que armazena os clientes

void cadastraClientes();
void listagemClientes();
Cliente clientes[CLIENTES]; // Vetor que armazena os clientes

#endif
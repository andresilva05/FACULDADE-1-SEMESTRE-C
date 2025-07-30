#ifndef CLIENTES_H
#define CLIENTES_H

//Define quantidade de clientes no sistema
#define CLIENTES 10

//Define tamanho max de caracteres do nome de um cliente
#define TAM_MAX_NOME 100

typedef struct
{
    char cpf[12];            // CPF do cliente (11 dígitos + '\0')
    char nome[TAM_MAX_NOME]; // Nome do cliente
    int qtdCompras;          // Quantidade total de compras realizadas (a implementar)
} Cliente;

//Função que cadastra cliente
void cadastraClientes();

//Função que lista quantidade de compras do usuario, informando seus dados
void listagemClientes();

#endif

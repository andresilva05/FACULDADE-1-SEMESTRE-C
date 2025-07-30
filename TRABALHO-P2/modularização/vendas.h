#ifndef VENDAS_H
#define VENDAS_H

#include "clientes.h" // se precisar da struct Cliente

#define MAX_VENDAS 100

typedef struct
{
    int id;
    int dia, mes, ano;
    char cpf_cliente[12];
    int id_produto;
    int quantidade;
} Venda;

Venda vendas[MAX_VENDAS];

void cadastroDeVendas();
void listarVendas();
#endif

#ifndef GLOBAL_H
#define GLOBAL_H

// Evita que o conteúdo do arquivo seja incluído mais de uma vez
// durante a compilação (proteção contra múltiplas inclusões)

// Inclui os headers dos módulos principais para usar suas structs
#include "produtos.h"
#include "clientes.h"
#include "vendas.h"

// Declaração das variáveis globais que são usadas em vários arquivos .c

// Vetor de produtos cadastrados (o tamanho máximo vem de produtos.h)
extern Produto produtos[MAX_PRODUTOS];

// Vetor de clientes cadastrados (o tamanho vem de clientes.h)
extern Cliente clientes[CLIENTES];

// Vetor de vendas cadastradas (o tamanho vem de vendas.h)
extern Venda vendas[MAX_VENDAS];

// Índices que indicam a próxima posição livre em cada vetor
extern int indice_produtos;
extern int indice_clientes;
extern int indice_vendas;

// ID atual das vendas (usado para gerar ID único para cada venda)
extern int id_atual;

#endif

#include "global.h"

// Aqui são **definidas** (declaradas de verdade) as variáveis globais
// que foram apenas **declaradas extern** no arquivo global.h

// Vetor que armazena todos os produtos cadastrados no sistema
Produto produtos[MAX_PRODUTOS];

// Vetor que armazena todos os clientes cadastrados
Cliente clientes[CLIENTES];

// Vetor que armazena todas as vendas realizadas
Venda vendas[MAX_VENDAS];

// Variável que indica a próxima posição livre no vetor de produtos
int indice_produtos = 0;

// Variável que indica a próxima posição livre no vetor de clientes
int indice_clientes = 0;

// Variável que indica a próxima posição livre no vetor de vendas
int indice_vendas = 0;

// Variável que armazena o próximo ID disponível para uma nova venda
// Começa em 1 porque o primeiro ID de venda será 1
int id_atual = 1;

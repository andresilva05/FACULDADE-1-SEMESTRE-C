#ifndef UTIL_H
#define UTIL_H

#include "vendas.h"

void limpar_buffer_entrada();
int ehBissexto(int ano);
int verificaData(Venda vendas);
int cpf_valido(char cpf[]);
void aguardar_tecla();

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela();

#endif

#ifndef UTIL_H
#define UTIL_H

#include "vendas.h" // Inclui o cabeçalho de vendas, necessário para usar a struct Venda

// Função para limpar o buffer do teclado (evita problemas com fgets/getchar)
void limpar_buffer_entrada();

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela();

// Função que pausa a execução até o usuário pressionar Enter
void aguardar_tecla();

// Verifica se o nome informado não está vazio ou composto apenas por espaços
int nome_valido(char nome[]);

// Valida o CPF (11 dígitos) com base na regra dos dígitos verificadores
int cpf_valido(char cpf[]);

// Verifica se a data armazenada em uma struct Venda é válida (considerando mês, dia e ano bissexto)
int verificaData(Venda venda);

// Verifica se um ano é bissexto
int ehBissexto(int ano);

#endif

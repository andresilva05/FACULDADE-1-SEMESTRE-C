#ifndef UTILS_H
#define UTILS_H

#include "data.h"  // Inclui as definições e funções relacionadas à data

// Define o tamanho máximo para a agenda e para nomes e demais strings
#define TAM_AGENDA 1   // Quantidade máxima de contatos na agenda (pode ajustar conforme necessário)
#define TAM_NOME 30    // Tamanho máximo para nome, email, telefone e endereço

// Estrutura que representa um contato
typedef struct
{
    char nome[TAM_NOME];             // Nome do contato
    Data dataDeNascimento;           // Data de nascimento (struct Data)
    char email[TAM_NOME];            // Email do contato
    char telefone[TAM_NOME];         // Telefone do contato
    char endereco[TAM_NOME];         // Endereço do contato
} Contato;

// Estrutura que representa a lista de contatos, com tamanho fixo TAM_AGENDA
typedef struct
{
    Contato contato[TAM_AGENDA];     // Array de contatos
} ListaDeContatos;

#endif

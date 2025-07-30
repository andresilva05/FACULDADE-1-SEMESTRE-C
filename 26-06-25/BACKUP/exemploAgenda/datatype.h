#ifndef UTILS_H
#define UTILS_H
#include "data.h"
#define TAM_AGENDA 2
#define TAM_NOME 30

typedef struct
{
    char nome[TAM_NOME];
    Data dataDeNascimento;
    char email[TAM_NOME];
    char telefone[TAM_NOME];
    char endereco[TAM_NOME];
} Contato;

typedef struct
{
    Contato contato[TAM_AGENDA];
} ListaDeContatos;
#endif

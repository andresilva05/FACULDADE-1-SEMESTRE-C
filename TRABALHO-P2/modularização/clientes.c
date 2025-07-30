#include <stdio.h>
#include "clientes.h"
#include "global.h"
#include "vendas.h"
#include "util.h"
// Função para cadastrar clientes
void cadastraClientes()
{
    int i, cpf_existe;
    char cpf_digitado[12]; // 11 dígitos + '\0'

    if (indice_clientes < CLIENTES)
    {
        // Valida o nome (não vazio, não só espaços)
        do
        {
            printf("\nDigite seu nome: ");
            fgets(clientes[indice_clientes].nome, TAM_MAX_NOME, stdin);
            clientes[indice_clientes].nome[strcspn(clientes[indice_clientes].nome, "\n")] = '\0';

            if (!nome_valido(clientes[indice_clientes].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
            }
        } while (!nome_valido(clientes[indice_clientes].nome));

        // Valida o CPF (11 dígitos, não duplicado, regra oficial)
        do
        {
            cpf_existe = 0;
            printf("\nDigite seu CPF com 11 digitos (apenas numeros): ");
            scanf("%11s", cpf_digitado); // Lê até 11 caracteres
            limpar_buffer_entrada();

            // Verifica tamanho correto do CPF
            if (strlen(cpf_digitado) != 11)
            {
                printf("\nCPF invalido (tamanho incorreto), tente novamente.\n");
                continue;
            }

            // Verifica se CPF é válido segundo regra oficial
            if (!cpf_valido(cpf_digitado))
            {
                printf("\nCPF invalido (formato incorreto), tente novamente.\n");
                continue;
            }

            // Verifica se CPF já foi cadastrado
            for (i = 0; i < indice_clientes; i++)
            {
                if (strcmp(cpf_digitado, clientes[i].cpf) == 0)
                {
                    cpf_existe = 1;
                    break;
                }
            }

            if (cpf_existe)
            {
                printf("\nCPF ja cadastrado, tente novamente.\n");
                continue;
            }

            // CPF válido e não duplicado, copia e sai do loop
            strcpy(clientes[indice_clientes].cpf, cpf_digitado);
            break;

        } while (1);

        indice_clientes++; // Incrementa índice para próximo cliente
        printf("\nCliente cadastrado com sucesso!\n");
    }
    else
    {
        printf("\nErro: Capacidade maxima de clientes atingida!\n");
    }
}

void listagemClientes()
{
    int total_compras;

    printf("----- Lista de Clientes -----\n");
    printf("CPF             | Nome                          | Compras Realizadas\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < indice_clientes; i++)
    {
        total_compras = 0;
        for (int j = 0; j < indice_vendas; j++)
        {
            if (strcmp(clientes[i].cpf, vendas[j].cpf_cliente) == 0)
            {
                total_compras++;
            }
        }

        printf("CPF: %s | Nome: %-30s | Compras Realizadas: %d\n", clientes[i].cpf, clientes[i].nome, total_compras);
    }
}
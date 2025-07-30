#include "clientes.h"
#include "global.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

// Aqui estão as funções de cadastro e listagem de clientes

// Função para cadastrar clientes
void cadastraClientes()
{
    int i, cpf_existe;
    char cpf_digitado[12]; // CPF com 11 dígitos + o '\0' no final (string)

    // Verifica se ainda há espaço para cadastrar mais clientes
    if (indice_clientes < CLIENTES)
    {
        // --- Cadastro do nome ---
        // Faz um loop até o usuário digitar um nome válido
        do
        {
            printf("\nDigite seu nome: ");
            fgets(clientes[indice_clientes].nome, TAM_MAX_NOME, stdin); // Lê o nome
            clientes[indice_clientes].nome[strcspn(clientes[indice_clientes].nome, "\n")] = '\0'; // Remove o '\n' no final

            // Verifica se o nome é válido (não vazio e não só espaços)
            if (!nome_valido(clientes[indice_clientes].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
            }
        } while (!nome_valido(clientes[indice_clientes].nome));

        // --- Cadastro do CPF ---
        do
        {
            cpf_existe = 0; // Começa assumindo que o CPF ainda não existe
            printf("\nDigite seu CPF com 11 digitos (apenas numeros): ");
            scanf("%11s", cpf_digitado); // Lê até 11 caracteres
            limpar_buffer_entrada(); // Limpa o buffer (caso sobre \n da entrada)

            // Verifica se o CPF tem exatamente 11 caracteres
            if (strlen(cpf_digitado) != 11)
            {
                printf("\nCPF invalido (tamanho incorreto), tente novamente.\n");
                continue;
            }

            // Verifica se o CPF segue as regras de validação
            if (!cpf_valido(cpf_digitado))
            {
                printf("\nCPF invalido (formato incorreto), tente novamente.\n");
                continue;
            }

            // Verifica se esse CPF já foi cadastrado anteriormente
            for (i = 0; i < indice_clientes; i++)
            {
                if (strcmp(cpf_digitado, clientes[i].cpf) == 0)
                {
                    cpf_existe = 1;
                    break;
                }
            }

            // Se CPF já existe, avisa o usuário e volta pro início do loop
            if (cpf_existe)
            {
                printf("\nCPF ja cadastrado, tente novamente.\n");
                continue;
            }

            // Se CPF passou por todas as validações, copia pro cadastro e sai do loop
            strcpy(clientes[indice_clientes].cpf, cpf_digitado);
            break;

        } while (1); // Loop infinito até quebrar com break

        // Se tudo deu certo, incrementa o índice de clientes
        indice_clientes++;
        printf("\nCliente cadastrado com sucesso!\n");
    }
    else
    {
        // Se atingiu o limite de clientes, avisa o usuário
        printf("\nErro: Capacidade maxima de clientes atingida!\n");
    }
}

// Função para listar os clientes já cadastrados
void listagemClientes()
{
    int total_compras;

    // Cabeçalho da listagem
    printf("----- Lista de Clientes -----\n");
    printf("CPF             | Nome                          | Compras Realizadas\n");
    printf("---------------------------------------------------------------\n");

    // Passa por todos os clientes
    for (int i = 0; i < indice_clientes; i++)
    {
        total_compras = 0;

        // Conta quantas compras cada cliente já fez
        for (int j = 0; j < indice_vendas; j++)
        {
            if (strcmp(clientes[i].cpf, vendas[j].cpf_cliente) == 0)
            {
                total_compras++;
            }
        }

        // Exibe os dados do cliente com o total de compras
        printf("CPF: %s | Nome: %-30s | Compras Realizadas: %d\n", clientes[i].cpf, clientes[i].nome, total_compras);
    }
}

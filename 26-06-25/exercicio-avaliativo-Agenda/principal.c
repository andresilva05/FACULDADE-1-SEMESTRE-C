// Insira as funcionalidades no projeto Agenda:
// 1)Menu no programa principal
// 2)No contato, acrescente os campos para telefone e endereço
// 3)Adeque as funções relativas a entrada e saída de dados do contato para suportar as
// alterações solicitadas em (2)
// 4)Valide se a data de nascimento é válida, usando a função verificaData da biblioteca
// data.h
// 5)Valide todas as entradas de dados, de preferência com o uso de funções

#include <stdio.h>
#include <string.h>
#include "data.c"
#include "utils.c"
#include "datatype.h"

// Declaração da variável global que armazena a lista de contatos
ListaDeContatos agenda;

// Protótipos das funções utilizadas
int menu();
void pedeContato();
void exibeContatos();
int verificaContato(Contato c);

int main()
{
    int opcao;

    // Loop principal do programa que exibe o menu e executa as opções escolhidas
    do
    {
        opcao = menu(); // Exibe menu e captura a opção do usuário

        if (opcao == 1)
        {
            pedeContato(); // Solicita entrada dos contatos
        }
        else if (opcao == 2)
        {
            exibeContatos(); // Exibe os contatos cadastrados
        }
        else if (opcao == 3)
        {
            printf("Encerrando!"); // Finaliza o programa
        }
        else
        {
            printf("Opcao invalida!\n"); // Caso opção seja inválida, avisa o usuário
        }

    } while (opcao != 3);
}

// Função que exibe o menu principal e lê a opção escolhida pelo usuário
int menu()
{
    int opcao;
    printf("\n===== MENU =====\n");
    printf("1. Informar Agenda\n");
    printf("2. Exibir lista de contatos\n");
    printf("3. Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);   // Lê opção numérica
    limparBufferEntrada(); // Limpa o buffer para evitar problemas com leitura posterior

    return opcao;
}

// Função que solicita a entrada dos dados para os contatos
void pedeContato()
{
    for (int i = 0; i < TAM_AGENDA; i++)
    {
        do
        {
            printf("\nEntre com o nome: ");
            gets(agenda.contato[i].nome); // Lê o nome do contato (atenção: gets é inseguro)

            printf("Entre com o email: ");
            gets(agenda.contato[i].email); // Lê o email

            printf("Entre com o endereço: ");
            gets(agenda.contato[i].endereco); // Lê o endereço

            agenda.contato[i].dataDeNascimento = lerData(); // Lê a data de nascimento do contato

            printf("Entre com o telefone: ");
            gets(agenda.contato[i].telefone); // Lê o telefone

            // Verifica se os campos obrigatórios estão preenchidos corretamente
            if (!verificaContato(agenda.contato[i]))
            {
                printf("Erro: nome, email, endereco e telefone nao podem estar vazios!\n");
            }

        } while (!verificaContato(agenda.contato[i])); // Repetir enquanto os dados forem inválidos

        limparBufferEntrada(); // Limpa buffer após entrada, especialmente se usar fgets
    }
}

// Função que exibe os contatos cadastrados na agenda
void exibeContatos()
{
    printf("\n\n Agenda");
    for (int i = 0; i < TAM_AGENDA; i++)
    {
        printf("\n (%d) Nome: %s, ", i + 1, agenda.contato[i].nome);
        printf("\nData de nascimento: ");
        imprimirData(agenda.contato[i].dataDeNascimento);
        printf("\nEmail: %s ", agenda.contato[i].email);
        printf("\nTelefone: %s ", agenda.contato[i].telefone);
        printf("\nEndereco: %s \n\n", agenda.contato[i].endereco);
    }
}

// Função que verifica se os campos obrigatórios do contato estão preenchidos corretamente
int verificaContato(Contato c)
{
    return verificaTextoString(c.nome) &&     // Verifica se nome não está vazio ou só espaços
           verificaTextoString(c.email) &&    // Verifica se email não está vazio ou só espaços
           verificaTextoString(c.endereco) && // Verifica se endereço não está vazio ou só espaços
           verificaTextoString(c.telefone);   // Verifica se telefone não está vazio ou só espaços
}

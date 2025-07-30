#include <stdio.h>    // Para printf, scanf
#include "produtos.c" // cadastrar_produto, listar_produtos, atualizar_estoque, buscar_produto, etc.
#include "clientes.c" // funções de clientes (se houver no menu)
#include "vendas.c"   // funções de vendas
#include "global.c"   // variáveis globais
#include "util.c"     // limpar_buffer_entrada, aguardar_tecla, limpar_tela, etc.

void exibir_menu();

int main()
{
    int opcao;
    do
    {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer_entrada();

        switch (opcao)
        {
        case 1:
            cadastrar_produto();
            break;
        case 2:
            listar_produtos();
            break;
        case 3:
            atualizar_estoque();
            break;
        case 4:
            buscar_produto();
            break;
        case 5:
            calcular_valor_total();
            break;
        case 6:
            relatorio_estoque_baixo();
            break;
        case 7:
            excluirProduto();
            break;
        case 8:
            cadastraClientes();
            break;
        case 9:
            cadastroDeVendas();
            break;
        case 10:
            listarVendas();
            break;
        case 11:
            listagemClientes();
            break;
        case 12:
            printf("Encerrando o sistema. Ate logo!\n");
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.\n");
            break;
        }

        if (opcao != 12)
            aguardar_tecla();

    } while (opcao != 12);

    return 0;
}

void exibir_menu()
{
    limpar_tela();
    printf("--- SISTEMA DE CONTROLE DE ESTOQUE ---\n");
    printf("1. Cadastrar Novo Produto\n");
    printf("2. Listar Todos os Produtos\n");
    printf("3. Atualizar Estoque de um Produto\n");
    printf("4. Buscar Produto por Nome/ID\n");
    printf("5. Calcular Valor Total do Estoque\n");
    printf("6. Relatorio de Produtos com Estoque Baixo\n");
    printf("7. Excluir Produto\n");
    printf("8. Cadastrar Cliente\n");
    printf("9. Cadastrar Venda\n");
    printf("10. Listar Vendas\n");
    printf("11. Listagem de Clientes\n");
    printf("12. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}

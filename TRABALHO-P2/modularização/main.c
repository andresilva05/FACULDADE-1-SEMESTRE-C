#include "produtos.c"
#include "clientes.c"
#include "vendas.c"
#include <stdio.h>

int main()
{
    int opcao;
    do
    {
        exibir_menu();           // Mostra o menu principal
        scanf("%d", &opcao);     // Lê a opção escolhida
        limpar_buffer_entrada(); // Limpa o buffer para evitar lixo na próxima leitura

        // Avalia a opção escolhida e chama a função correspondente
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
        {
            aguardar_tecla(); // Aguarda o usuário pressionar Enter antes de continuar
        }

    } while (opcao != 12); // Continua enquanto não escolher sair (opção 9)

    return 0;
}

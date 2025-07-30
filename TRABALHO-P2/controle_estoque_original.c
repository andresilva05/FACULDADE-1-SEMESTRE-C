#include <stdio.h>  // Para funções de entrada e saída (printf, scanf)
#include <stdlib.h> // Para funções de sistema (system("cls") ou system("clear"))
#include <string.h> // Para manipulação de strings (strcpy, strstr, strcspn)
#include <ctype.h>  // Para a função isdigit, que verifica se um caractere é um dígito

// --- 1. Definições Globais e Estruturas de Dados ---
#define MAX_PRODUTOS 50
#define TAM_MAX_NOME 100

int indice_atual = 0;
int id_atual = 0; // para gerar ID sequencial e único

typedef struct
{
    int id;
    char nome[TAM_MAX_NOME];
    int quantidade;
    float preco;
    int ativo; // 1 = ativo, 0 = deletado
} Produto;
Produto produtos[MAX_PRODUTOS];

void exibir_menu();
void cadastrar_produto();
void listar_produtos();
void atualizar_estoque();
void buscar_produto();
void calcular_valor_total();
void relatorio_estoque_baixo();
void limpar_buffer_entrada();
void aguardar_tecla();
void limpar_tela();
void excluirProduto();

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
            printf("Encerrando o sistema. Ate logo!\n");
            break;
        default:
            printf("Opcao invalida! Por favor, tente novamente.\n");
            break;
        }

        if (opcao != 8)
        {
            aguardar_tecla();
        }

    } while (opcao != 8);

    return 0;
}

void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void aguardar_tecla()
{
    printf("\nPressione Enter para continuar...");
    getchar();
}

void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
    printf("8. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}
void cadastrar_produto()
{
    limpar_tela();
    printf("--- 1. Cadastro de Novo Produto ---\n");

    if (indice_atual < MAX_PRODUTOS)
    {
        produtos[indice_atual].id = id_atual++;
        produtos[indice_atual].ativo = 1;

        printf("Digite o nome do produto: ");
        fgets(produtos[indice_atual].nome, TAM_MAX_NOME, stdin);
        produtos[indice_atual].nome[strcspn(produtos[indice_atual].nome, "\n")] = 0;

        printf("Digite a quantidade inicial: ");
        scanf("%d", &produtos[indice_atual].quantidade);
        limpar_buffer_entrada();

        printf("Digite o preco unitario (R$): ");
        scanf("%f", &produtos[indice_atual].preco);
        limpar_buffer_entrada();

        printf("\nProduto '%s' cadastrado com sucesso! ID: %d\n", produtos[indice_atual].nome, produtos[indice_atual].id);
        indice_atual++;
    }
    else
    {
        printf("\nErro: Capacidade maxima de produtos atingida!\n");
    }
}

void listar_produtos()
{
    limpar_tela();
    printf("--- 2. Lista de Produtos Cadastrados ---\n");

    if (indice_atual == 0)
    {
        printf("Nenhum produto cadastrado ainda.\n");
    }
    else
    {
        printf("%-5s | %-30s | %-10s | %-10s\n", "ID", "Nome", "Qtd.", "Preco (R$)");
        printf("------------------------------------------------------------------\n");

        for (int i = 0; i < indice_atual; i++)
        {
            if (produtos[i].ativo == 1)
            {
                printf("%-5d | %-30s | %-10d | R$ %-8.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            }
            else
            {
                printf("%-5d | %-30s | %-10s | %-10s\n",
                       produtos[i].id, "Produto Deletado", "-", "-");
            }
        }
    }
}
void atualizar_estoque()
{
    int id_produto;
    int quantidade_movimento;
    int encontrado = 0;

    limpar_tela();
    printf("--- 3. Atualizar Estoque ---\n");
    printf("Digite o ID do produto que deseja atualizar: ");
    scanf("%d", &id_produto);
    limpar_buffer_entrada();

    // Procura o produto pelo ID (não pelo índice)
    for (int i = 0; i < indice_atual; i++)
    {
        if (produtos[i].id == id_produto && produtos[i].ativo == 1)
        {
            printf("\nProduto selecionado: %s\n", produtos[i].nome);
            printf("Estoque atual: %d\n", produtos[i].quantidade);
            printf("Digite a quantidade a ser adicionada (ex: 10) ou removida (ex: -5): ");
            scanf("%d", &quantidade_movimento);
            limpar_buffer_entrada();

            if ((produtos[i].quantidade + quantidade_movimento) >= 0)
            {
                produtos[i].quantidade += quantidade_movimento;
                printf("\nEstoque atualizado com sucesso! Novo estoque: %d\n", produtos[i].quantidade);
            }
            else
            {
                printf("\nErro: Operacao invalida. O estoque nao pode ficar negativo.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nErro: Produto com ID %d nao encontrado ou deletado.\n", id_produto);
    }
}
void buscar_produto()
{
    char termo_busca[TAM_MAX_NOME];
    int id_busca = -1;
    int encontrado = 0;

    limpar_tela();
    printf("--- 4. Buscar Produto ---\n");
    printf("Digite o ID ou parte do nome do produto: ");
    fgets(termo_busca, TAM_MAX_NOME, stdin);
    termo_busca[strcspn(termo_busca, "\n")] = 0;

    // Tenta buscar por ID
    if (sscanf(termo_busca, "%d", &id_busca) == 1)
    {
        for (int i = 0; i < indice_atual; i++)
        {
            if (produtos[i].id == id_busca)
            {
                if (produtos[i].ativo == 1)
                {
                    printf("\n--- Produto Encontrado por ID ---\n");
                    printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                           produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
                }
                else
                {
                    printf("\nProduto com ID %d foi deletado.\n", id_busca);
                }
                encontrado = 1;
                break;
            }
        }
    }

    // Se não achou por ID, busca por nome
    if (!encontrado)
    {
        printf("\n--- Resultados da Busca por Nome '%s' ---\n", termo_busca);
        for (int i = 0; i < indice_atual; i++)
        {
            if (produtos[i].ativo == 1 && strstr(produtos[i].nome, termo_busca) != NULL)
            {
                printf("ID: %d | Nome: %s | Qtd: %d | Preco: R$ %.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
                encontrado = 1;
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum produto encontrado com o termo '%s'.\n", termo_busca);
    }
}

void calcular_valor_total()
{
    double valor_total_estoque = 0.0;

    for (int i = 0; i < indice_atual; i++)
    {
        if (produtos[i].ativo == 1)
        {
            valor_total_estoque += (double)produtos[i].quantidade * produtos[i].preco;
        }
    }

    limpar_tela();
    printf("--- 5. Valor Total do Estoque ---\n");
    printf("O valor total de todos os produtos em estoque e: R$ %.2f\n", valor_total_estoque);
}
void relatorio_estoque_baixo()
{
    int limite_estoque;
    int encontrou_item_baixo = 0;

    limpar_tela();
    printf("--- 6. Relatorio de Estoque Baixo ---\n");
    printf("Digite a quantidade limite para considerar o estoque baixo (ex: 5): ");
    scanf("%d", &limite_estoque);
    limpar_buffer_entrada();

    printf("\n--- Produtos com estoque igual ou inferior a %d ---\n", limite_estoque);

    for (int i = 0; i < indice_atual; i++)
    {
        if (produtos[i].ativo == 1 && produtos[i].quantidade <= limite_estoque)
        {
            printf("ID: %d | Nome: %s | Estoque Atual: %d\n", produtos[i].id, produtos[i].nome, produtos[i].quantidade);
            encontrou_item_baixo = 1;
        }
    }

    if (!encontrou_item_baixo)
    {
        printf("Nenhum produto com estoque baixo encontrado.\n");
    }
}

void excluirProduto()
{
    int id_deletado;
    int encontrado = 0;

    printf("Digite ID do produto que deseja deletar: ");
    scanf("%d", &id_deletado);
    limpar_buffer_entrada();

    for (int i = 0; i < indice_atual; i++)
    {
        if (produtos[i].id == id_deletado)
        {
            if (produtos[i].ativo == 1)
            {
                produtos[i].ativo = 0;
                printf("Produto com ID %d deletado com sucesso.\n", id_deletado);
            }
            else
            {
                printf("Produto com ID %d já está deletado.\n", id_deletado);
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Produto não encontrado.\n");
    }
}
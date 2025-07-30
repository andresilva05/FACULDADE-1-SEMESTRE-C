#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 50    // Limite máximo de livros no sistema
#define TAM_MAX_NOME 100 // Tamanho máximo para nomes (livros)

void exibi_menu();
void limpar_tela();
void incluir_livro();
int nome_valido(char nome[]);
void limpar_buffer_entrada();
void aguardar_tecla();

// Estrutura que representa um Livro
typedef struct
{
    int id;                   // Identificador único do livro
    char nome[TAM_MAX_NOME];  // Título do livro
    char autor[TAM_MAX_NOME]; // Nome do autor
    int quantidade;           // Quantidade de exemplares disponíveis
    float preco;              // Preço unitário do livro
    int ativo;                // 1 = ativo / 0 = removido do sistema
} Livro;

Livro livros[MAX_LIVROS]; // Vetor que armazena os livros cadastrados

int indice_livros = 0; // Próxima posição livre no vetor
int id_atual = 1;      // ID sequencial para livros

int main()
{
    int opcao;
    do
    {
        exibi_menu();
        scanf("%d", &opcao);
        limpar_buffer_entrada();

        switch (opcao)
        {
        case 1:
            incluir_livro();
            break;
        case 2:
            // excluir_livro();
            break;
        case 3:
            // listar_livro();
            break;
        case 4:
            // atualizar_estoque();
            break;

        case 5:
            // buscar_livro();
            break;
        case 6:
            // calcular_valor_total();
            break;
        case 7:
            // relatorio_estoque_baixo();
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
            aguardar_tecla(); // Aguarda o usuário pressionar Enter antes de continuar
        }

    } while (opcao != 8);

    return 0;
}

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Comando do Windows
#else
    system("clear"); // Comando do Linux/Mac
#endif
}

void exibi_menu()
{

    limpar_tela();
    printf("--- SISTEMA DE CONTROLE DE BIBLIOTECA ---\n");
    printf("1. Cadastrar Novo Livro\n");
    printf("2. Excluir livro\n");
    printf("3. Listar livros\n");
    printf("4. Atualizar estoque\n");
    printf("5. Buscar livro por NOME/ID\n");
    printf("6. Calcular valor total\n");
    printf("7. Relatorio de estoque baixo\n");
    printf("8. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}

void incluir_livro()
{
    limpar_tela();

    printf("--- 1. Cadastro de Novo Livro ---\n");

    if (indice_livros < MAX_LIVROS)
    {
        livros[indice_livros].id = id_atual++; // Define ID único sequencial
        livros[indice_livros].ativo = 1;       // Marca como ativo

        int nome_existente;
        int autor_existente;

        do
        {
            printf("Digite o nome do livro: ");
            fgets(livros[indice_livros].nome, TAM_MAX_NOME, stdin);
            livros[indice_livros].nome[strcspn(livros[indice_livros].nome, "\n")] = '\0'; // Remove o '\n'

            if (!nome_valido(livros[indice_livros].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            printf("Digite o nome do autor: ");
            fgets(livros[indice_livros].autor, TAM_MAX_NOME, stdin);
            livros[indice_livros].autor[strcspn(livros[indice_livros].autor, "\n")] = '\0'; // Remove o '\n'

            if (!nome_valido(livros[indice_livros].autor))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            nome_existente = 0;
            autor_existente = 0;

            for (int i = 0; i < indice_livros; i++)
            {
                if (strcmp(livros[i].nome, livros[indice_livros].nome) == 0 || strcmp(livros[i].autor, livros[indice_livros].autor) == 0)
                {
                    nome_existente = 1;
                    autor_existente = 1;
                    printf("Erro: Nome do livro ou autor ja cadastrados. Escolha outro nome ou autor.\n");
                    break;
                }
            }

        } while (nome_existente != 0 && autor_existente != 0);

        do
        {
            printf("\nDigite a quantidade inicial: ");
            scanf("%d", &livros[indice_livros].quantidade);
            limpar_buffer_entrada(); // Limpa buffer após scanf

            printf("\nDigite o preco unitario (R$): ");
            scanf("%f", &livros[indice_livros].preco);
            limpar_buffer_entrada(); // Limpa buffer

            if (livros[indice_livros].quantidade < 0 || livros[indice_livros].preco < 0)
            {
                printf("\nErro: R$Preco ou quantidade nao pode ser negativos");
            }
            else
            {
                printf("\nLivro '%s' cadastrado com sucesso! ID: %d\n", livros[indice_livros].nome, livros[indice_livros].id);
                indice_livros++; // Incrementa índice para próximo cadastro
            }
        } while (livros[indice_livros].quantidade < 0 || livros[indice_livros].preco < 0);
    }
}

// Função que verifica se um nome é válido (não vazio ou só espaços)
int nome_valido(char nome[])
{
    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\t')
        {
            return 1; // nome válido (tem caractere não branco)
        }
    }
    return 0; // inválido (vazio ou só espaços)
}
// Função para limpar o buffer do teclado (stdin), evitando problemas em entradas futuras
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // descarta todos os caracteres até o fim da linha
    }
}

// Função que aguarda o usuário pressionar Enter
void aguardar_tecla()
{
    printf("\nPressione Enter para continuar...");
    getchar();
}
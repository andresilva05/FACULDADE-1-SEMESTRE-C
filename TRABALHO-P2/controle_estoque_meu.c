#include <stdio.h>  // Para funções de entrada e saída (printf, scanf)
#include <stdlib.h> // Para funções de sistema (system("cls") ou system("clear"))
#include <string.h> // Para manipulação de strings (strcpy, strstr, strcspn)
#include <ctype.h>  // Para a função isdigit, que verifica se um caractere é um dígito

// --- 1. Definições Globais e Estruturas de Dados ---
#define MAX_PRODUTOS 50  // Limite máximo de produtos no sistema
#define TAM_MAX_NOME 100 // Tamanho máximo para nomes (produtos e clientes)
#define CLIENTES 10      // Limite máximo de clientes no sistema
#define MAX_VENDAS 100   // Limite máximo de vendas

int indice_produtos = 0; // Índice atual para cadastro de produtos
int indice_clientes = 0; // Índice atual para cadastro de clientes
int id_atual = 1;        // ID sequencial para produtos
int indice_vendas = 0;

// Estrutura que representa um Produto
typedef struct
{
    int id;                  // Identificador único do produto
    char nome[TAM_MAX_NOME]; // Nome do produto
    int quantidade;          // Quantidade disponível no estoque
    float preco;             // Preço unitário do produto
    int ativo;               // Flag para indicar se o produto está ativo (1) ou deletado (0)
} Produto;
Produto produtos[MAX_PRODUTOS]; // Vetor que armazena os produtos

// Estrutura que representa um Cliente
typedef struct
{
    char cpf[12];            // CPF do cliente (11 dígitos + '\0')
    char nome[TAM_MAX_NOME]; // Nome do cliente
    int qtdCompras;          // Quantidade total de compras realizadas (a implementar)
} Cliente;
Cliente clientes[CLIENTES]; // Vetor que armazena os clientes

typedef struct
{
    int id;
    int dia;
    int mes;
    int ano;
    char cpf_cliente[12];
    int id_produto;
    int quantidade;
} Venda;

Venda vendas[MAX_VENDAS];

// Protótipos das funções usadas no programa
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
void cadastraClientes();
int cpf_valido(char cpf[]);
int nome_valido(char nome[]);
void cadastroDeVendas();
int verificaData(Venda vendas);
int ehBissexto(int ano);
void listarVendas();
void listagemClientes();

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

// Função para limpar a tela, dependendo do sistema operacional
void limpar_tela()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux/Mac
#endif
}

// Exibe o menu principal do sistema
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

void cadastrar_produto()
{
    limpar_tela();
    printf("--- 1. Cadastro de Novo Produto ---\n");

    if (indice_produtos < MAX_PRODUTOS)
    {
        produtos[indice_produtos].id = id_atual++; // Define ID único sequencial
        produtos[indice_produtos].ativo = 1;       // Marca como ativo

        int nome_existente;
        do
        {
            printf("Digite o nome do produto: ");
            fgets(produtos[indice_produtos].nome, TAM_MAX_NOME, stdin);
            produtos[indice_produtos].nome[strcspn(produtos[indice_produtos].nome, "\n")] = '\0'; // Remove o '\n'

            if (!nome_valido(produtos[indice_produtos].nome))
            {
                printf("Nome invalido! Nao pode ser vazio ou apenas espacos. Tente novamente.\n");
                continue;
            }

            nome_existente = 0;
            for (int i = 0; i < indice_produtos; i++)
            {
                if (strcmp(produtos[i].nome, produtos[indice_produtos].nome) == 0)
                {
                    nome_existente = 1;
                    printf("Erro: Nome do produto ja cadastrado. Escolha outro nome.\n");
                    break;
                }
            }
        } while (nome_existente != 0);

        do
        {
            printf("\nDigite a quantidade inicial: ");
            scanf("%d", &produtos[indice_produtos].quantidade);
            limpar_buffer_entrada(); // Limpa buffer após scanf

            printf("\nDigite o preco unitario (R$): ");
            scanf("%f", &produtos[indice_produtos].preco);
            limpar_buffer_entrada(); // Limpa buffer

            if (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0)
            {
                printf("\nErro: R$Preco ou quantidade nao pode ser negativos");
            }
            else
            {
                printf("\nProduto '%s' cadastrado com sucesso! ID: %d\n", produtos[indice_produtos].nome, produtos[indice_produtos].id);
                indice_produtos++; // Incrementa índice para próximo cadastro
            }

        } while (produtos[indice_produtos].quantidade < 0 || produtos[indice_produtos].preco < 0);
    }
    else
    {
        printf("\nErro: Capacidade maxima de produtos atingida!\n");
    }
}

// Função que lista todos os produtos cadastrados
void listar_produtos()
{
    limpar_tela();
    printf("--- 2. Lista de Produtos Cadastrados ---\n");

    if (indice_produtos == 0)
    {
        printf("Nenhum produto cadastrado ainda.\n");
    }
    else
    {
        // Cabeçalho da tabela
        printf("%-5s | %-30s | %-10s | %-10s\n", "ID", "Nome", "Qtd.", "Preco (R$)");
        printf("------------------------------------------------------------------\n");

        for (int i = 0; i < indice_produtos; i++)
        {
            if (produtos[i].ativo == 1)
            {
                // Imprime os dados do produto ativo
                printf("%-5d | %-30s | %-10d | R$ %-8.2f\n",
                       produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            }
            else
            {
                // Produto deletado, exibe mensagem alternativa
                printf("%-5d | %-30s | %-10s | %-10s\n",
                       produtos[i].id, "Produto Deletado", "-", "-");
            }
        }
    }
}

// Função para atualizar o estoque de um produto pelo ID
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

    // Procura produto pelo ID e verifica se está ativo
    for (int i = 0; i < indice_produtos; i++)
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

// Função para buscar produto por ID ou parte do nome
void buscar_produto()
{
    char termo_busca[TAM_MAX_NOME];
    int id_busca = -1;
    int encontrado = 0;

    limpar_tela();
    printf("--- 4. Buscar Produto ---\n");
    printf("Digite o ID ou parte do nome do produto: ");
    fgets(termo_busca, TAM_MAX_NOME, stdin);
    termo_busca[strcspn(termo_busca, "\n")] = 0; // Remove o '\n' final

    // Tenta interpretar a entrada como ID (número)
    if (sscanf(termo_busca, "%d", &id_busca) == 1)
    {
        for (int i = 0; i < indice_produtos; i++)
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

    // Se não achou por ID, busca por nome (substring)
    if (!encontrado)
    {
        printf("\n--- Resultados da Busca por Nome '%s' ---\n", termo_busca);
        for (int i = 0; i < indice_produtos; i++)
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

// Função para calcular e exibir o valor total dos produtos em estoque
void calcular_valor_total()
{
    double valor_total_estoque = 0.0;

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].ativo == 1)
        {
            // Multiplica quantidade pelo preço e acumula
            valor_total_estoque += (double)produtos[i].quantidade * produtos[i].preco;
        }
    }

    limpar_tela();
    printf("--- 5. Valor Total do Estoque ---\n");
    printf("O valor total de todos os produtos em estoque e: R$ %.2f\n", valor_total_estoque);
}

// Função que lista produtos com estoque baixo (igual ou inferior ao limite)
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

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].ativo == 1 && produtos[i].quantidade <= limite_estoque)
        {
            if (produtos[i].quantidade <= 0)
            {
                printf("ID: %d | Nome: %s | Estoque Atual: Sem estoque\n", produtos[i].id, produtos[i].nome);
            }
            else
            {
                printf("ID: %d | Nome: %s | Estoque Atual: %d\n", produtos[i].id, produtos[i].nome, produtos[i].quantidade);
            }
            encontrou_item_baixo = 1;
        }
    }

    if (!encontrou_item_baixo)
    {
        printf("Nenhum produto com estoque baixo encontrado.\n");
    }
}

// Função para "excluir" produto (marca como inativo)
void excluirProduto()
{
    int id_deletado;
    int encontrado = 0;

    printf("Digite ID do produto que deseja deletar: ");
    scanf("%d", &id_deletado);
    limpar_buffer_entrada();

    for (int i = 0; i < indice_produtos; i++)
    {
        if (produtos[i].id == id_deletado)
        {
            for (int j = 0; j < indice_vendas; j++)
            {
                if (vendas[j].id_produto == id_deletado)
                {
                    printf("\n-Este produto já foi vendido e não pode ser excluído.");
                    return;
                }
            }

            if (produtos[i].ativo == 1)
            {

                produtos[i].ativo = 0; // Marca como deletado
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

int cpf_valido(char cpf[])
{
    int i;
    int todos_iguais = 1;

    for (i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            todos_iguais = 0;
            break;
        }
    }

    if (todos_iguais)
        return 0;

    int numeros[11];
    for (i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0;
        numeros[i] = cpf[i] - '0';
    }

    int soma = 0;
    for (i = 0; i < 9; i++)
    {
        soma += numeros[i] * (10 - i);
    }

    int primeiro_digito = (soma * 10) % 11;
    if (primeiro_digito == 10)
        primeiro_digito = 0;
    if (numeros[9] != primeiro_digito)
        return 0;

    soma = 0;
    for (i = 0; i < 10; i++)
    {
        soma += numeros[i] * (11 - i);
    }

    int segundo_digito = (soma * 10) % 11;
    if (segundo_digito == 10)
        segundo_digito = 0;
    if (numeros[10] != segundo_digito)
        return 0;

    return 1;
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
void cadastroDeVendas()
{
    // Verifica se há produtos e clientes cadastrados antes de iniciar
    if (indice_produtos == 0)
    {
        printf("\nNao ha produtos cadastrados. Cadastre ao menos um produto antes de realizar uma venda.\n");
        return;
    }
    if (indice_clientes == 0)
    {
        printf("\nNao ha clientes cadastrados. Cadastre ao menos um cliente antes de realizar uma venda.\n");
        return;
    }

    char cpf_temp[12]; // Variável para armazenar o CPF temporariamente
    int i, cpf_existe, produto_existe, qtdProduto, qtd_Estoque;

    // Etapa 1 - Validação da data
    while (!verificaData(vendas[indice_vendas]))
    {
        printf("\nInforme a data da venda (dd mm aaaa): ");
        scanf("%d %d %d",
              &vendas[indice_vendas].dia,
              &vendas[indice_vendas].mes,
              &vendas[indice_vendas].ano);

        limpar_buffer_entrada(); // Limpa o buffer após a leitura
    }

    // Etapa 2 - Verificação do CPF
    do
    {
        printf("\nDigite seu CPF com 11 digitos (apenas numeros): ");
        scanf("%s", cpf_temp);
        limpar_buffer_entrada();
        cpf_existe = 0; // Reinicia a verificação
        for (i = 0; i < indice_clientes; i++)
        {
            if (strcmp(cpf_temp, clientes[i].cpf) == 0)
            {
                cpf_existe = 1;
                // Copia o CPF validado para a venda
                strcpy(vendas[indice_vendas].cpf_cliente, cpf_temp);
                break;
            }
        }
        if (!cpf_existe)
        {
            printf("\nCPF nao encontrado, tente novamente.\n");
        }

    } while (!cpf_existe);

    // Etapa 3 - Verificação do produto
    int idProduto;
    do
    {
        printf("\nDigite id do produto: ");
        scanf("%d", &idProduto);
        limpar_buffer_entrada();

        produto_existe = 0;

        for (i = 0; i < indice_produtos; i++)
        {
            if (idProduto == produtos[i].id && produtos[i].ativo == 1)
            {
                if (produtos[i].quantidade == 0)
                {
                    int opcao;
                    printf("\nProduto com estoque zerado. Nao e possivel realizar a venda desse item.\n");
                    printf("Deseja:\n");
                    printf("1. Tentar outro produto\n");
                    printf("2. Cancelar venda\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
                    limpar_buffer_entrada();

                    if (opcao == 2)
                    {
                        printf("\nVenda cancelada pelo usuario.\n");
                        return; // Sai da função de venda
                    }

                    produto_existe = 0; // continua no loop para tentar outro produto
                }
                else
                {
                    produto_existe = 1;
                    vendas[indice_vendas].id_produto = idProduto;
                }
                break;
            }
        }
        if (!produto_existe)
        {
            printf("\nProduto inexistente ou inativo. Tente novamente.\n");
        }

    } while (!produto_existe);

    // Etapa 4 - Validação da quantidade
    do
    {
        qtdProduto = 0;
        qtd_Estoque = 0;

        printf("\nQuantas unidades deseja vender?");
        scanf("%d", &qtdProduto);
        limpar_buffer_entrada();

        if (qtdProduto > 0)
        {
            for (i = 0; i < indice_produtos; i++)
            {
                if (produtos[i].id == idProduto)
                {
                    qtd_Estoque = produtos[i].quantidade;

                    if (qtdProduto <= qtd_Estoque)
                    {
                        // Quantidade válida, atualiza estoque e registra venda
                        vendas[indice_vendas].quantidade = qtdProduto;
                        produtos[i].quantidade -= qtdProduto;
                    }
                    else
                    {
                        printf("\nEstoque insuficiente. Estoque possui %d unidade(s)", produtos[i].quantidade);
                        qtdProduto = -1; // Força repetição do loop
                    }

                    break; // Produto já encontrado
                }
            }
        }
        else
        {
            printf("\nQuantidade de produtos nao pode ser 0!");
        }

    } while (qtdProduto <= 0 || qtdProduto > qtd_Estoque);

    // Etapa 5 - Geração do ID da venda e incremento do índice
    vendas[indice_vendas].id = indice_vendas + 1;
    indice_vendas++;

    printf("\nVenda registrada com sucesso!\n");
}

// Função que verifica se a data passada é válida
int verificaData(Venda vendas)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDias;

    // Verifica se dia, mês e ano estão dentro de valores básicos válidos
    if (vendas.dia < 1 || vendas.dia > 31 || vendas.mes < 1 || vendas.mes > 12 || vendas.ano < 1)
    {
        return 0; // Data inválida
    }

    // Obtém o número máximo de dias para o mês informado
    maxDias = diasPorMes[vendas.mes - 1];

    // Se for fevereiro e o ano for bissexto, ajusta o máximo de dias para 29
    if (vendas.mes == 2 && ehBissexto(vendas.ano))
    {
        maxDias = 29;
    }

    // Verifica se o dia não ultrapassa o máximo permitido para o mês
    if (vendas.dia > maxDias)
    {
        return 0; // Data inválida
    }

    return 1; // Data válida
}
int ehBissexto(int ano)
{
    // Ano bissexto: múltiplo de 4, não múltiplo de 100, ou múltiplo de 400
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1; // É bissexto
    }
    else
    {
        return 0; // Não é bissexto
    }
}

void listarVendas()
{

    int i, j, k, encontrouCliente;
    printf("\nVendas ate o momento");

    for (i = 0; i < indice_vendas; i++)
    {
        encontrouCliente = 0;
        printf("\n-----------------------------");
        printf("\nId da Venda: %d", vendas[i].id);
        printf("\nData da Venda: %02d/%02d/%04d", vendas[i].dia, vendas[i].mes, vendas[i].ano);

        for (j = 0; j < indice_clientes; j++)
        {
            if (strcmp(vendas[i].cpf_cliente, clientes[j].cpf) == 0)
            {
                printf("\nCliente:");
                printf("\n - Nome: %s", clientes[j].nome);
                printf("\n - CPF: %s", vendas[i].cpf_cliente);
                encontrouCliente = 1;
                break;
            }
        }
        for (k = 0; k < indice_produtos; k++)
        {
            if (vendas[i].id_produto == produtos[k].id)
            {
                printf("\nProduto:");
                printf("\n - ID: %d", produtos[k].id);
                printf("\n - Nome: %s", produtos[k].nome);
            }
        }
        if (encontrouCliente == 0)
        {
            printf("\nCliente: Não encontrado.");
        }
    }
    printf("\n-----------------------------\n");
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
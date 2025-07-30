// 4. Sorteio de Brindes no SuperMercado Algorítmico. O supermercado Algorítmico está fazendo
// uma promoção: quando faz uma compra, o cliente participa de um sorteio e, se agraciado, ganha
// um prêmio.
// O sorteio é feito da seguinte maneira: o comprador fala um número entre 1 e 512. O programa
// pesquisa se esse número está armazenado em um vetor de inteiros com 16 posições, preenchido
// com números aleatórios entre 1 e 512. Se o número falado estiver no vetor, o comprador ganha o
// prêmio.
// Você deve usar recursos da linguagem de programação para gerar os números aleatórios. Não
// devem existir números repetidos no vetor. O programa deve permitir criar um novo conjunto de
// números a qualquer momento. Deve ser possível exibir na tela este vetor, de forma limpa e
// compacta.
// Implemente os algoritmos da Pesquisa Sequencial e Pesquisa Binária para fazer a busca do
// número no vetor. Lembre-se que para executar a Pesquisa Binária é necessário antes ordenar o
// vetor. Você vai fazê-lo usando o algoritmo SelectSort.
// Inclui as bibliotecas necessárias
#include <stdio.h>  // Biblioteca para entrada e saída
#include <stdlib.h> // Biblioteca para funções como rand() e srand()
#include <time.h>   // Biblioteca para usar time(), que ajuda na geração de números aleatórios diferentes a cada execução

// Define uma constante para o tamanho do vetor
#define TAM 16

// Declaração das funções utilizadas no código
void SelectionSort(int numeros[]);             // Função para ordenar o vetor (Selection Sort)
void exibirVetor(int vetor[]);                 // Função para exibir o vetor na tela
int PesqSeq(int numeros[], int numeroUsuario); // Função para busca sequencial
int PesqBin(int numeros[], int numeroUsuario); // Função para busca binária
void armazenaNumeroAleatorio(int vetor[]);     // Função para gerar e armazenar números aleatórios no vetor

// Função que exibe o menu de opções para o usuário
void menu()
{
    printf("   INFORMACOES SOBRE CODIGO\n");
    printf("De acordo com orientacaoes, faca sua escolha!\n");
    printf("1 - GERA NOVO VETOR\n");
    printf("2 - EXIBIR VETOR\n");
    printf("3 - REALIZA BUSCA SEQUENCIAL\n");
    printf("4 - REALIZA BUSCA BINARIA\n");
    printf("5 - SAIR\n\n");
}

// Função que gera um número aleatório entre 1 e 512
int gerarNumeroAleatorio()
{
    return (rand() % 512) + 1; // Gera números de 1 até 512
}

// Função principal
int main()
{
    int vetor[TAM];      // Declaração do vetor que armazenará os números aleatórios
    int numero;          // Número que o usuário deseja buscar
    int opcao;           // Armazena a opção escolhida no menu
    int vetorGerado = 0; // Variável para verificar se o vetor já foi gerado (0 = não, 1 = sim)

    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios, usando o relógio atual

    // Estrutura de repetição do menu
    do
    {
        menu(); // Exibe o menu
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção do usuário

        // Estrutura de decisão baseada na opção escolhida
        switch (opcao)
        {
        case 1:
            // Gera e armazena os números aleatórios no vetor
            armazenaNumeroAleatorio(vetor);
            vetorGerado = 1; // Marca que o vetor foi gerado
            break;

        case 2:
            // Exibe o vetor, se ele já tiver sido gerado
            if (vetorGerado)
            {
                exibirVetor(vetor);
            }
            else
            {
                printf("Vetor ainda nao gerado.\n");
            }
            break;

        case 3:
            // Realiza busca sequencial no vetor
            if (vetorGerado)
            {
                printf("Digite um numero para buscar (Busca Sequencial): ");
                scanf("%d", &numero); // Lê o número a ser buscado
                int resultado = PesqSeq(vetor, numero);

                if (resultado != -1)
                    printf("Numero encontrado na posicao %d (Busca Sequencial)\n\n", resultado);
                else
                    printf("Numero nao encontrado (Busca Sequencial)\n\n");
            }
            else
            {
                printf("Vetor ainda nao foi gerado.\n");
            }
            break;

        case 4:
            // Realiza busca binária, após ordenar o vetor
            if (vetorGerado)
            {
                printf("Digite um numero para buscar (Busca Binaria): ");
                scanf("%d", &numero);

                SelectionSort(vetor); // Ordena o vetor antes da busca binária

                int resultadoBin = PesqBin(vetor, numero);

                if (resultadoBin != -1)
                    printf("Numero encontrado na posicao %d (Busca Binaria)\n", resultadoBin);
                else
                    printf("Numero nao encontrado (Busca Binaria)\n\n");
            }
            else
            {
                printf("Vetor ainda nao foi gerado.\n");
            }
            break;

        case 5:
            printf("Saindo do programa.\n"); // Encerra o programa
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n"); // Caso o usuário digite uma opção inválida
            break;
        }

    } while (opcao != 5); // Repete até que a opção escolhida seja 5 (Sair)

    return 0; // Fim do programa
}

// Função que exibe os valores armazenados no vetor
void exibirVetor(int vetor[])
{
    int i;
    printf("Vetor: { ");
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]); // Imprime cada elemento do vetor
    }
    printf("}\n"); // Fecha a exibição
}

// Função que gera e armazena números aleatórios no vetor, sem repetição
void armazenaNumeroAleatorio(int vetor[])
{
    int i, j, repetido = 0, numeroGerado;

    printf("Os numeros sorteados foram {");

    for (i = 0; i < TAM; i++) // Percorre cada posição do vetor
    {
        repetido = 1;         // Inicializa como verdadeiro para entrar no while
        while (repetido == 1) // Enquanto gerar um número repetido
        {
            numeroGerado = gerarNumeroAleatorio(); // Gera número aleatório
            repetido = 0;                          // Assume que não é repetido

            // Verifica se o número já está no vetor
            for (j = 0; j < i; j++)
            {
                if (vetor[j] == numeroGerado) // Se for repetido
                {
                    repetido = 1; // Marca que é repetido e sai do for
                }
            }
        }

        vetor[i] = numeroGerado; // Armazena o número no vetor

        printf(" %d,", vetor[i]); // Exibe o número na tela
    }

    printf("}\n\n"); // Fecha a exibição dos números sorteados
}

// Função que realiza a busca sequencial no vetor
int PesqSeq(int numeros[], int numeroUsuario)
{
    int i = 0;

    // Percorre o vetor até encontrar ou chegar no final
    while ((numeros[i] != numeroUsuario) && (i < TAM))
        i = i + 1;

    // Se encontrou, retorna a posição; se não, retorna -1
    if (i < TAM)
        return i;
    else
        return -1;
}

// Função que ordena o vetor utilizando o método Selection Sort
void SelectionSort(int numeros[])
{
    int i, j, posMenor, aux;

    // Percorre cada posição do vetor (exceto a última)
    for (i = 0; i < TAM - 1; i++)
    {
        posMenor = i; // Assume que o menor está na posição atual

        // Busca o menor elemento nas posições restantes
        for (j = i + 1; j < TAM; j++)
        {
            if (numeros[j] < numeros[posMenor])
            {
                posMenor = j; // Atualiza a posição do menor
            }
        }

        // Se encontrou um menor, faz a troca
        if (i != posMenor)
        {
            aux = numeros[i];
            numeros[i] = numeros[posMenor];
            numeros[posMenor] = aux;
        }
    }
}

// Função que realiza a busca binária (vetor precisa estar ordenado)
int PesqBin(int numeros[], int numeroUsuario)
{
    int ini = 0;       // Início da busca (primeira posição)
    int fim = TAM - 1; // Fim da busca (última posição)
    int meio;          // Posição central

    // Enquanto existir intervalo de busca
    while (ini <= fim)
    {
        meio = (ini + fim) / 2; // Calcula o meio do intervalo

        if (numeros[meio] == numeroUsuario) // Se encontrou
            return meio;

        if (numeros[meio] < numeroUsuario) // Se o número do meio é menor
            ini = meio + 1;                // Busca na metade direita

        if (numeros[meio] > numeroUsuario) // Se é maior
            fim = meio - 1;                // Busca na metade esquerda
    }

    return -1; // Não encontrou o número
}

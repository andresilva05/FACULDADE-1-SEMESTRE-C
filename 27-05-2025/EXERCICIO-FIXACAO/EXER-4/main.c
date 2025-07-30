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

#include <stdio.h>

#include "sorteio.c"

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
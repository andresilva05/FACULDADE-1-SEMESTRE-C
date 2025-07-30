#include "sorteio.h"

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

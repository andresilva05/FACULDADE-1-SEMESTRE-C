#include <stdio.h>

#define TAM 6 // Tamanho original do vetor (antes de inserir o novo valor)

void preencherVetor(int vetor[]);
void insereValorNaPosicao(int vetor[], int valor, int posicao);

int main()
{
    int vetor[TAM + 1]; // Cria vetor com espaço extra para inserir novo valor
    int value, posicao;

    // Preenche o vetor com valores do usuário
    preencherVetor(vetor);

    // Pede para o usuário informar o valor a ser inserido e a posição onde inserir
    printf("De um valor e uma posicao:\n");
    scanf("%d %d", &value, &posicao);

    // Insere o valor informado na posição desejada e exibe o vetor atualizado
    insereValorNaPosicao(vetor, value, posicao);

    return 0;
}

// Função para preencher o vetor com valores fornecidos pelo usuário
void preencherVetor(int vetor[])
{
    int i;
    for (i = 0; i < TAM; i++) // Percorre os índices de 0 até TAM-1
    {
        printf("\nValor [%d]: ", i);
        scanf("%d", &vetor[i]); // Lê e armazena o valor na posição i do vetor
    }
}

// Função para inserir um valor na posição dada no vetor, deslocando elementos à direita
void insereValorNaPosicao(int vetor[], int valor, int posicao)
{
    int i;

    // Desloca os elementos do vetor para a direita, a partir da última posição até a posição dada
    for (i = TAM; i > posicao; i--)
    {
        vetor[i] = vetor[i - 1]; // Copia o elemento anterior para a posição atual
    }

    // Insere o novo valor na posição desejada
    vetor[posicao] = valor;

    // Exibe o vetor resultante após a inserção
    printf("V = {");
    for (i = 0; i <= TAM; i++) // Imprime todos os elementos, incluindo o novo (TAM+1 elementos)
    {
        printf("%d ", vetor[i]);
    }
    printf("}\n");
}

// Lê 6 valores inteiros do usuário e armazena em um vetor.

// Solicita um valor e uma posição para inserção no vetor.

// Insere o valor informado na posição especificada dentro do vetor, movendo todos os elementos que estavam naquela posição e à direita uma casa para frente (para não perder nenhum dado).

// Imprime o vetor atualizado, agora com 7 elementos (os 6 originais mais o valor inserido).

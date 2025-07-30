// Escreva uma função que delete um elemento de uma dada posição de um vetor. Por exemplo, se o
// vetor for v = {2, 5, 7, 10, 12, 13} e o elemento a ser deletado for o de posição 4, programa deve
// retornar o vetor v = {2, 5, 7, 12, 13}
#include <stdio.h>
#define TAM 6 // Define o tamanho máximo do vetor

// Declaração das funções
void preencherVetor(int vetor[], int tamanho);
int removerElemento(int vetor[], int tamanho, int posicao);
void imprimirVetor(int vetor[], int tamanho);

int main()
{
    int vetor[TAM];    // Declara o vetor com tamanho máximo TAM
    int tamanho = TAM; // Cria uma variável para controlar o tamanho lógico do vetor
    int posicao;       // Posição do elemento que o usuário quer remover

    // Preenche o vetor com valores fornecidos pelo usuário
    preencherVetor(vetor, tamanho);

    // Pergunta ao usuário qual posição deseja remover
    printf("Digite a posicao do elemento que deseja remover (0 a %d): ", tamanho - 1);
    scanf("%d", &posicao);

    // Verifica se a posição digitada é válida
    if (posicao < 0 || posicao >= tamanho)
    {
        printf("Posicao invalida!\n");
        return 1; // Encerra o programa com erro
    }

    // Chama a função que remove o elemento e atualiza o tamanho
    tamanho = removerElemento(vetor, tamanho, posicao);

    // Mostra o vetor após a remoção
    printf("Vetor apos remocao:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

// Função para preencher o vetor
void preencherVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

// Função que remove um elemento na posição indicada
int removerElemento(int vetor[], int tamanho, int posicao)
{
    // Faz os elementos posteriores "andarem" uma posição para a esquerda
    for (int i = posicao; i < tamanho - 1; i++)
    {
        vetor[i] = vetor[i + 1]; // O elemento da direita entra na posição atual
    }

    return tamanho - 1; // Retorna o novo tamanho do vetor (um a menos)
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho)
{
    printf("V = { ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("}\n");
}

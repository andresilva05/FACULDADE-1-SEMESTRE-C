// 4. Escreva uma função que insira um valor dado num vetor ordenado de modo que o vetor continue
// ordenado. Por exemplo, se o vetor dado for v = {2, 5, 7, 10, 12, 13} e o valor dado for 6, a função
// deve fornecer o vetor v = {2, 5, 6, 7, 10, 12, 13}.

#include <stdio.h>
#define TAM 6

void preencherVetor(int vetor[]);

int main()
{
    int vetor[TAM + 1]; // Cria vetor com espaço extra para inserir novo valor
    int numeroUsuario;

    preencherVetor(vetor);

    printf("Digite um valor:\n");
    scanf("%d", &numeroUsuario);

    insereValorNaPosicao(vetor, numeroUsuario);
}

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
void insereValorNaPosicao(int vetor[], int valor)
{
    int i, posicao = TAM;

    for (i = 0; i < TAM; i++)
    {
        if (vetor[i] >= valor)
        {
            posicao = i;
            break;
        }
    }
    for (i = TAM; i > posicao; i--)
    {
        vetor[i] = vetor[i - 1]; // Copia o elemento anterior para a posição atual
    }

    vetor[posicao] = valor;

    // Exibe o vetor resultante após a inserção
    printf("V = {");
    for (i = 0; i <= TAM; i++) // Imprime todos os elementos, incluindo o novo (TAM+1 elementos)
    {
        printf("%d ", vetor[i]);
    }
    printf("}\n");
}
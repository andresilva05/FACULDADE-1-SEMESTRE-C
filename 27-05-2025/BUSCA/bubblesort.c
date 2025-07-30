#include <stdio.h> // Biblioteca padrão de entrada e saída
#define TAM 10     // Definindo uma constante TAM com valor 10, que representa o tamanho do vetor

// Declaração das funções
void imprimirVetor(int vetor[]);
void BubbleSort(int numeros[]);

int main()
{
    // Declaração e inicialização do vetor com 10 números
    int numeros[TAM] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    // Mostra o vetor antes da ordenação
    printf("Vetor antes da ordenacao:\n");
    imprimirVetor(numeros);

    // Chamada da função que ordena o vetor
    BubbleSort(numeros);

    // Mostra o vetor depois da ordenação
    printf("\nVetor depois da ordenacao:\n");
    imprimirVetor(numeros);

    return 0; // Fim do programa
}

// Função que implementa o método Bubble Sort
void BubbleSort(int numeros[])
{
    int i, continua, aux;

    do
    {
        continua = 0; // Variável para verificar se houve troca

        // Percorre o vetor até o penúltimo elemento
        for (i = 0; i < TAM - 1; i++)
        {
            // Compara elementos vizinhos
            if (numeros[i] > numeros[i + 1])
            {
                // Se estão fora de ordem, faz a troca
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;

                // Marca que houve troca e precisa repetir o processo
                continua = 1;
            }
        }
        // Continua o laço enquanto houver troca
    } while (continua);
}

// Função para imprimir os elementos do vetor
void imprimirVetor(int vetor[])
{
    int i;
    printf("\nDados armazenados no vetor:\n[ ");

    // Percorre o vetor e imprime cada elemento
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n"); // Fecha a impressão do vetor
}

// 🔥 O que esse código faz?
// Cria um vetor com 10 números inteiros desordenados.

// Imprime esse vetor antes da ordenação.

// Ordena os números em ordem crescente usando o algoritmo Bubble Sort (ordenação por bolha).

// Imprime novamente o vetor, agora ordenado.
#include <stdio.h> // Biblioteca padrão de entrada e saída
#define TAM 10     // Define uma constante TAM com valor 10, que é o tamanho do vetor

// Declaração das funções
void imprimirVetor(int vetor[]);
void SelectionSort(int numeros[]);

int main()
{
    // Declaração e inicialização do vetor
    int numeros[TAM] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    // Mostra o vetor antes da ordenação
    printf("Vetor antes da ordenacao");
    imprimirVetor(numeros);

    // Chama a função que ordena o vetor
    SelectionSort(numeros);

    // Mostra o vetor depois da ordenação
    printf("\nVetor depois da ordenacao");
    imprimirVetor(numeros);

    return 0; // Fim do programa
}

// Função para imprimir os elementos do vetor
void imprimirVetor(int vetor[])
{
    int i;
    printf("\nDados armazenados no vetor:\n[ ");
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

// Função que faz a ordenação por seleção (Selection Sort)
void SelectionSort(int numeros[])
{
    int i, j, posMenor, aux;

    // Percorre cada posição do vetor, menos a última
    for (i = 0; i < TAM - 1; i++)
    {
        posMenor = i; // Assume que o menor valor está na posição atual

        // Busca o menor elemento no restante do vetor
        for (j = i + 1; j < TAM; j++)
        {
            if (numeros[j] < numeros[posMenor])
            {
                posMenor = j; // Atualiza a posição do menor elemento encontrado
            }
        }

        // Se encontrou um elemento menor, faz a troca
        if (i != posMenor)
        {
            aux = numeros[i];
            numeros[i] = numeros[posMenor];
            numeros[posMenor] = aux;
        }
    }
}

// 🧠 Explicação Simples:
// O Selection Sort funciona assim:

// Procura o menor elemento do vetor e coloca na primeira posição.

// Depois procura o segundo menor e coloca na segunda posição.

// Repete isso até o vetor inteiro estar ordenado.

// Funciona como se você estivesse escolhendo sempre o menor número e separando ele do restante.

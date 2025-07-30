#include <stdio.h> // Biblioteca padrão para entrada e saída
#define TAM 10     // Constante que define o tamanho do vetor

// Declaração da função de busca sequencial otimizada para vetor ordenado
int PesqSeq(int numeros[], int x);

// Declaração da função de ordenação Selection Sort
void SelectionSort(int numeros[]);

int main()
{
    // Vetor de números inicial (não necessariamente ordenado)
    int numeros[TAM] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    int buscar, posicao;

    // Pede para o usuário digitar o valor que deseja buscar
    printf("Entre com o valor que deseja buscar: ");
    scanf("%d", &buscar);

    // Ordena o vetor para que a busca otimizada funcione corretamente
    SelectionSort(numeros);

    // Chama a função de busca sequencial otimizada
    posicao = PesqSeq(numeros, buscar);

    // Verifica se o valor foi encontrado e mostra a mensagem apropriada
    if (posicao == -1)
        printf("Valor nao encontrado\n");
    else
        // Adiciona +1 para mostrar a posição "humana" (começa em 1)
        printf("Valor encontrado na posicao %d\n", posicao + 1);

    return 0; // Encerra o programa
}

// Função que ordena o vetor usando Selection Sort
void SelectionSort(int numeros[])
{
    int i, j, posMenor, aux;

    // Percorre o vetor, menos o último elemento
    for (i = 0; i < TAM - 1; i++)
    {
        posMenor = i; // Assume que o menor elemento está na posição i

        // Procura o menor elemento no restante do vetor
        for (j = i + 1; j < TAM; j++)
        {
            if (numeros[j] < numeros[posMenor])
            {
                posMenor = j; // Atualiza a posição do menor elemento
            }
        }

        // Se o menor elemento não está na posição i, troca os elementos
        if (i != posMenor)
        {
            aux = numeros[i];
            numeros[i] = numeros[posMenor];
            numeros[posMenor] = aux;
        }
    }
}

// Função que realiza a busca sequencial otimizada para vetor ordenado
int PesqSeq(int numeros[], int x)
{
    int i = 0, cont = 0;

    // Enquanto não chegou ao final e o valor atual for menor ou igual ao valor buscado
    while (i < TAM && numeros[i] <= x)
    {
        cont++; // Conta quantas posições foram verificadas

        if (numeros[i] == x)
        {
            printf("Foram verificadas %d posicoes para encontrar o valor.\n", cont);
            // Se encontrar o valor, retorna a posição
            return i;
        }

        i++; // Avança para o próximo elemento
    }

    // Se saiu do loop, significa que não encontrou o valor
    printf("Foram verificadas %d posicoes e o valor nao foi encontrado.\n", cont);
    return -1; // Retorna -1 para indicar que não encontrou
}

/*
Explicação Simplificada:

- Primeiro, o vetor é ordenado para garantir que os elementos estejam em ordem crescente.
- A busca sequencial otimizada aproveita essa ordenação:
    - Ela verifica elemento por elemento, do início até encontrar um valor maior que o que buscamos.
    - Isso permite parar a busca mais cedo, economizando tempo.
- Se encontrar o valor buscado, retorna sua posição.
- Se não encontrar, informa quantas posições foram verificadas e retorna -1.
- Essa busca é eficiente porque o vetor está ordenado e não possui elementos repetidos.
*/

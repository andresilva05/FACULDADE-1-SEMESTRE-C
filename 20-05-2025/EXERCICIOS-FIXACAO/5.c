#include <stdio.h>

// Declaração da função que vai procurar a posição do número dentro do vetor
void encontraPosicaoNum(int vetor[], int numero);

// Função para ler os valores do vetor
void lerVetor(int vetor[], int tamanho)
{
    int i;

    printf("INFORME %d NUMEROS INTEIROS:\n\n", tamanho);

    // Laço para preencher o vetor
    for (i = 0; i < tamanho; i++)
    {
        printf("Valor [%d]: ", i); // Mostra em qual posição o valor será armazenado
        scanf("%d", &vetor[i]);    // Lê o valor digitado e guarda no vetor
    }
}

int main()
{
    int i, NUM, VET[10]; // Declara o vetor de 10 posições, a variável NUM e a auxiliar i

    // Chama a função que lê e preenche o vetor
    lerVetor(VET, 10);

    // Solicita o número que será buscado no vetor
    printf("INFORME MAIS UM NUMERO INTEIRO:\n");
    scanf("%d", &NUM);

    // Chama a função que verifica se NUM está no vetor e em qual posição
    encontraPosicaoNum(VET, NUM);

    return 0; // Fim do programa
}

// Função que busca a posição do número dentro do vetor
void encontraPosicaoNum(int vetor[], int numero)
{
    int i, encontrou = -1; // Variável 'encontrou' começa em -1 (significa não encontrado)

    // Percorre o vetor de 0 a 9
    for (i = 0; i < 10; i++)
    {
        if (numero == vetor[i]) // Se o número for igual ao valor na posição 'i'
        {
            encontrou = i; // Guarda a posição onde encontrou
        }
    }

    // Se encontrou diferente de -1, significa que achou o número no vetor
    if (encontrou != -1)
    {
        printf("NUMERO ENCONTRADO NA POSICAO %d\n", encontrou);
    }
    else
    {
        // Se não encontrou (permanece -1), imprime -1
        printf("-1");
    }
}

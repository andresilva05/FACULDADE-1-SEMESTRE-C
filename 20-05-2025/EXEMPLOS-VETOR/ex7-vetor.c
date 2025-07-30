

#include <stdio.h> // Inclusão da biblioteca padrão de entrada e saída

// Protótipos das funções
void preencherVetor(int vetor[]);        // Função para preencher o vetor com dados do usuário
void imprimir_vetor(int vetor[]);        // Função para imprimir os dados do vetor em ordem normal
void imprimirVetor_inverso(int vetor[]); // Função para imprimir os dados do vetor em ordem inversa

int main()
{
    int vetor[5]; // Declaração de um vetor de inteiros com 5 posições

    // Chamada da função para preencher o vetor com entrada do usuário
    preencherVetor(vetor);

    // Chamada da função para imprimir os elementos do vetor em ordem original
    imprimir_vetor(vetor);

    // Chamada da função para imprimir os elementos do vetor em ordem inversa
    imprimirVetor_inverso(vetor);

    return 0; // Fim do programa
}

// Função que recebe o vetor e solicita ao usuário os valores para preenchê-lo
void preencherVetor(int vetor[])
{
    int i;
    for (i = 0; i < 5; i++) // Percorre o vetor do índice 0 ao 4
    {
        printf("\n Valor [%d]: ", i); // Solicita valor ao usuário para a posição atual
        scanf("%d", &vetor[i]);       // Lê o valor digitado e armazena na posição correspondente
    }
}

// Função que imprime os elementos do vetor na ordem em que foram inseridos
void imprimir_vetor(int vetor[])
{
    int i;
    printf("Exibicao dos dados armazenados no conjunto:\n [ ");
    for (i = 0; i < 5; i++) // Percorre o vetor do início ao fim
    {
        printf("%d ", vetor[i]); // Imprime o valor de cada posição
    }
    printf("]\n"); // Fecha o colchete e quebra linha
}

// Função que imprime os elementos do vetor na ordem inversa (último até o primeiro)
void imprimirVetor_inverso(int vetor[])
{
    int i;
    printf("Inverso dos dados armazenados no conjunto:\n [ ");
    for (i = 4; i >= 0; i--) // Começa do último índice e vai até o primeiro
    {
        printf("%d ", vetor[i]); // Imprime o valor de cada posição em ordem inversa
    }
    printf("]\n"); // Fecha o colchete e quebra linha
}

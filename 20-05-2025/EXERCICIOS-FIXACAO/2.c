// 2. Dado um vetor B definido como int B[10], preenchê-lo com os números inteiros 10,9,8,…,1

#include <stdio.h> // Inclusão da biblioteca padrão para entrada e saída de dados

// Protótipos das funções
void imprimirVetor_inverso(int vetor[]); // Função para imprimir os elementos do vetor em ordem inversa

int main()
{
    int B[10]; // Declaração de um vetor de 5 inteiros

    B[0] = 1;
    B[1] = 2;
    B[2] = 3;
    B[3] = 4;
    B[4] = 5;
    B[5] = 6;
    B[6] = 7;
    B[7] = 8;
    B[8] = 9;
    B[9] = 10;
    // Exibição dos elementos do vetor na ordem inversa
    imprimirVetor_inverso(B);

    return 0; // Finaliza o programa com sucesso
}

// Função que imprime os elementos do vetor em ordem inversa (do último para o primeiro)
void imprimirVetor_inverso(int vetor[])
{
    int i;

    printf("Inverso dos dados armazenados no conjunto:\n [ ");
    for (i = 9; i >= 0; i--) // Laço começa do índice 4 e vai até 0
    {
        printf("%d ", vetor[i]); // Imprime o valor da posição i
    }
    printf("]\n"); // Fecha o colchete e adiciona uma quebra de linha
}

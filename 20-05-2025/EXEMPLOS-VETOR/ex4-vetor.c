#include <stdio.h> // Inclusão da biblioteca padrão de entrada e saída

// Protótipo da função que imprime os valores do vetor
void imprimir_vetor(int vetor[]);

int main()
{
    int vetor[5]; // Declaração de um vetor de 5 inteiros
    int i;        // Variável auxiliar para controle do índice

    // Usuário preenche o vetor com 5 valores
    for (i = 0; i < 5; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita o valor para a posição i
        scanf("%d", &vetor[i]);       // Lê o valor digitado e armazena no vetor
    }

    // Chamada da função para exibir os valores armazenados
    imprimir_vetor(vetor);

    return 0; // Fim do programa
}

// Função que recebe um vetor como parâmetro e imprime seus valores
void imprimir_vetor(int vetor[])
{
    int i;
    printf("Exibicao dos dados armazenados no conjunto:\n [ ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]); // Imprime os elementos do vetor
    }
    printf("]\n"); // Fecha a exibição
}

// ⚠️ Abaixo está uma duplicata da função imprimir_vetor, o que causará erro de compilação
// Em C, não é permitido declarar a mesma função duas vezes

void imprimir_vetor(int vetor[])
{
    int i;
    printf("Exibicao dos dados armazenados no conjunto:\n [ ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

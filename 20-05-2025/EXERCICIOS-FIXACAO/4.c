// 4. Fazer um programa para ler 20 números, calcular a média dos mesmos e exibir os números que
// estiverem acima da média.

#include <stdio.h>

float calculaMedia(int vetor[]);
void exibeNumAcimaMedia(int vetor[]);

int main()
{
    int numero[20]; // Declaração de um vetor de 20 inteiros
    int i;          // Variável auxiliar usada como índice

    // Preenchimento do vetor com valores informados pelo usuário
    for (i = 0; i < 20; i++)
    {
        printf("\n Valor [%d]: ", i); // Solicita valor para a posição 'i'
        scanf("%d", &numero[i]);      // Lê e armazena o valor digitado no vetor
    }

    exibeNumAcimaMedia(numero);

    return 0; // Finaliza o programa com sucesso
}

// Função que imprime os elementos do vetor na ordem em que foram inseridos
float calculaMedia(int vetor[])
{

    int soma = 0;
    float media;
    int i;

    for (i = 0; i < 20; i++)
    {
        soma = soma + vetor[i];
    }

    media = soma / 20.0;

    printf("Media: %.2f\n", media);

    return media;
}

void exibeNumAcimaMedia(int vetor[])
{
    int i;
    float media;

    media = calculaMedia(vetor);

    for (i = 0; i < 20; i++)
    {
        if (vetor[i] > media)
        {
            printf("%d Acima da media\n", vetor[i]);
        }
        else
        {
            printf("%d Abaixo da media\n", vetor[i]);
        }
    }
}
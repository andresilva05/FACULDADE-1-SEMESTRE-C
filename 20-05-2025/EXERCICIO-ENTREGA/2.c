// 2. A amplitude de uma relação de números reais é a diferença entre o maior e o menor valor da
// relação. Por exemplo, a amplitude da relação 5, 7, 15, 2, 23 21, 3, 6 é 21 (porque 23 – 2 = 21).
// Escreva um programa que receba um conjunto de 6 números e forneça sua amplitude.

#include <stdio.h> // Biblioteca padrão de entrada e saída

#define TAM 6 // Definindo o tamanho do vetor como constante (boa prática)

// ============================
// Protótipos das funções
// ============================
void preencherVetor(int vetor[]);       // Função que preenche o vetor com valores informados pelo usuário
int forneceAmplitude(int vetor[]);      // Função que calcula e retorna a amplitude do vetor

// ============================
// Função principal
// ============================
int main()
{
    int vetor[TAM];     // Declaração do vetor com tamanho 6
    int amplitude;      // Variável para armazenar o valor da amplitude

    preencherVetor(vetor);  // Chama a função para preencher o vetor

    amplitude = forneceAmplitude(vetor); // Chama a função para calcular a amplitude

    // Exibe o resultado da amplitude
    printf("\nAmplitude = %d\n", amplitude);

    return 0; // Encerra o programa
}

// ============================
// Função para preencher o vetor
// ============================
void preencherVetor(int vetor[])
{
    int i;
    for (i = 0; i < TAM; i++) // Loop que percorre do índice 0 até TAM-1
    {
        printf("\nValor [%d]: ", i); // Solicita o valor para o índice atual
        scanf("%d", &vetor[i]);       // Lê e armazena o valor na posição i do vetor
    }
}

// ============================
// Função que calcula a amplitude
// ============================
int forneceAmplitude(int vetor[])
{
    // Inicializa as variáveis 'maior' e 'menor' com o primeiro valor do vetor
    int i, maior = vetor[0], menor = vetor[0];

    // Percorre o vetor a partir do segundo elemento (índice 1)
    for (i = 1; i < TAM; i++)
    {
        // Verifica se o elemento atual é maior que o maior registrado até agora
        if (vetor[i] > maior)
        {
            maior = vetor[i]; // Atualiza o maior valor
        }
        // Verifica se o elemento atual é menor que o menor registrado até agora
        else if (vetor[i] < menor)
        {
            menor = vetor[i]; // Atualiza o menor valor
        }
    }

    // Retorna a diferença entre o maior e o menor valor (amplitude)
    return maior - menor;
}
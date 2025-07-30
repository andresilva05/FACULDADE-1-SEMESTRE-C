

#include <stdio.h> // Biblioteca padrão de entrada e saída
#define TAM 10     // Define uma constante TAM com valor 10, que é o tamanho do vetor

// Declaração da função de busca binária
int PesqBin(int numeros[], int x);

int main()
{
    // Declaração e inicialização do vetor (IMPORTANTE: o vetor precisa estar ordenado para busca binária)
    int numeros[TAM] = {14, 18, 27, 32, 37, 60, 64, 70, 90, 95};

    int buscar, posicao;

    // Pede para o usuário informar o número que deseja buscar
    printf("Entre com o valor que deseja buscar: ");
    scanf("%d", &buscar);

    // Chama a função de busca binária e guarda a posição onde encontrou (ou -1 se não encontrou)
    posicao = PesqBin(numeros, buscar);

    // Verifica se encontrou ou não e exibe a mensagem correspondente
    if (posicao == -1)
        printf("Valor nao encontrado\n");
    else
        printf("Valor encontrado na posicao %d\n", posicao + 1); // soma 1 para mostrar posição começando em 1 (não em 0)

    return 0; // Fim do programa
}

// Função que faz a busca binária
int PesqBin(int numeros[], int x)
{
    int ini = 0, descartados; // Início da busca (primeira posição)
    int fim = TAM - 1;        // Fim da busca (última posição) — Correção: deve ser TAM - 1
    int meio;                 // Posição do meio

    // Enquanto ainda existir intervalo para buscar
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;

        if (numeros[meio] == x)
            return meio;

        if (numeros[meio] < x)
        {
            descartados = meio - ini + 1;
            printf("Descartados %d elementos da parte esquerda\n", descartados);
            ini = meio + 1;
        }
        else
        {
            descartados = fim - meio + 1;
            printf("Descartados %d elementos da direita\n", descartados);
            fim = meio - 1;
        }
    }

    return -1; // Não encontrou, retorna -1
}

// 🚀 Resumo Simples do Funcionamento:
// Divide o vetor ao meio.

// Compara o valor do meio com o que você está procurando.

// Se for igual, achou.

// Se for menor, busca na metade da direita.

// Se for maior, busca na metade da esquerda.

// Repete até achar ou não ter mais onde procurar.
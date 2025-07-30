#include <stdio.h> // Biblioteca padrão de entrada e saída
#define TAM 10     // Define uma constante TAM com valor 10, que é o tamanho do vetor

// Declaração da função de busca sequencial
int PesqSeq(int numeros[], int x);

int main()
{
    // Declaração e inicialização do vetor (não precisa estar ordenado para busca sequencial)
    int numeros[TAM] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};

    int buscar, posicao;

    // Solicita ao usuário o valor que deseja buscar
    printf("Entre com o valor que deseja buscar: ");
    scanf("%d", &buscar);

    // Chama a função de busca sequencial
    posicao = PesqSeq(numeros, buscar);

    // Verifica se encontrou ou não e exibe a mensagem correspondente
    if (posicao == -1)
        printf("Valor nao encontrado");
    else
        printf("Valor encontrado na posicao %d", posicao + 1); // +1 para exibir começando de 1 (posição humana)

    return 0; // Fim do programa
}

// Função que realiza a busca sequencial
int PesqSeq(int numeros[], int x)
{
    int i = 0;

    // Percorre o vetor enquanto não encontra o elemento e não chega no final
    while ((numeros[i] != x) && (i < TAM))
        i = i + 1; // Avança uma posição no vetor

    // Se achou (i menor que TAM), retorna a posição
    if (i < TAM)
        return i;
    else
        return -1; // Se não achou, retorna -1
}

// 🧠 Explicação Simplificada:
// A busca sequencial vai olhando um elemento de cada vez, da primeira posição até a última.

// Se encontra o valor, retorna a posição.

// Se chega no final sem achar, retorna -1 (não encontrado).

// Esse tipo de busca funciona com qualquer vetor, não precisa estar ordenado.
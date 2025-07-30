// 9. Escreva um programa que leia a idade e o primeiro nome de N pessoas. Seu programa deve terminar
// quando uma idade negativa for digitada. Ao terminar, seu programa deve escrever o nome e a idade das
// pessoas mais jovens e mais velhas.
// Entrada
// A entrada consiste em vários casos de teste e é terminada pela digitação do valor -1 na idade. Cada
// caso de teste contém um valor numérico inteiro para a idade e um valor string para o primeiro nome
// da pessoa.
// Saída
// Exiba duas linhas, uma contendo o primeiro nome e o valor da idade da pessoa mais jovem e a
// outra contendo o primeiro nome e o valor da idade da pessoa mais velha.
// Exemplo
// 20, marcos
// 24, maria
// 15, ana
// 33, beatriz
// -1
// ana é a mais jovem com 15 anos
// beatriz é a mais velha com 33 anos

#include <stdio.h>
#include <string.h>

#define TAM 50          // Tamanho máximo para cada nome
#define MAX_PESSOAS 100 // Quantidade máxima de pessoas que o programa pode armazenar

// Funções auxiliares que recebem nomes, idades e a quantidade de pessoas lidas
void encontraMenorIdade(char nome[][TAM], int idade[], int qtdPessoas);
void encontraMaiorIdade(char nome[][TAM], int idade[], int qtdPessoas);

int main()
{
    int idades[MAX_PESSOAS];      // Vetor para armazenar idades
    char nomes[MAX_PESSOAS][TAM]; // Vetor para armazenar os nomes
    int i = 0, qtdPessoas = 0;    // Contadores

    // Laço principal de leitura
    while (1)
    {
        printf("Digite a idade: ");
        scanf("%d", &idades[i]);

        // Encerra se a idade for negativa
        if (idades[i] < 0)
        {
            break;
        }

        printf("Digite o primeiro nome: ");
        scanf("%s", nomes[i]); // Lê o nome (sem espaços)

        i++;          // Passa para o próximo índice
        qtdPessoas++; // Conta uma nova pessoa
    }

    // Chama funções para identificar a mais jovem e a mais velha
    encontraMenorIdade(nomes, idades, qtdPessoas);
    encontraMaiorIdade(nomes, idades, qtdPessoas);
}

// Função que encontra a pessoa mais jovem
void encontraMenorIdade(char nome[][TAM], int idade[], int qtdPessoas)
{
    int menorIdade = 100; // Inicializa com valor alto
    int i;
    char pessoaMaisNova[TAM]; // Guarda o nome da pessoa mais nova

    for (i = 0; i < qtdPessoas; i++)
    {
        if (idade[i] < menorIdade)
        {
            menorIdade = idade[i];           // Atualiza a menor idade
            strcpy(pessoaMaisNova, nome[i]); // Copia o nome correspondente
        }
    }

    printf("%s eh o(a) mais jovem com %d anos.\n\n", pessoaMaisNova, menorIdade);
}

// Função que encontra a pessoa mais velha
void encontraMaiorIdade(char nome[][TAM], int idade[], int qtdPessoas)
{
    int maiorIdade = -1; // Inicializa com valor muito baixo
    int i;
    char pessoaMaisVelha[TAM]; // Guarda o nome da pessoa mais velha

    for (i = 0; i < qtdPessoas; i++)
    {
        if (idade[i] > maiorIdade)
        {
            maiorIdade = idade[i];            // Atualiza a maior idade
            strcpy(pessoaMaisVelha, nome[i]); // Copia o nome correspondente
        }
    }

    printf("%s eh o(a) mais velho com %d anos.\n\n", pessoaMaisVelha, maiorIdade);
}

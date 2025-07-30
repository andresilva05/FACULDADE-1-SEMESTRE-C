// 3. Faça um programa que leia um nome e indique se a primeira letra é ‘c’ (maiúscula ou minúscula).
// Entrada
// A entrada consiste em uma variável (nome), declarada como tipo de dados string.
// Saída
// Exiba a mensagem “Inicia com c ou C” ou “não inicia”, de acordo com seu teste

#include <stdio.h>  // Biblioteca para funções de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings (não usada nesse código, mas incluída)

/* Função que verifica se a primeira letra da string 'nome' é 'c' ou 'C' */
void verificaPrimeiraLetraC(char nome[]);

int main()
{
    int sair = 1;  // Variável para controlar o loop (continuar ou sair)
    char nome[15]; // Vetor de caracteres para armazenar o nome digitado

    do
    {
        printf("Digite um nome: \n");
        scanf("%s", nome); // Lê uma palavra (nome) do usuário

        verificaPrimeiraLetraC(nome); // Chama a função para verificar a primeira letra e exibir mensagem

        // Pergunta ao usuário se deseja continuar ou sair do programa
        printf("\n1 para continuar programa\n0 para sair!\n");
        scanf("%d", &sair);

    } while (sair != 0); // Repete o loop enquanto o usuário não digitar 0

    printf("Encerrando programa!"); // Mensagem final antes de encerrar
    return 0;
}

/* Função que recebe uma string e verifica a primeira letra */
void verificaPrimeiraLetraC(char nome[])
{
    // Verifica se o primeiro caractere é 'c' ou 'C'
    if (nome[0] == 'c' || nome[0] == 'C')
    {
        printf("\nInicia com c ou C\n"); // Mensagem se iniciar com 'c' ou 'C'
    }
    else
    {
        printf("\nNao inicia\n"); // Mensagem se não iniciar com 'c' ou 'C'
    }
}

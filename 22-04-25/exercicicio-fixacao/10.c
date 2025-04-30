// Exercício 10. Crie um programa para simular o jogo “Par ou Ímpar”, usando a Linguagem C. A cada
// rodada, o jogador digita um número inteiro, no intervalo de 0 a 5, e escolhe uma das seguintes
// opções:
//  Par
//  Ímpar
// O jogo lê o número e a opção do jogador. O jogo verifica se o número é válido (dentro do intervalo
// de 0 a 10) e não dá sequência se for inválido. Se o jogador escolheu Par, automaticamente o
// computador (o oponente) deve ficar com a opção Ímpar e vice-versa. O jogo deve gerar um número
// aleatório, também no intervalo de 0 a 10, que será atribuído ao computador. Então, o jogo efetua a
// soma dos números (do jogador e do computador) e determina se o resultado é um número par ou
// ímpar. Vence quem tiver escolhido a opção correta.
// Dica: para gerar o número aleatório, use a função
// int gerarNumeroAleatorio(int min, int max){
// srand((unsigned)time(NULL));
// return min + rand() % max;
// }
// Obs.
// 1. min e max são os valores de limite inferior e superior do intervalo
// 2. acrescente as bibliotecas stdlib.h e time.h, para usar as funções
// srand(), rand() e time().

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções
int gerarNumeroAleatorio(int min, int max);
int somaNumeros(int a, int b);
void verificaVencedor(int resultSoma, char escolhaUsuario);

// Função que obriga o jogador a escolher entre Par (P) ou Ímpar (I)
void escolhaParOuImpar(char *escolha)
{
    do
    {
        printf("Escolha entre (P)ar ou (I)mpar: ");
        scanf(" %c", escolha);
    } while (*escolha != 'P' && *escolha != 'p' && *escolha != 'I' && *escolha != 'i');
}

// Função para ler e validar o número do usuário entre 0 e 10
void digitaNumero(int *numero)
{
    do
    {
        printf("Digite um numero de 0 a 10:\n");
        scanf("%d", numero);
    } while (*numero < 0 || *numero > 10);
}

int main()
{
    int soma, resultadoMaquina, numUsuario, encerra = 1;
    char escolhaUsuario;

    printf("Seja bem vindo ao jogo!\n\n");

    do
    {
        // Usuário escolhe Par ou Ímpar
        escolhaParOuImpar(&escolhaUsuario);

        // Usuário digita número de 0 a 10
        digitaNumero(&numUsuario);

        // Gera número aleatório de 0 a 10 para a máquina
        resultadoMaquina = gerarNumeroAleatorio(0, 10);

        printf("%d foi o numero da maquina\n", resultadoMaquina);

        // Soma os dois números
        soma = somaNumeros(numUsuario, resultadoMaquina);

        // Verifica e exibe quem venceu com base na soma e escolha do jogador
        verificaVencedor(soma, escolhaUsuario);

        // Pergunta se o usuário deseja continuar jogando
        printf("Digite 1 para continuar e 0 para encerrar programa!\n");
        scanf("%d", &encerra);

    } while (encerra != 0); // Repete enquanto o usuário desejar

    printf("Obrigado por participar!");
}

// Função que gera número aleatório dentro do intervalo definido
int gerarNumeroAleatorio(int min, int max)
{
    srand((unsigned)time(NULL)); // Semente aleatória baseada no horário
    return min + rand() % (max - min + 1);
}

// Função que retorna a soma de dois inteiros
int somaNumeros(int a, int b)
{
    return a + b;
}

// Função que verifica se a soma é par ou ímpar e define o vencedor com base na escolha do jogador
void verificaVencedor(int resultSoma, char escolhaUsuario)
{
    // Exibe se o resultado foi par ou ímpar
    if (resultSoma % 2 == 0)
    {
        printf("Resultado eh par\n");
    }
    else
    {
        printf("Resultado eh impar\n");
    }

    // Verifica quem venceu de acordo com a escolha e o resultado
    if (escolhaUsuario == 'P' || escolhaUsuario == 'p')
    {
        if (resultSoma % 2 == 0)
        {
            printf("Voce venceu!\n\n");
        }
        else
        {
            printf("Maquina Venceu!\n\n");
        }
    }
    if (escolhaUsuario == 'I' || escolhaUsuario == 'i')
    {
        if (resultSoma % 2 == 1)
        {
            printf("Voce venceu!\n\n");
        }
        else
        {
            printf("Maquina Venceu!\n\n");
        }
    }
}

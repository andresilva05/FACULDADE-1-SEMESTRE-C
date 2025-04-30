// Exercício 2. Escreva um programa que simule as operações de um caixa eletrônico através
// de transações, que podem ser:
// Retirada de dinheiro (código de transação = 1);
// Depósito de dinheiro (código de transação = 2);
// Verificação de saldo (código de transação = 3).
// Considere que o banco terá somente 1 cliente e que suas informações, como saldo e limite
// da conta devem ser informados na criação dessas variáveis.
// O programa deve conter funcionalidades para validar a transação de retirada, de acordo
// com o saldo e o limite da conta.

#include <stdio.h>

int main()
{
    int codigoTransacao; // Armazena o código da operação escolhida

    // Saldo inicial e limite da conta definidos na criação das variáveis
    float saldo = 1000.0, limite = 500.0;
    float valorRetirado, valorDeposito, saldoAtual;

    // Menu de opções apresentado ao usuário
    printf("Ola cliente, seja bem-vindo!\n");
    printf("Digite o codigo da transacao desejada:\n");
    printf("1 - Retirada de dinheiro\n2 - Deposito de dinheiro\n3 - Verificacao de saldo\n");

    // Garante que o usuário digite um código válido (1, 2 ou 3)
    do
    {
        printf("Digite o codigo de transacao conforme orientacao acima: \n");
        scanf("%d", &codigoTransacao);
    } while (codigoTransacao != 1 && codigoTransacao != 2 && codigoTransacao != 3);

    // Transação de retirada
    if (codigoTransacao == 1)
    {
        do
        {
            printf("Qual o valor voce deseja retirar?\n");
            scanf("%f", &valorRetirado);

            // Verifica se o valor está dentro do saldo + limite
            if (valorRetirado > saldo + limite)
            {
                printf("Valor nao disponivel. Total que voce tem em conta eh: R$%.2f\n", saldo + limite);
            }

        } while (valorRetirado > saldo + limite);

        // Calcula o novo saldo disponível após a retirada
        saldoAtual = (saldo + limite) - valorRetirado;

        printf("Seu saldo atual com o valor retirado de R$%.2f, eh: R$%.2f\n", valorRetirado, saldoAtual);
    }

    // Transação de depósito
    if (codigoTransacao == 2)
    {
        printf("Qual o valor voce deseja depositar?\n");
        scanf("%f", &valorDeposito);

        // Soma o depósito ao saldo atual (saldo + limite)
        saldoAtual = saldo + limite + valorDeposito;
        printf("Seu saldo atual com o valor depositado de R$%.2f, eh: R$%.2f\n", valorDeposito, saldoAtual);
    }

    // Verificação de saldo
    if (codigoTransacao == 3)
    {
        printf("O valor do seu saldo disponivel (saldo + limite) eh: R$%.2f\n", saldo + limite);
    }

    // Mensagem final de agradecimento
    printf("\nTransacao concluida. Obrigado por usar nosso caixa!\n");

    return 0;
}

// Observação:
// Neste exercício, optei por utilizar o valor disponível total (saldo + limite)
// para validar a retirada, conforme o que geralmente acontece em caixas eletrônicos,
// onde o banco permite que o cliente use o limite como complemento do saldo.
//
// Porém, em um sistema mais completo, poderia ser interessante separar o saldo real
// do limite do cheque especial, controlando o quanto foi usado, quanto ainda está
// disponível e, em alguns casos, até calcular juros sobre o uso do limite.
//
// Para o objetivo do exercício, a abordagem adotada é suficiente e cumpre o que foi solicitado.
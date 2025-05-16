// (2,5 pontos) Senha Fixa. (https://judge.beecrowd.com/pt/problems/view/1114) Escreva um programa que repita
// a leitura de uma senha até que ela seja válida. Para cada leitura de senha incorreta informada,
// escrever a mensagem “Senha Invalida”. Quando a senha for informada corretamente deve ser
// impressa a mensagem “Acesso Permitido” e o algoritmo encerrado. Considere que a senha correta é
// o valor 2025.
// Entrada
// A entrada é composta por vários casos de testes contendo valores inteiros.
// Saída
// Para cada valor lido mostre a mensagem correspondente à descrição do problema.
// Exemplo de Entrada Exemplo de Saída
// 2200
// 1020
// 2022
// 2025
// Senha Invalida
// Senha Invalida
// Senha Invalida
// Acesso Permitido

// Inclui a biblioteca padrão de entrada e saída (necessária para printf e scanf)
#include <stdio.h>

int main()
{
    // Declara e inicializa a variável 'senha' com o valor correto (2025)
    // Declara a variável 'respostaUsuario' que vai guardar o valor digitado pelo usuário
    int senha = 2025, respostaUsuario;

    // Estrutura de repetição que continua enquanto a senha digitada estiver incorreta
    do
    {
        // Solicita ao usuário que digite a senha
        printf("Digite a senha para acessar seu banco!\n");
        scanf("%d", &respostaUsuario); // Lê o valor digitado e armazena em 'respostaUsuario'

        // Verifica se a senha digitada é diferente da senha correta
        if (respostaUsuario != senha)
        {
            // Se a senha estiver errada, exibe uma mensagem de erro
            printf("Senha Invalida\n");
        }

    } while (respostaUsuario != senha); // Repete até que a senha correta seja digitada

    // Exibe mensagem de sucesso quando a senha correta for digitada
    printf("Acesso permitido\n");

    return 0; // Indica que o programa terminou com sucesso
}

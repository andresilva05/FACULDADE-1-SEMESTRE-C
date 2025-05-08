// 3. Biblioteca de Funções Matemáticas: Crie uma biblioteca "matematica_avancada" com funções
// para calcular a potência de um número, encontrar o fatorial de um número e verificar se um número
// é primo.
#include <stdio.h>

#include "matematica_avancada.c" // Inclui a biblioteca de funções matemáticas

int main()
{
    int escolhaUsuario, continuar, expoente, numero; // Variáveis para armazenar a escolha do usuário, controle de repetição, expoente e número
    float base;                                      // Variável para armazenar a base da potência

    do
    {
        // Loop interno para garantir que a escolha do usuário seja válida
        do
        {
            escolhaUsuario = escolhaCalculo();            // Chama a função para exibir as opções e retorna a escolha do usuário
            if (escolhaUsuario < 1 || escolhaUsuario > 3) // Verifica se a escolha está dentro do intervalo válido
            {
                printf("Opcao invalida! Tente novamente.\n\n"); // Caso contrário, avisa o usuário e pede para tentar novamente
            }
        } while (escolhaUsuario < 1 || escolhaUsuario > 3); // Continua pedindo até que a escolha seja válida

        // Switch para decidir qual cálculo o usuário quer realizar
        switch (escolhaUsuario)
        {
        case 1:                                                  // Caso 1: Calcula Potência de um número
            printf("Digite a base da potência e o expoente:\n"); // Pede ao usuário para digitar a base e o expoente
            scanf("%f %d", &base, &expoente);                    // Lê os valores da base (float) e expoente (int)

            printf("A potencia de %.2f eh: %.2f\n", base, PotenciaDeN(base, expoente)); // Chama a função PotenciaDeN e exibe o resultado formatado

            break;

        case 2:                            // Caso 2: Calcula Fatorial de um número
            printf("Digite um numero:\n"); // Pede ao usuário para digitar um número
            scanf("%d", &numero);          // Lê o número digitado (int)

            printf("O fatorial de %d eh: %d\n", numero, FatorialDeN(numero)); // Chama a função FatorialDeN e exibe o resultado formatado
            break;

        case 3:                                    // Caso 3: Verifica se o número é primo
            printf("Digite um numero inteiro:\n"); // Pede ao usuário para digitar um número inteiro
            scanf("%d", &numero);                  // Lê o número digitado (int)

            // Chama a função NumeroPrimo e imprime se o número é primo ou não
            if (NumeroPrimo(numero))
            {
                printf("Numero eh primo.\n"); // Caso a função retorne 1, o número é primo
            }
            else
            {
                printf("Numero nao eh primo.\n"); // Caso a função retorne 0, o número não é primo
            }
            break;
        }

        // Pergunta se o usuário deseja fazer outra operação
        printf("Deseja fazer outra conversao? (1 para sim, 0 para nao)!\n");
        scanf("%d", &continuar); // Lê a escolha do usuário para continuar ou encerrar o programa
    } while (continuar == 1); // Repete o processo enquanto o usuário responder '1' (sim)

    // Mensagem final quando o programa é encerrado
    printf("Obrigado por usar o calculo!\n");
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}
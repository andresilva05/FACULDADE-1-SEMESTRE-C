// Exercício 3. O cardápio de uma lanchonete é mostrado abaixo.Faça um programa que leia
//     o pedido do cliente,
//     calcule e exiba o valor da sua conta.Caso o cliente peça para exibir o
//         valor da conta dividido,
//     pergunte por quantas pessoas e exiba o valor correspondente.Lanches Preço
//             X -
//         Salada 20,
//     0 X - Burguer 25, 00 Hot dog 15, 00 Batata frita 15, 00 Refrigerante(lata) 8, 00

#include <stdio.h>
#include <string.h>

int main()
{

    float Xsalada = 20.0;
    float xburguer = 25.0;
    float hotDog = 15.0;
    float batataFrita = 15.0;
    float refri = 8.0;
    float totalConta, valueDividida;
    char contaDividida;

    int qtdXsalada, qtdXburguer, qtdHotdog, qtdBatata, qtdRefri, qtdPessoasDividida;
    printf("Digite a quantidade de X-Salada adquiridos: \n");
    scanf("%d", &qtdXsalada);
    printf("Digite a quantidade de X-Burguer adquiridos: \n");
    scanf("%d", &qtdXburguer);
    printf("Digite a quantidade de Hot-Dog adquiridos: \n");
    scanf("%d", &qtdHotdog);
    printf("Digite a quantidade de Batata Frita adquiridos: \n");
    scanf("%d", &qtdBatata);
    printf("Digite a quantidade de Refrigerantes adquiridos: \n");
    scanf("%d", &qtdRefri);

    totalConta = (qtdBatata * batataFrita) + (qtdHotdog * hotDog) + (qtdRefri * refri) + (qtdXburguer * xburguer) + (qtdXsalada * Xsalada);

    printf("O valor total da conta foi: R$%.2f\n", totalConta);

    printf("Voce gostaria de dividir a conta? Resposta: (S) ou (N) \n");
    scanf(" %c", &contaDividida);

    if (contaDividida == 'S' || contaDividida == 's')
    {
        printf("Digite para quantas pessoas quer que seja dividido o valor:");
        scanf("%d", &qtdPessoasDividida);

        valueDividida = totalConta / qtdPessoasDividida;

        printf("O valor da conta dividido para %d sera de: R$%.2f\n\n", qtdPessoasDividida, valueDividida);
    }

    printf("Muito obrigado pela preferencia! Volte sempre!");
    return 0;
}
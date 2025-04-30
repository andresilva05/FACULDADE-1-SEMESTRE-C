// Exercício 5. Escreva um programa que converta um valor em reais ou em dólares, de acordo com a
// escolha do usuário. O valor da cotação do dólar deve ser indicado em uma constante. Escreva duas
// funções, uma para converter de real para dólar e outra para converter de dólar para real.

#include <stdio.h>

#define COTACAO_DOLAR 5.71 // Definindo a cotação do dólar como constante

float RealToDolar(float real);
float DolarToReal(float dolar);

int main()
{
    int escolhaUsuario;
    float dolar, real;

    printf("Conversao de Real para Dolar (codigo de transacao = 1)\n");
    printf("Conversao de Dolar para Real (codigo de transacao = 2)\n\n");

    do
    {
        printf("Digite o codigo de transacao conforme orientacao acima: \n");
        scanf("%d", &escolhaUsuario);

    } while (escolhaUsuario != 1 && escolhaUsuario != 2);

    if (escolhaUsuario == 1)
    {
        printf("\nDigite o valor em Reais para obter conversao para Dolar:\nR$");
        scanf("%f", &real);

        printf("O valor digitado em dolar eh: USD %.2f ", RealToDolar(real));
    }
    if (escolhaUsuario == 2)
    {
        printf("\nDigite o valor em Dolar para obter conversao para Reais:\nUSD ");
        scanf("%f", &dolar);

        printf("O valor digitado em Real eh: R$ %.2f ", DolarToReal(dolar));
    }

    return 0;
}

float RealToDolar(float real)
{

    return real / COTACAO_DOLAR;
}
float DolarToReal(float dolar)
{

    return dolar * COTACAO_DOLAR;
}
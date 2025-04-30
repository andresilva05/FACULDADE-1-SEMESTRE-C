// Uma loja vende seus produtos no sistema de entrada mais duas prestações, sendo que
// o valor da entrada deve ser igual ou maior do que as prestações. As prestações devem ser iguais.
// Por exemplo:
// ◦ Se o valor da mercadoria for R$ 270,00, e a entrada for de R$ 90,00, as duas prestações
// serão iguais a R$ 90,00;
// ◦ Se o valor da mercadoria for R$ 350,00, a entrada é de R$ 150,00 e as duas prestações
// são iguais a R$ 100,00.
// Escreva um programa que receba o valor da mercadoria e o valor da entrada e forneça o
// valor das duas prestações, de acordo com as regras acima.


#include <stdio.h>

int main()
{
    float valueMercadoria, valueEntrada, valuePrestacao;

    printf("Digite o valor da mercadoria: ");
    scanf("%f", &valueMercadoria);
    printf("Digite o valor da entrada: ");
    scanf("%f", &valueEntrada);

    valuePrestacao = valueMercadoria - valueEntrada;

    printf("O valor das duas prestações é: %.2f", valuePrestacao);
}
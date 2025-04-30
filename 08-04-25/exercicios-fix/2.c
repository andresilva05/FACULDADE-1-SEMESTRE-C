// Exercício 2. Escreva um programa que realize arredondamentos de números utilizando a regra
// usual da matemática: se a parte fracionária for maior do que ou igual a 0,5, o número é arredondado
// para o inteiro imediatamente superior, caso contrário, é arredondado para o inteiro imediatamente
// inferior.
// Observação: para esse exercício considere que o número é informado com uma casa decimal.

#include <stdio.h>

int main()
{
    float num, resultFracao;
    int fracao, resultado;
    printf("Digite um numero com uma casa decimal: ");
    scanf("%f", &num);

    fracao = num;

    resultFracao = num - fracao;

    if (resultFracao >= 0.5)
    {
        resultado = fracao + 1;
        printf("O numero dado arredondado sera: %d", resultado);
    }
    else
    {
        printf("O numero dado arredondado sera: %d", fracao);
    }

    return 0;
}
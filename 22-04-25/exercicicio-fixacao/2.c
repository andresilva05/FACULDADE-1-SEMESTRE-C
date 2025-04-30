// Exercício 2. Escreva uma função que determine o maior múltiplo de um inteiro dado menor do que
// ou igual a um outro inteiro dado. Por exemplo: o maior múltiplo de 7 menor que 50 é 49.
// Assinatura: int MaiorMultiplo(int inteiro, int maior);

#include <stdio.h>

int MaiorMultiplo(int inteiro, int maior);

int main()
{
    int base, limite;

    printf("Digite o numero base (inteiro): ");
    scanf("%d", &base);

    printf("Digite o limite maximo: ");
    scanf("%d", &limite);

    printf("O maior multiplo de %d menor ou igual a %d eh: %d\n", base, limite, MaiorMultiplo(base, limite));

    return 0;
}

int MaiorMultiplo(int inteiro, int maior)
{
    int resultado;

    resultado = (maior / inteiro) * inteiro;

    return resultado;
}
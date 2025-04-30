#include <stdio.h>

int main()
{

    // declaração de variáveis
    int idade, anoNasc, qtdeAnos;
    int anoAtual = 2026; // atribuição de valor durante a declaração da variável
    printf("Digite sua idade: ");
    scanf("%d", &idade); // atribuição de valor a partir do teclado
    printf("Digite o ano de seu nascimento: ");
    scanf("%d", &anoNasc);
    qtdeAnos = anoAtual - anoNasc; // atribuição de valor a partir de cálculo

    printf("\nIdade infromada pelo usuario = %d\n", idade);
    printf("Idade que tera ao final deste ano: %d\n\n ", qtdeAnos);
}
// Exercício 3. Faça um programa que apresente a tabuada de um número qualquer escolhido
// pelo usuário, no formato: numero X 1 = resultado.

#include <stdio.h>
int main()
{
    int numero;
    int i;
    printf("Digite o numero para tabuada: ");
    scanf("%d", &numero);
    for (i = 1; i <= 10; i++)
    {
        printf("\n%d x %2d = %2d", numero, i, (numero * i));
    }
    return 0;
}

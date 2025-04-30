// Exercício 4. Escreva um programa para determinar o maior de três números inteiros informados pelo
// usuário

#include <stdio.h>

int main()
{

    int num1, num2, num3, maior;

    printf("Digite 3 numeros inteiros: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
    {
        printf("O maior numero dado eh: %d\n", num1);
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        printf("O maior numero dado eh: %d\n", num2);
    }
    else
    {
        printf("O maior numero dado eh: %d\n", num3);
    }

    return 0;
}
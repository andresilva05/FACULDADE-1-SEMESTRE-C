#include <stdio.h>
#include "matematico.c"

int main(int argc, char const *argv[])
{
    int num1, num2;

    printf("\n Digite o numero 1: ");
    scanf("%d", &num1);
    printf("\n Digite o numero 2: ");
    scanf("%d", &num2);
    printf("\n A soma = %d", soma(num1, num2));
    printf("\n O produto = %d", multiplica(num1, num1));
    return 0;
}

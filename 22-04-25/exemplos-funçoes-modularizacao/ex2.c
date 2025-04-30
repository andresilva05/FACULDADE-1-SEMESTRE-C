#include <stdio.h>

int maiorInteiro(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}
int main()
{

    // variaveis para armazenar os numeros digitados
    int numero1, numero2;

    // variavel que vai receber o maior dos valores
    int maior;

    // entrada de dados
    printf("Digite o numero 1:\n");
    scanf("%d", &numero1);
    printf("Digite o numero 2:\n");
    scanf("%d", &numero2);

    printf("O maior valor = %d", maiorInteiro(numero1, numero2));

    return 0;
}
#include <stdio.h>

int main()
{

    int numero;
    int i;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    printf("Tabuada do %d:\n", numero);
    for (i = 1; i <= 10; i++)
    {
        printf("\n%d x %2d = %2d", numero, i, (numero * i));
    }

    return 0;
}
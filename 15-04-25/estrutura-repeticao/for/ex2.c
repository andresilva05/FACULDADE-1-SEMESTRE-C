#include <stdio.h>

int main()
{
    printf("Contagem regressiva... ");
    for (int contador = 10; contador >= 1; contador--)
        printf("\n %d", contador);

    return 0;
}
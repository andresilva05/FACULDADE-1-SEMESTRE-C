#include <stdio.h>

#include "data.c"

int main()
{

    Data d;
    printf("Digite uma data (dd mm aaaa): ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    if (verificaData(d))
    {
        printf("Data valida!\n");
    }
    else
    {
        printf("Data invalida!\n");
    }
}
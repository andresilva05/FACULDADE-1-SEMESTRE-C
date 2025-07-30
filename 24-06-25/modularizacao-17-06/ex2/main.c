
#include <stdio.h>

#include "numeroDias.c"

int main()
{
    Data data1, data2;
    int diferenca;

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);

    diferenca = diferencaDias(data1, data2);

    printf("Diferenca de dias: %d\n", diferenca);

    return 0;
}
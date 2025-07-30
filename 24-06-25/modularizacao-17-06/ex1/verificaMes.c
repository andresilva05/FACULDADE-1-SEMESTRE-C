

#include "verificaMes.h"

Data lerData()
{
    Data x;
    printf("Digite o dia: ");
    scanf("%d", &x.dia);
    printf("Digite o mes: ");
    scanf("%d", &x.mes);
    printf("Digite o ano: ");
    scanf("%d", &x.ano);
    return x; // Retorna a data preenchida
}

void imprimirData(Data x)
{
    printf("\nData: %02d/%02d/%04d\n", x.dia, x.mes, x.ano);
}
int verificaMes(Data x)
{
    if (x.mes >= 1 && x.mes <= 12)
        return 1; // mês válido
    else
        return 0; // mês inválido
}

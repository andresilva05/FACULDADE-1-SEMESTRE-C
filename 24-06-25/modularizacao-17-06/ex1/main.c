#include <stdio.h>

#include "verificaMes.c"

int main()
{
    Data data = lerData(); // lê a data do usuário
    imprimirData(data);    // imprime a data

    // verifica o mês e age conforme o resultado
    if (verificaMes(data))
        printf("Mes valido!\n");
    else
        printf("Mes invalido!\n");

    return 0;
}
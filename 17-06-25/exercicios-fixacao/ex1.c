#include <stdio.h>

// Definição da struct Data
typedef struct
{
    int dia, mes, ano;
} Data;

// Função que lê a data do usuário e retorna uma struct Data
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

// Função que imprime a data no formato dd/mm/aaaa
void imprimirData(Data x)
{
    printf("\nData: %02d/%02d/%04d\n", x.dia, x.mes, x.ano);
}

// Função que verifica se o mês é válido e retorna 1 (válido) ou 0 (inválido)
int verificaMes(Data x)
{
    if (x.mes >= 1 && x.mes <= 12)
        return 1; // mês válido
    else
        return 0; // mês inválido
}

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

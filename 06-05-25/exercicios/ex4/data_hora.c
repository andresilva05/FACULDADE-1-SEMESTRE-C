#include "data_hora.h"
#include <stdio.h>

// Função para definir o mês
void define_mes(int mes)
{
    switch (mes)
    {
    case 1:
        printf("janeiro\n");
        break;
    case 2:
        printf("fevereiro\n");
        break;
    case 3:
        printf("marco\n");
        break;
    case 4:
        printf("abril\n");
        break;
    case 5:
        printf("maio\n");
        break;
    case 6:
        printf("junho\n");
        break;
    case 7:
        printf("julho\n");
        break;
    case 8:
        printf("agosto\n");
        break;
    case 9:
        printf("setembro\n");
        break;
    case 10:
        printf("outubro\n");
        break;
    case 11:
        printf("novembro\n");
        break;
    case 12:
        printf("dezembro\n");
        break;
    default:
        printf("mês inválido\n");
    }
}

// Função para calcular o dia da semana
int define_dia_semana(int D, int M, int A)
{
    int F, resto, C, Y;

    // Separar o ano em C (século) e Y (últimos dois dígitos)
    C = A / 100;
    Y = A % 100;

    // Ajustar o mês e o ano para janeiro e fevereiro
    if (M == 1 || M == 2)
    {
        M += 12;
        Y -= 1; // Decrementar o ano para janeiro ou fevereiro
    }

    // Fórmula de Zeller para calcular o dia da semana
    F = D + (13 * (M + 1)) / 5 + Y + Y / 4 + C / 4 - 2 * C;

    // Obter o resto (dia da semana)
    resto = F % 7;

    // Usar switch para imprimir o nome do dia
    switch (resto)
    {
    case 0:
        printf("sabado\n");
        break;
    case 1:
        printf("domingo\n");
        break;
    case 2:
        printf("segunda-feira\n");
        break;
    case 3:
        printf("terça-feira\n");
        break;
    case 4:
        printf("quarta-feira\n");
        break;
    case 5:
        printf("quinta-feira\n");
        break;
    case 6:
        printf("sexta-feira\n");
        break;
    }
}

// Função para verificar se o ano é bissexto
int is_bissexto(int ano)
{
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

// Função para calcular o número de dias até a data fornecida
int dias_ate_data(int D, int M, int A)
{
    int dias_totais = 0;

    // Contar os dias dos anos completos até o ano A
    for (int ano = 1; ano < A; ano++)
    {
        dias_totais += is_bissexto(ano) ? 366 : 365;
    }

    // Contar os dias dos meses completos no ano A até o mês M
    int meses[12] = {31, is_bissexto(A) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int mes = 0; mes < M - 1; mes++)
    {
        dias_totais += meses[mes];
    }

    // Contar os dias do mês M até o dia D
    dias_totais += D;

    return dias_totais;
}

// Função para calcular a diferença em dias entre duas datas
int diferenca_dias(int D1, int M1, int A1, int D2, int M2, int A2)
{
    int dias_1 = dias_ate_data(D1, M1, A1);
    int dias_2 = dias_ate_data(D2, M2, A2);

    return dias_2 - dias_1;
}


// Função para exibir as opções e capturar a escolha do usuário
int opcaoParaUsuario()
{
    int mes, dia, mes_semana, ano, dia1, mes1, ano1, dia2, mes2, ano2, diferenca;
    int opcao;

    // Solicitar ao usuário o mês e exibir o nome do mês automaticamente
    printf("Digite o numero do mes 1 a 12 ");
    scanf("%d", &mes);
    printf("O nome do mes para o numero %d e ", mes);
    define_mes(mes);

    // Solicitar ao usuário uma data e calcular o dia da semana
    printf("\nDigite uma data dia mes ano ");
    scanf("%d %d %d", &dia, &mes_semana, &ano);
    printf("O dia da semana para %d %d %d e ", dia, mes_semana, ano);
    define_dia_semana(dia, mes_semana, ano);

    // Solicitar ao usuário duas datas para calcular a diferença entre elas
    printf("\nDigite a primeira data dia mes ano ");
    scanf("%d %d %d", &dia1, &mes1, &ano1);
    printf("Digite a segunda data dia mes ano ");
    scanf("%d %d %d", &dia2, &mes2, &ano2);

    // Calcular e exibir a diferença entre as duas datas
    diferenca = diferenca_dias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca entre as duas datas e de %d dias\n", diferenca);

    // Perguntar ao usuário se ele quer continuar ou encerrar
    printf("\nDeseja realizar outra operacao 1 Sim 0 Nao ");
    scanf("%d", &opcao);

    return opcao;  // Retornar a escolha do usuário 1 para continuar 0 para encerrar
}

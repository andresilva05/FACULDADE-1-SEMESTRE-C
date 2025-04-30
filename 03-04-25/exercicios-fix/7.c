// Escreva um programa que converta um intervalo de tempo dado em minutos para
// horas, minutos e segundos.
// Por exemplo, se o tempo dado for 145.87 min, o programa deve fornecer 2 h 25 min 52.2 s
// (vale lembrar que o ponto é o separador da parte inteira).

#include <stdio.h>

int main()
{

    int horasInteiras, minutos;
    float segundos, totalHoras, totalMinutos, tempo;

    printf("Digite o tempo em minutos: \n");
    scanf("%f", &tempo);

    totalHoras = tempo / 60;

    horasInteiras = totalHoras;

    totalMinutos = (totalHoras - horasInteiras) * 60;

    minutos = totalMinutos;
    segundos = (totalMinutos - minutos) * 60;

    printf("Seu tempo convertido eh: %dh %d min %2.f s", horasInteiras, minutos, segundos);

    return 0;
}
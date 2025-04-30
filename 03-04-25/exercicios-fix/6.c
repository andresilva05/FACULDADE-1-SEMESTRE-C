// Faça um programa para calcular a quantidade de combustível gasto em uma viagem. O
// programa deve receber a quantidade de km por litro que o automóvel que faz, o tempo gasto e a
// velocidade média durante a viagem.

#include <stdio.h>

int main()
{
    float qtdCombustivel, distancia, kmLitro, tempoEmHoras, tempGasto, velocMedia;

    printf("Informe a quantidade de km por litro que seu automóvel faz: \n");
    scanf("%f", &kmLitro);

    printf("informe o tempo gasto na viagem em minutos: \n");
    scanf("%f", &tempGasto);
    printf("Informe a velocidade média durante a viagem: \n");
    scanf("%f", &velocMedia);

    tempoEmHoras = tempGasto / 60;

    distancia = velocMedia * tempoEmHoras;
    qtdCombustivel = distancia / kmLitro;

    printf("O total de, combustível gasto durante sua viagem foi: %2.f", qtdCombustivel);
    return 0;
}
// Sobre unidades de medida, sabe-se que:
//  1 pé = 12 polegadas
//  1 jarda = 3 pés
//  1 milha = 1760 jardas
//  1 milha = 16093 metros
// Desenvolva um programa que receba uma medida em pés e apresente as conversões para
// polegadas, jardas, milhas e metros.

#include <stdio.h>

int main()
{

    int medida, polegadas, pes, jardas, milhas, metros;

    printf("Digite a medida em pes: \n");
    scanf("%d", &medida);

    polegadas = medida * 12;
    jardas = medida / 3;
    metros = medida / 16093;

    return 0;
}
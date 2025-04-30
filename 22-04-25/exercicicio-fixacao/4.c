// Exercício 4. Escreva um programa que calcule o valor de uma média ponderada, considerando duas
// notas e dois pesos informados pelo usuário. O cálculo da média deve ser feito usando uma função.
// Assinatura: float MediaPonderada( float nota1, float peso1, float nota2, float peso2);

#include <stdio.h>

float MediaPonderada(float nota1, float peso1, float nota2, float peso2);

int main()
{
    int p1, p2;
    float n1, n2;

    printf("Digite duas notas e seus respectivos pesos (nota 1, peso 1, nota 2, peso 2): \n");
    scanf("%f %d %f %d", &n1, &p1, &n2, &p2);

    printf("A media ponderada eh: %.2f", MediaPonderada(n1, p1, n2, p2));
    return 0;
}

float MediaPonderada(float nota1, float peso1, float nota2, float peso2)
{

        return (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
}
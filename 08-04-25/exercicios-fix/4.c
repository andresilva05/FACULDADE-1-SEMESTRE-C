// Exercício 5. Escreva um programa para classificar um triângulo de lados de comprimentos dados em
// escaleno(os três lados de comprimentos diferentes),
//     isósceles(dois lados de comprimentos iguais)
//         ou equilátero(os três lados de comprimentos iguais)
//             .

#include <stdio.h>

int main()
{

    int lado1, lado2, lado3;

    printf("Digite o comprimento dos 3 lados de um triangulo: ");
    scanf("%d %d %d", &lado1, &lado2, &lado3);

    if (lado1 == lado2 && lado2 == lado3)
    {
        printf("Seu triangulo eh equilatero");
    }
    else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
    {
        printf("Seu triangulo eh escaleno");
    }
    else
    {
        printf("Seu triangulo eh isosceles");
    }

    return 0;
}
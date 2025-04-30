// Exercício 1. Calcule a média de quatro números dados. Exiba o valor da média e, para
// cada número exiba se ele está abaixo ou acima da média.

#include <stdio.h>

int main()
{

    float num1, num2, num3, num4, media;

    printf("Digite 4 numeros: ");
    scanf("%f %f %f %f", &num1, &num2, &num3, &num4);

    media = (num1 + num2 + num3 + num4) / 4;

    printf("Média: %.2f\n\n", media);
    if (num1 >= media)
    {
        printf("Numero %.2f, Acima\n", num1);
    }
    else
        printf("Numero %.2f, Abaixo\n", num1);
    if (num2 >= media)
    {
        printf("Numero %.2f, Acima\n", num2);
    }
    else
        printf("Numero %.2f, Abaixo\n", num2);
    if (num3 >= media)
    {
        printf("Numero %.2f, Acima\n", num3);
    }
    else
        printf("Numero %.2f, Abaixo\n", num3);
    if (num4 >= media)
    {
        printf("Numero %.2f, Acima\n", num4);
    }
    else
        printf("Numero %.2f, Abaixo\n", num4);

    return 0;
}
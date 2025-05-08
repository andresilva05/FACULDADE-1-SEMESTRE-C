// 1. Biblioteca de Geometria: Crie uma biblioteca chamada "geometria" que contenha funções para
// calcular a área e o perímetro de um círculo, retângulo e triângulo.

// printf("A soma: %d", soma(5, 4));
#include <stdio.h>
#include "geometria.c"

int main()
{
    int escolhaConta, escolhaCalculo;
    float base, altura, areaCirculo, perimetroCirculo, areaTriangulo, perimetroTriangulo, lado1T, lado2T, lado3T, areaRetangulo, perimetroRetangulo, raio;

    printf("Ola, blz?\nEscolha a conta geométrica que deseja fazer de acordo com o código:\n");
    printf("1 - Triangulo\n2 - Retangulo\n3 - Circulo\n\n");

    do
    {
        printf("Digite o codigo da figura geometrica: ");
        scanf("%d", &escolhaConta);
    } while (escolhaConta != 1 && escolhaConta != 2 && escolhaConta != 3);

    do
    {
        printf("Escolha o calculo (1 para area, 2 para perimetro): ");
        scanf("%d", &escolhaCalculo);
    } while (escolhaCalculo != 1 && escolhaCalculo != 2);

    switch (escolhaConta)
    {
    case 1: // Triângulo
        switch (escolhaCalculo)
        {
        case 1: // Área
            printf("Digite a base e altura\n");
            scanf("%f %f", &base, &altura);
            areaTriangulo = area_triangulo(base, altura);
            printf("A área do triângulo é: %.2f\n", areaTriangulo);
            break;

        case 2: // Perímetro
            printf("Digite os 3 lados do triângulo:\n");
            scanf("%f %f %f", &lado1T, &lado2T, &lado3T);
            perimetroTriangulo = perimetro_triangulo_gen(lado1T, lado2T, lado3T);
            printf("O perímetro do triângulo é: %.2f\n", perimetroTriangulo);
            break;
        }
        break;

    case 2: // Retângulo
        switch (escolhaCalculo)
        {
        case 1:
            printf("Digite a base e altura\n");
            scanf("%f %f", &base, &altura);
            areaRetangulo = area_retangulo(base, altura);
            printf("A área do retângulo é: %.2f\n", areaRetangulo);
            break;

        case 2:
            printf("Digite a base e altura\n");
            scanf("%f %f", &base, &altura);
            perimetroRetangulo = perimetro_retangulo(base, altura);
            printf("O perímetro do retângulo é: %.2f\n", perimetroRetangulo);
            break;
        }
        break;

    case 3: // Círculo
        printf("Digite o valor do raio\n");
        scanf("%f", &raio);

        switch (escolhaCalculo)
        {
        case 1:
            areaCirculo = area_circulo(raio);
            printf("A área do círculo é: %.2f\n", areaCirculo);
            break;

        case 2:
            perimetroCirculo = perimetro_circulo(raio);
            printf("O perímetro do círculo é: %.2f\n", perimetroCirculo);
            break;
        }
        break;
    }

    return 0;
}

// Pseudocódigo	    Linguagem C
// escolha(valor)	    switch (valor)
// caso X:	            case X:
// pare	            break;
// padrao:	            default:

// if (escolhaConta == 1 && escolhaCalculo == 1)
//     {
//         printf("Digite a base e altura\n");
//         scanf("%f %f", &base, &altura);

//         areaTriangulo = area_triangulo(base, altura);

//         printf("A area do triangulo eh: %.2f", areaTriangulo);
//     }
//     if (escolhaConta == 1 && escolhaCalculo == 2)
//     {
//         printf("Digite os 3 lados do triangulo:\n");
//         scanf("%f %f %f", &lado1T, &lado2T, &lado3T);

//         perimetroTriangulo = perimetro_triangulo_gen(lado1T, lado2T, lado3T);

//         printf("O perimetro do triangulo eh: %.2f", perimetroTriangulo);
//     }

//     if (escolhaConta == 2 && escolhaCalculo == 1)
//     {
//         printf("Digite a base e altura\n");
//         scanf("%f %f", &base, &altura);

//         areaRetangulo = area_retangulo(base, altura);
//         ;

//         printf("A area do retangulo eh: %.2f", areaRetangulo);
//     }
//     if (escolhaConta == 2 && escolhaCalculo == 2)
//     {

//         printf("Digite a base e altura\n");
//         scanf("%f %f", &base, &altura);

//         perimetroRetangulo = perimetro_retangulo(base, altura);

//             printf("O perimetro do retangulo eh: %.2f", perimetroRetangulo);
//     }
//     if (escolhaConta == 3 && escolhaCalculo == 1)
//     {
//         printf("Digite o valor do raio\n");
//         scanf("%f", &raio);

//         areaCirculo = area_circulo(raio);

//         printf("A area do circulo eh: %.2f", areaCirculo);
//     }
//     if (escolhaConta == 3 && escolhaCalculo == 2)
//     {

//         printf("Digite o valor do raio\n");
//         scanf("%f", &raio);

//         perimetroCirculo = perimetro_circulo(raio);

//         printf("O perimetro do circulo eh: %.2f", perimetroCirculo);
//     }

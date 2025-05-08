#include "geometria.h"

float area_triangulo(float base, float altura)
{
    return (base * altura) / 2;
}

float perimetro_triangulo_gen(float a, float b, float c)
{
    return a + b + c;
}

float area_circulo(float raio)
{
    return 3.1415 * (raio * raio);
}

float perimetro_circulo(float raio)
{
    return 2 * 3.1415 * raio;
}

float area_retangulo(float base, float altura)
{
    return base * altura;
}

float perimetro_retangulo(float base, float altura)
{
    return 2 * (base + altura);
}

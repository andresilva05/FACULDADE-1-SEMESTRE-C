#include "conversoes.h"
#include <stdio.h>

// Celsius para Fahrenheit
float CelsiusToF(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

// Fahrenheit para Celsius
float FahrenheitToC(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

// Pes para metros
float PesToMetros(float pes)
{
    return pes * 0.3048;
}

// Metros para pes
float MetrosToPes(float metros)
{
    return metros * 3.28084;
}

// Kg para Libras
float KgToLb(float Kg)
{
    return Kg * 2.20462;
}

// Libras para Kg
float LbToKg(float Libras)
{
    return Libras * 0.453592;
}

int escolhaConversao()
{
    int escolha;
    printf("Ola, digite o codigo da conversao que deseja realizar!\n\n");
    printf("1- Celsius para Fahrenheit\n2- Fahrenheit para Celsius\n3- Pes para metros\n4- Metros para pes\n5- Kg para Libras\n6- Libras para Kg\n\n");

    // Leitura da escolha do usuário
    scanf("%d", &escolha);
    return escolha; // Retorna a escolha do usuário
}

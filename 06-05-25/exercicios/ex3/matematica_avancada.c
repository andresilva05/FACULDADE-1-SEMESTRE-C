#include "matematica_avancada.h"
#include <stdio.h>
#include <math.h>

// Calcula Potência de um número
double PotenciaDeN(double base, double expoente)
{
    return pow(base, expoente);
}

//  Calcula Fatorial de um número
int FatorialDeN(int numero)
{
    int fatorial = 1;
    for (int i = numero; i >= 1; i--)
    {
        fatorial *= i;
    }
    return fatorial;
}

// Verifica se Numero é primo
int NumeroPrimo(int num)
{

    if (num <= 1)
        return 0; // 0 e 1 não são primos
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int escolhaCalculo()
{
    int escolha;
    printf("Ola, digite o codigo do calculo que deseja realizar!\n\n");
    printf("1- Potencia de Numero\n2- Fatorial de Numero\n3- Verifica Se Numero eh primo\n\n");

    // Leitura da escolha do usuário
    scanf("%d", &escolha);
    return escolha; // Retorna a escolha do usuário
}

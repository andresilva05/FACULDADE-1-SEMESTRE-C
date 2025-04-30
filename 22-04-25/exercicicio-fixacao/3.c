// Exercício 3. Sobre unidades de medida, sabe-se que:
//  1 pé = 12 polegadas
//  1 jarda = 3 pés
//  1 milha = 1760 jardas
//  1 milha = 16093 metros
// Desenvolva um programa que receba uma medida em pés e apresente as conversões para
// polegadas, jardas, milhas e metros. Crie funções para converter cada uma das medidas.

// Assinaturas: float PesToPolegadas(float pes);
// float JardaToPes(float jarda);

float PesToPolegadas(float pes);
float PesToJardas(float pes);
float PesToMilhas(float pes);
float PesToMetros(float pes);

int main()
{
    float pes;

    printf("Digite uma medida em pes: \n");
    scanf("%f", &pes);

    printf("O valor da medida convertida de pes para polegadas eh: %.2f\nO valor da medida convertida de pes para jardas eh: %.2f\nO valor da medida convertida de pes para milhas eh: %.2f\nO valor da medida convertida de pes para Metros eh: %.2f\n", PesToPolegadas(pes), PesToJardas(pes), PesToMilhas(pes), PesToMetros(pes));
}

float PesToPolegadas(float pes)
{
    float polegadas;
    return polegadas = pes * 12;
}

float PesToJardas(float pes)
{
    float jardas;

    jardas = pes / 3;
    return jardas;
}

float PesToMilhas(float pes)
{
    return pes / 5280;
}


float PesToMetros(float pes) {
    return pes * 0.3048;
}

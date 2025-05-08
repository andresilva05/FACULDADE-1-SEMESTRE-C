// 2. Biblioteca de Conversão de Unidades: Desenvolva uma biblioteca "conversoes" com funções
// para converter temperaturas (Celsius para Fahrenheit e vice-versa), distâncias (metros para pés e
// vice-versa) e pesos (quilogramas para libras e vice-versa)

#include <stdio.h>

#include "conversoes.c"

int main()
{

    int escolhaUsuario, continuar;
    float temperatura, pes, metros, kg, libras;

    do
    {
        // Loop interno para garantir escolha válida
        do
        {
            escolhaUsuario = escolhaConversao();
            if (escolhaUsuario < 1 || escolhaUsuario > 6)
            {
                printf("Opcao invalida! Tente novamente.\n\n");
            }
        } while (escolhaUsuario < 1 || escolhaUsuario > 6);

        switch (escolhaUsuario)
        {
        case 1: // Celsius para Fahrenheit
            printf("Digite o valor da temperatura em Graus Celsius:\n");
            scanf("%f", &temperatura);

            printf("A conversao de %.2fC para Fahrenheit eh: %.2fF\n", temperatura, CelsiusToF(temperatura));

            break;
        case 2: // Fahrenheit para Celsius
            printf("Digite o valor da temperatura em Fahrenheit:\n");
            scanf("%f", &temperatura);

            printf("A conversao de %.2fF para Celsius eh: %.2f°C\n", temperatura, FahrenheitToC(temperatura));
            break;

        case 3: // Pés para metros
            printf("Digite o valor de pes:\n");
            scanf("%f", &pes);
            printf("A conversao de %.2f pes para metros eh: %.2f\n", pes, PesToMetros(pes));

            break;
        case 4: // Metros para pés
            printf("Digite o valor de metros:\n");
            scanf("%f", &metros);
            printf("A conversao de %.2f metros para pes eh: %.2f\n", metros, MetrosToPes(metros));

            break;
        case 5: // Kg para libras
            printf("Digite o peso em Quilogramas:\n");
            scanf("%f", &kg);
            printf("A conversao de %.2f Kg para Libras eh: %.2f\n", kg, KgToLb(kg));
            break;
        case 6: // Libras para Kg
            printf("Digite o peso em Libras:\n");
            scanf("%f", &libras);
            printf("A conversao de %.2f Libras para Kg eh: %.2f\n", libras, LbToKg(libras));
            break;
        }
        printf("Deseja fazer outra conversao? (1 para sim, 0 para nao)!\n");
        scanf("%d", &continuar);

    } while (continuar == 1);

    printf("Obrigado por usar o conversor!\n");
    return 0;
}
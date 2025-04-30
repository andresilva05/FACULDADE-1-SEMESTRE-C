// Exercício 8. Considere que uma calculadora comum, de quatro operações aritméticas, está com as
// teclas de divisão e multiplicação quebradas. Escreva funções para a multiplicação e divisão, usando
// apenas as operações de adição e subtração.

#include <stdio.h>

int soma(int a, int b);

int subtracao(int a, int b);

int multiplicacao(int a, int b);

float divisao(float a, float b);

int main()
{
    int opcao, somaA, somaB, multiplicaA, multiplicaB, subtraiA, subtraiB;
    float dividiA, dividiB;

    printf("Digite o codigo da conta a ser realizada:\n");
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n");

    do
    {
        printf("Digite a conta a ser efetuada conforme orientacao acima ou 0 para encerrar:\n\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            printf("Digite dois numeros para somar:\n");
            scanf("%d %d", &somaA, &somaB);

            printf("O resultado da soma de %d + %d eh = %d\n", somaA, somaB, soma(somaA, somaB));
        }
        if (opcao == 2)
        {
            printf("Digite dois numeros para subtrair:\n");
            scanf("%d %d", &subtraiA, &subtraiB);

            printf("O resultado da subtracao de %d - %d eh = %d\n", subtraiA, subtraiB, subtracao(subtraiA, subtraiB));
        }

        if (opcao == 3)
        {
            printf("Digite dois numeros para multiplicar:\n");
            scanf("%d %d", &multiplicaA, &multiplicaB);

            printf("O resultado da multiplicacao de %d x %d eh = %d\n", multiplicaA, multiplicaB, multiplicacao(multiplicaA, multiplicaB));
        }

        if (opcao == 4)
        {
            printf("Digite dois numeros para dividir:\n");
            scanf("%f %f", &dividiA, &dividiB);
            printf("O resultado da divisao de %0.f / %0.f eh = %.2f\n", dividiA, dividiB, divisao(dividiA, dividiB));
        }
        if (opcao == 0)
            break;

    } while (opcao != 0);

    printf("Fim!");
}

int soma(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{

    int i, contador;

    for (i = 1; i <= b; i++)
    {

        contador += a;
    }

    return contador;
}

float divisao(float a, float b)
{

    int contador = 0;

    while (a >= b)
    {
        a = a - b;
        contador++;
    }

    return contador;
}
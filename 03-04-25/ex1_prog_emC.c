/* Programa que determina a média de três números dados */
#include <stdio.h> // Biblioteca padrão para entrada e saída (printf, scanf)

int main()
{
    float a, b, c, media; // Declara quatro variáveis do tipo float (números com casas decimais)

    // Exibe uma mensagem na tela pedindo para o usuário digitar três números
    puts("Digite três números");

    // Lê três números digitados pelo usuário e armazena nas variáveis a, b e c
    scanf("%f %f %f", &a, &b, &c);

    // Calcula a média dos três números somando-os e dividindo por 3
    media = (a + b + c) / 3;

    // Exibe o resultado na tela
    printf("A media dos números %f , %f e %f é igual a %f ", a, b, c, media);

    return 0; // Retorna 0 indicando que o programa terminou corretamente
}

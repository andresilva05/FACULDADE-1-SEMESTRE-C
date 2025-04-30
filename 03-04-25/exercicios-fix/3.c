// Programa que troca (permuta) os valores de duas variáveis
#include <stdio.h> // Biblioteca padrão para entrada e saída de dados

int main()
{
    int temp, a, b; // Declaração das variáveis: 'a' e 'b' para os números e 'temp' como auxiliar na troca

    // Pede para o usuário digitar o valor de 'a'
    printf("Digite o valor de A: \n");
    scanf("%d", &a); // Lê e armazena o valor digitado na variável 'a'

    // Pede para o usuário digitar o valor de 'b'
    printf("Digite o valor de B: \n");
    scanf("%d", &b); // Lê e armazena o valor digitado na variável 'b'

    // Troca os valores de 'a' e 'b' usando uma variável auxiliar 'temp'
    temp = a; // Guarda o valor de 'a' na variável temporária
    a = b;    // Agora 'a' recebe o valor de 'b'
    b = temp; // 'b' recebe o valor que estava em 'a' (guardado em 'temp')

    // Exibe os valores após a troca
    printf("Valor de A com a troca será: %d \n", a);
    printf("Valor de B com a troca será: %d \n", b);

    return 0; // Retorna 0 indicando que o programa finalizou corretamente
}

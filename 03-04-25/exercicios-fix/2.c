// . Gerar o inverso de um número com três algarismos (exemplo: o inverso de 498 é 894).

/* Programa que inverte um número com três algarismos */
#include <stdio.h> // Biblioteca padrão de entrada e saída (printf, scanf)

int main()
{
    int num, unidades, dezenas, centenas, invertido; // Declara variáveis para os dígitos e o número invertido

    // Pede para o usuário digitar um número de três algarismos (entre 100 e 999)
    printf("Digite um inteiro com três algarismos: ");
    scanf("%d", &num); // Lê o número digitado e armazena em 'num'

    // Obtém o último dígito (unidade) com o operador módulo (%)
    unidades = num % 10; // Ex: se num = 123 → unidades = 3

    // Obtém o dígito do meio (dezena)
    dezenas = (num / 10) % 10; // Ex: 123 / 10 = 12, e 12 % 10 = 2 → dezenas = 2

    // Obtém o primeiro dígito (centena)
    centenas = num / 100; // Ex: 123 / 100 = 1 → centenas = 1

    // Constrói o número invertido:
    // coloca as unidades na casa da centena, as dezenas no meio e as centenas na casa da unidade
    invertido = unidades * 100 + dezenas * 10 + centenas;

    // Mostra o número original e o número invertido
    printf("O inverso de %d e' %d ", num, invertido);

    return 0; // Fim do programa
}

// 3. Exemplo Difícil: Fatorial com Validação de Entrada
// Neste exemplo, o programa vai calcular o fatorial de um número positivo e, se o usuário digitar um número negativo, ele irá solicitar novamente o número até que ele seja válido.

#include <stdio.h>

int main() {
    int n, fatorial = 1;

    do {
        // Solicita o número
        printf("Digite um número positivo para calcular o fatorial: ");
        scanf("%d", &n);

        // Se o número for negativo, solicita novamente
        if (n < 0) {
            printf("Número inválido. O número deve ser positivo.\n");
        }
    } while (n < 0);  // Continua pedindo até que o número seja positivo

    // Calcula o fatorial
    for (int i = n; i >= 1; i--) {
        fatorial *= i;
    }

    // Exibe o resultado
    printf("O fatorial de %d é %d.\n", n, fatorial);
    return 0;
}

// Explicação:
// Neste exemplo, o programa usa do...while para garantir que o usuário forneça um número positivo. Se o número for negativo, ele solicita novamente até que o número correto seja digitado. Após isso, ele calcula o fatorial do número e exibe o resultado.
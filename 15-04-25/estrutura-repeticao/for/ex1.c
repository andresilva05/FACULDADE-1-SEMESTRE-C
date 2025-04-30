#include <stdio.h>  // Biblioteca padrão para entrada e saída

int main() {
    int contador;  // Declara a variável que vai controlar o loop

    // Mostra uma mensagem antes de iniciar a contagem
    printf("Contagem progressiva... ");

    // Laço de 1 até 10 (inclusive), incrementando de 1 em 1
    for (contador = 1; contador <= 10; contador++) {
        printf("\n %d", contador);  // Imprime o valor atual do contador
    }

    return 0;  // Finaliza o programa
}


// #include <stdio.h>

// int main() {
//     printf("Contagem progressiva...");
//     for (int i = 1; i <= 10; i++)
//         printf("\n %d", i);
//     return 0;
// }

#include <stdio.h>

// Função para limpar o buffer de entrada (consome caracteres até '\n')
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta o caractere
    }
}
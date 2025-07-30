#include <stdio.h>
#include "cesar.c"

int main() {
    char mensagem[100];
    int chave = 3;

    // Lê a mensagem a ser criptografada
    printf("Digite a mensagem a ser criptografada: ");
    gets(mensagem);

    // Criptografa a mensagem
    criptografar(mensagem, chave);

    // Imprime a mensagem criptografada
    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}
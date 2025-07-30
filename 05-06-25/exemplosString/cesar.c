#include <ctype.h> // Para usar funções como isalpha e isupper
#include "cesar.h"

// Função para criptografar uma mensagem usando o código de César
void criptografar(char mensagem[], int chave) {
    int i = 0;

    // Percorre a mensagem
    while (mensagem[i] != '\0') {
        char caracter = mensagem[i];

        // Verifica se o caracter é uma letra maiúscula
        if (isalpha(caracter) && isupper(caracter)) {
            // Aplica o deslocamento e ajusta para o alfabeto maiúsculo (A-Z)
            caracter = 'A' + (caracter - 'A' + chave) % 26;
        }
        // Caso o caracter seja minúsculo
        else if (isalpha(caracter)) {
            // Aplica o deslocamento e ajusta para o alfabeto minúsculo (a-z)
            caracter = 'a' + (caracter - 'a' + chave) % 26;
        }

        // Substitui o caracter na mensagem
        mensagem[i] = caracter;
        i++;
    }
}



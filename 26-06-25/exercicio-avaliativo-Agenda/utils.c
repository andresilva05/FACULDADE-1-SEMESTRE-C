#include <stdio.h>

// Função para limpar o buffer de entrada do teclado
// Ela consome e descarta todos os caracteres restantes na linha até encontrar o '\n' ou EOF,
// evitando que dados residuais interfiram nas próximas leituras.
void limparBufferEntrada(void)
{
    int c;
    // Lê caracteres até encontrar o fim da linha ou fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Não faz nada, só descarta
    }
}

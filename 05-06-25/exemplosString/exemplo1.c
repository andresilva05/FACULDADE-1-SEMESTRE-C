#include <stdio.h> // Para printf e scanf

int main() {
    char nome[30]; // variavel para armazenar o nome

    printf("Digite seu primeiro nome: ");
    scanf("%s", nome); // Lê a string digitada

    printf("O nome digitado foi: %s \n", nome); // exibe o nome lido

    return 0; 
}

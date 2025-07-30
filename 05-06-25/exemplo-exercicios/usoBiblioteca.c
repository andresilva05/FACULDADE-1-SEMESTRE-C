#include <stdio.h>
#include <string.h>
#define TAM 20

int main()
{
    char nome[TAM];
    char sobrenome[TAM];

    strcpy(nome, "Eduardo");
    strcpy(sobrenome, " Leal");

    printf("Nome: %s\n", nome);
    printf("Sobrenome: %s\n", sobrenome);
    strcat(nome, sobrenome);
    printf("Nome completo: %s\n", nome);
    printf("O nome eh Eduardo Leal? %d\n", strcmp(nome, "Eduardo Leal"));

    printf("O nome eh Eduardo Lima? %d\n", strcmp(nome, "Eduardo Lima"));
    printf("O nome %s possui %d caracteres.\n", nome, strlen(nome));

    return 0;
}
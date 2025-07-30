// 2. Faça um programa que leia três palavras distintas e coloque-as em ordem alfabética.
// Semelhante ao exercício anterior, mas com três variáveis de entrada.

#include <stdio.h>  // Biblioteca para entrada e saída (printf, scanf)
#include <string.h> // Biblioteca para manipulação de strings (strcmp, strcpy)

int main()
{
    char palavra1[20];  // Armazena a 1ª palavra digitada
    char palavra2[20];  // Armazena a 2ª palavra digitada
    char palavra3[20];  // Armazena a 3ª palavra digitada
    char resultado[20]; // Usada temporariamente para trocar palavras

    printf("Digite tres palavras distintas:\n");
    scanf("%s", palavra1); // Lê a 1ª palavra
    scanf("%s", palavra2); // Lê a 2ª palavra
    scanf("%s", palavra3); // Lê a 3ª palavra

    // Primeiro passo: garantir que palavra1 < palavra2
    if (strcmp(palavra1, palavra2) < 0)
    {
        // Já estão na ordem certa, não faz nada
    }
    else
    {
        // Se palavra1 > palavra2, troca as duas
        strcpy(resultado, palavra1);
        strcpy(palavra1, palavra2);
        strcpy(palavra2, resultado);
    }

    // Segundo passo: garantir que palavra2 < palavra3
    if (strcmp(palavra2, palavra3) < 0)
    {
        // Já estão na ordem certa, não faz nada
    }
    else
    {
        // Se palavra2 > palavra3, troca as duas
        strcpy(resultado, palavra2);
        strcpy(palavra2, palavra3);
        strcpy(palavra3, resultado);
    }

    // Terceiro passo: repetir a comparação entre palavra1 e palavra2
    // (porque palavra2 pode ter mudado de lugar com palavra3)
    if (strcmp(palavra1, palavra2) < 0)
    {
        // Já estão na ordem certa, não faz nada
    }
    else
    {
        // Se palavra1 > palavra2, troca as duas
        strcpy(resultado, palavra1);
        strcpy(palavra1, palavra2);
        strcpy(palavra2, resultado);
    }

    // Exibe as três palavras já em ordem alfabética
    printf("\n%s %s %s\n", palavra1, palavra2, palavra3);

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char palavras[3][20];
//     char temp[20];

//     printf("Digite tres palavras distintas:\n");
//     scanf("%s", palavras[0]);
//     scanf("%s", palavras[1]);
//     scanf("%s", palavras[2]);

//     // Bubble sort para ordenar as palavras
//     for (int i = 0; i < 2; i++) {
//         for (int j = i + 1; j < 3; j++) {
//             if (strcmp(palavras[i], palavras[j]) > 0) {
//                 // Troca as palavras
//                 strcpy(temp, palavras[i]);
//                 strcpy(palavras[i], palavras[j]);
//                 strcpy(palavras[j], temp);
//             }
//         }
//     }

//     printf("\nPalavras em ordem alfabetica:\n");
//     printf("%s %s %s\n", palavras[0], palavras[1], palavras[2]);

//     return 0;
// }

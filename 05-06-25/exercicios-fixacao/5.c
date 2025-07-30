// 5. Faça um programa que conte o quantas vezes número “1” aparece em um string.
// Exemplo: em “0011001” a resposta será 3.
#include <stdio.h>
#define TAM 8 // Define o tamanho do vetor, igual ao tamanho da string "0011001"

int verificaQtdNumeroUm(char numero[]); // Protótipo da função que conta quantos '1' existem na string

int main()
{
    char numero[TAM] = "0011001"; // Inicializa o vetor com a string desejada

    // Imprime o resultado da contagem de '1's e a string original
    printf("O numero 1 aparece %d vezes no numero %s.\n", verificaQtdNumeroUm(numero), numero);

    return 0;
}

int verificaQtdNumeroUm(char numero[])
{
    int i, somaQtd = 0;

    // Loop para percorrer o vetor de caracteres
    for (i = 0; i < TAM; i++)
    {
        // Verifica se o caractere atual é '1'
        if (numero[i] == '1')
        {
            somaQtd++; // Incrementa o contador quando encontra '1'
        }
    }

    return somaQtd; // Retorna o total de '1's encontrados
}

// int verificaQtdNumeroUm(char numero[])
// {
//     int i, somaQtd = 0;
//     int tamanho = strlen(numero); // calcula o tamanho real da string

//     for (i = 0; i < tamanho; i++)
//     {
//         if (numero[i] == '1')
//         {
//             somaQtd++;
//         }
//     }

//     return somaQtd;
// }

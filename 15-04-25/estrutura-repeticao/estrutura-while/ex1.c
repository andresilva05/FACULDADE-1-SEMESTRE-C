#include <stdio.h> // Inclusão da biblioteca padrão de entrada e saída

int main()
{
    double somaNotas = 0; // Variável para acumular a soma das notas válidas
    int qtdeNotas = 0;    // Contador de quantas notas válidas foram digitadas
    double mediaNotas;    // Variável para armazenar a média das notas
    double nota = 0;      // Variável que armazena temporariamente cada nota digitada

    // Loop que continuará enquanto a nota digitada estiver entre 0 e 10 (inclusive)
    while ((nota >= 0) && (nota <= 10))
    {
        printf("Nota [digite <0 ou >10 para sair]: "); // Pede ao usuário uma nota
        scanf("%lf", &nota);                           // Lê a nota digitada

        // Se a nota digitada estiver entre 0 e 10 (inclusive), ela é considerada válida
        if ((nota >= 0) && (nota <= 10))
        {
            somaNotas += nota; // Soma a nota à variável acumuladora
            qtdeNotas++;       // Incrementa o contador de notas válidas
        }
    }

    // Após sair do loop, se pelo menos uma nota válida foi digitada:
    if (qtdeNotas > 0)
    {
        mediaNotas = somaNotas / qtdeNotas;              // Calcula a média
        printf("Total de notas lidas: %d\n", qtdeNotas); // Exibe o número de notas válidas
        printf("Media das notas: %.1lf\n", mediaNotas);  // Exibe a média com uma casa decimal
    }

    return 0; // Finaliza o programa
}

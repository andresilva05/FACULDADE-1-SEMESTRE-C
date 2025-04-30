// Determinar o maior múltiplo de um inteiro dado menor do que ou igual a um outro inteiro
// dado.
// Por exemplo: o maior múltiplo de 7 menor que 50 é 49.

#include <stdio.h> // Biblioteca padrão para entrada e saída de dados

int main()
{
    // Declaração das variáveis
    int base, limite, inteiro, num;

    // Pede para o usuário digitar a base do múltiplo (por exemplo, 7)
    printf("Digite um numero inteiro: \n");
    scanf("%d", &base); // Lê esse valor e guarda em "base"

    // Pede para o usuário digitar o maior número que pode ser considerado como limite
    printf("Digite o maior número que pode ser considerado: \n");
    scanf("%d", &limite); // Lê esse valor e guarda em "limite"

    // Calcula quantas vezes o número "base" cabe dentro do "limite"
    inteiro = limite / base;

    // Multiplica o número inteiro de vezes que cabe pela base, achando o maior múltiplo
    num = inteiro * base;

    // Mostra o resultado
    printf("O maior múltiplo de %d menor ou igual a %d é: %d", base, limite, num);

    return 0; // Finaliza o programa
}

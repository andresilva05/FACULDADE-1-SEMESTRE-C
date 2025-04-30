// Exercício 1. Calcule a média de um aluno na disciplina de ARQIPCO. Para isso solicite as notas das
// avaliações e seus respectivos pesos. Mostre a média como resultado e caso ela seja maior ou igual
// a 6.0, informe que o aluno foi aprovado.

#include <stdio.h>

int main()
{

    float n1, n2, media;
    int peso1, peso2;

    printf("Digite nota da primeira avaliacao e seu peso: ");
    scanf("%f %d", &n1, &peso1);
    printf("Digite nota da segunda avaliacao e seu peso: ");
    scanf("%f %d", &n2, &peso2);

    media = (n1 * peso1 + n2 * peso2) / (peso1 + peso2);

    if (media >= 6.0)
    {
        printf("Parabens, voce foi aprovado!");
    }
    else
    {
        printf("Infelizmente voce foi reprovado! :(");
    }

    return 0;
}
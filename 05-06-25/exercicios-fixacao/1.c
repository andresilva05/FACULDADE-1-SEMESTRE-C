// 1. Faça um programa que leia duas palavras distintas e coloque-as em ordem alfabética.
// Entrada
// A entrada consiste em duas variáveis (palavra1 e palavra2), declaradas como tipo de dados string.
// Saída
// Exiba uma única linha contendo as duas palavras, ordenadas alfabeticamente.

int main()
{
    char palavra1[20];
    char palavra2[20];

    printf("Digite duas palavras distintas:\n");
    scanf("%s", palavra1);
    scanf("%s", palavra2);

    if (strcmp(palavra1, palavra2) < 0)
    {
        printf("\n%s %s ", palavra1, palavra2);
    }
    else
    {
        printf("\n%s %s ", palavra2, palavra1);
    }

    return 0;
}
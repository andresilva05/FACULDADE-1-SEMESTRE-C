#include <stdio.h> // Biblioteca padrão de entrada e saída

// Definição de uma estrutura chamada 'Data' com três campos: dia, mês e ano
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Protótipos das funções que serão usadas no programa
Data lerData();            // Função que lê uma data do usuário
void imprimirData(Data x); // Função que imprime uma data na tela
int verificaData(Data x);  // Função que verifica se o mês da data é válido

int main()
{
    Data data;              // Declara uma variável do tipo Data
    data = lerData();       // Chama a função para ler a data do usuário
    imprimirData(data);     // Exibe a data digitada
    if (verificaData(data)) // Verifica se o mês está entre 1 e 12
        printf("\n Data com mes válido!");
    else
        printf("\n Data com mes inválido!");
}

// Função que lê os valores de dia, mês e ano do usuário e retorna uma struct Data preenchida
Data lerData()
{
    Data x;
    printf("Entre o dia: ");
    scanf("%d", &x.dia); // Lê o dia
    printf("Entre o mes: ");
    scanf("%d", &x.mes); // Lê o mês
    printf("Entre o ano: ");
    scanf("%d", &x.ano); // Lê o ano
    return x;            // Retorna a struct preenchida
}

// Função que imprime os valores da struct Data no formato dd/mm/aaaa
void imprimirData(Data x)
{
    printf("\n Data %d/%d/%d", x.dia, x.mes, x.ano);
}

// Função que verifica se o valor do mês está no intervalo de 1 a 12
int verificaData(Data x)
{
    int valido = 1;
    if ((x.mes < 1) || (x.mes > 12)) // Se o mês for menor que 1 ou maior que 12
        valido = 0;                  // então é inválido
    return valido;                   // Retorna 1 se válido, 0 se inválido
}

#ifndef DATA_H
#define DATA_H

// Definição da struct para armazenar uma data (dia, mês e ano)
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Protótipos das funções relacionadas a datas e validação de texto

// Lê uma data do usuário e retorna uma struct Data
Data lerData(void);

// Imprime a data no formato dia/mês/ano
void imprimirData(Data x);

// Verifica se a data passada é válida (retorna 1 se válida, 0 se inválida)
int verificaData(Data x);

// Verifica se o ano é bissexto (retorna 1 se for, 0 se não)
int ehBissexto(int ano);

// Verifica se a string contém algum caractere diferente de espaço (retorna 1 se contém texto válido, 0 se vazia ou só espaços)
int verificaTextoString(char texto[]);

#endif

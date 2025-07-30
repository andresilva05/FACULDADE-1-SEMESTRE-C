
#ifndef DATA_H

typedef struct
{
    int dia, mes, ano;
} Data;

int verificaData(Data x);
int ehBissexto(int ano);

#endif
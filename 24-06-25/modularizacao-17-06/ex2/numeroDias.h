#ifndef NUMERO_DIAS_H

typedef struct
{
    int dia, mes, ano;
} Data;

int ehBissexto(int ano);
int totalDias(Data d);
int diferencaDias(Data d1, Data d2);

#endif
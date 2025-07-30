
#ifndef DATA_H

typedef struct
{
    int dia, mes, ano;
} Data;

Data lerData();

void imprimirData(Data x);
int verificaMes(Data x);

#endif
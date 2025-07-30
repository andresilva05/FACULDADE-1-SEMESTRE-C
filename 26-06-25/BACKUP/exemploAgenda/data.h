#ifndef DATA_H
    #define DATA_H
    
    typedef struct{
        int dia;
        int mes;
        int ano;
    } Data;

    Data lerData(void);
    void imprimirData(Data x);
    int verificaData(Data x);
#endif
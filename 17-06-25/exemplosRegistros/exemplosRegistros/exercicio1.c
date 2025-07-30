#include <stdio.h>
typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

int verificaData(Data x);

int main(){
    Data data;
    printf("Entre o dia:" );
    scanf("%d",&data.dia);
    printf("Entre o mes:" );
    scanf("%d",&data.mes);
    printf("Entre o ano:" );
    scanf("%d",&data.ano);
    if(verificaData(data)) printf("\n Data com mes valido!");
    else printf("\n Data com mes invalido!");
}

int verificaData(Data x){
    int valido = 1;
    if((x.mes<1)||(x.mes>12)) valido = 0;
    return(valido);
}
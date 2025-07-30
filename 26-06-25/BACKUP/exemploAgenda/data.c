#include <stdio.h>
#include "data.h"

Data lerData(){
    Data x;
    printf("Entre o dia:" );
    scanf("%d",&x.dia);
    printf("Entre o mes:" );
    scanf("%d",&x.mes);
    printf("Entre o ano:" );
    scanf("%d",&x.ano);
    return(x);
};

void imprimirData(Data x){
    printf(" %d/%d/%d", x.dia, x.mes, x.ano);
};

int verificaData(Data x){
    int valido = 1;
    if((x.mes<1)||(x.mes>12)) valido = 0;
    return(valido);
}
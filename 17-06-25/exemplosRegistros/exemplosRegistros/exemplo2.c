#include <stdio.h>

int main(){
    struct dma{
        int dia;
        int mes;
        int ano;
    };
    struct dma x, y;
    x.dia = 17;
    x.mes = 6;
    x.ano = 2025;
    printf("\n Hoje %d/%d/%d", x.dia, x.mes, x.ano);
    y = x;
    printf("\n Amanha %d/%d/%d", y.dia+1, y.mes, y.ano);
}
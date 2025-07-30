#include <stdio.h>

int main(){
    struct{
        int dia;
        int mes;
        int ano;
    } x;

    x.dia = 17;
    x.mes = 6;
    x.ano = 2025;
    printf("Hoje %d/%d/%d", x.dia, x.mes, x.ano);
}
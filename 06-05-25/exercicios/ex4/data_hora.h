#ifndef DATA_HORA_H
#define DATA_HORA_H

void define_mes(int mes);
int define_dia_semana(int D, int M, int A);
int is_bissexto(int ano);
int dias_ate_data(int D, int M, int A);
int diferenca_dias(int D1, int M1, int A1, int D2, int M2, int A2);
int opcaoParaUsuario();
#endif

// 4. Biblioteca de Data e Hora: Desenvolva uma biblioteca "data_hora" que contenha funções para
// formatar uma data, calcular a diferença entre duas datas e obter o dia da semana de uma data.

#include "data_hora.c"
#include <stdio.h>

int main()
{
    int opcao;

    do
    {
        opcao = opcaoParaUsuario();  // Chama a função que lida com a entrada do usuário

    } while (opcao == 1);  // Se o usuário escolher "1", o programa continua

    printf("Programa encerrado.\n");  // Mensagem de encerramento

    return 0;
}


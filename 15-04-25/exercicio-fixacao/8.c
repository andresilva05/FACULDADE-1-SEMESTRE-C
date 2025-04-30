// Exercício 8. Em uma eleição existem 2 chapas concorrentes. Os votos para as chapas são
// informados por meio de código, conforme a tabela abaixo.
// 1, 2 Votos para as respectivas chapas
// 5 Voto nulo
// 6 Voto em branco
// Faça um programa em C que calcule e mostre:
// • O total de votos para cada chapa;
// • O total de votos nulos;
// • O total de votos em branco;
// • A porcentagem de votos nulos sobre o total de votos e;
// • A porcentagem de votos em branco sobre o total de votos.
// • Os votos devem ser informados um a um. Para finalizar a entrada de dados
// (votos), deve-se utilizar o valor zero e, para códigos inválidos, o programa deverá
// mostrar uma mensagem.

#include <stdio.h>

int main()
{

    int seuVoto, primChapa = 1, segunChapa = 2, votoNulo = 5, votoBranco = 6, totalVotos = 0, totalVoto1 = 0, totalVoto2 = 0;
    float porcVotosNulos, porcVotosBrancos, totalNulo = 0, totalVotoBranco = 0;

    printf("Ola eleitor, para efetuar seu voto deve-se, digitar os seguintes numeros:\n1 e 2 para as respectivas chapas\n5 Voto nulo\n6 Voto em branco\n\n");
    while (1)
    {
        printf("Digite o codigo do seu voto:\n");
        scanf("%d", &seuVoto);

        if (seuVoto == 0)
        {
            break; // Sai do loop
        }
        else
        {

            if (seuVoto == primChapa || seuVoto == segunChapa || seuVoto == votoNulo || seuVoto == votoBranco)
            {
                totalVotos++;
                if (seuVoto == primChapa)
                {
                    totalVoto1++;
                }
                if (seuVoto == segunChapa)
                {
                    totalVoto2++;
                }
                if (seuVoto == votoNulo)
                {

                    totalNulo++;
                }
                if (seuVoto == votoBranco)
                {
                    totalVotoBranco++;
                }
            }
            else
            {
                printf("Numero digitado nao corresponde aos codigos da eleicao, por favor, digite um numero valido!\n");
            }
        }
    }

    porcVotosNulos = (totalNulo / totalVotos) * 100;
    porcVotosBrancos = (totalVotoBranco / totalVotos) * 100;

    printf("O total de votos eh: %d\n", totalVotos);
    printf("O total de votos para primeira chapa, foi de: %d \n", totalVoto1);
    printf("O total de votos para segunda chapa, foi de: %d \n", totalVoto2);
    printf("O total de votos nulos eh: %.0f \n", totalNulo);
    printf("O total de votos em branco eh: %.0f \n", totalVotoBranco);
    printf("A porcentagem de votos nulos sobre o total de votos eh: %.0f%%\n", porcVotosNulos);
    printf("A porcentagem de votos brancos sobre o total de votos eh: %.0f%%\n", porcVotosBrancos);

    return 0;
}

// CODIGO MAIS CURTO E MAIS ESTRUTURADO

// #include <stdio.h>

// int main() {
//     int voto, totalVotos = 0, totalVoto1 = 0, totalVoto2 = 0;
//     float totalNulo = 0, totalBranco = 0;

//     printf("Ola eleitor, digite:\n1 ou 2 para votar nas chapas\n5 para voto nulo\n6 para voto em branco\n0 para encerrar\n\n");

//     while (1) {
//         printf("Digite o codigo do seu voto: ");
//         scanf("%d", &voto);

//         if (voto == 0) break; // Finaliza a votação

//         // Valida os votos e contabiliza
//         if (voto == 1 || voto == 2 || voto == 5 || voto == 6) {
//             totalVotos++;
//             if (voto == 1) totalVoto1++;
//             else if (voto == 2) totalVoto2++;
//             else if (voto == 5) totalNulo++;
//             else totalBranco++;
//         } else {
//             printf("Codigo invalido. Digite novamente.\n");
//         }
//     }

//     // Calcula as porcentagens
//     float porcNulo = (totalNulo / totalVotos) * 100;
//     float porcBranco = (totalBranco / totalVotos) * 100;

//     // Exibe resultados
//     printf("\nTotal de votos: %d\n", totalVotos);
//     printf("Chapa 1: %d votos\n", totalVoto1);
//     printf("Chapa 2: %d votos\n", totalVoto2);
//     printf("Nulos: %.0f votos (%.0f%%)\n", totalNulo, porcNulo);
//     printf("Brancos: %.0f votos (%.0f%%)\n", totalBranco, porcBranco);

//     return 0;
// }

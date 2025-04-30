// Exercício 3. Deseja-se calcular o imposto de renda de um contribuinte. Para isto, escreva
// um programa que:
// a. leia os dados do contribuinte: CPF, nome, rendimento mensal, contribuição previdenciária
// e número de dependentes;
// b. pesquise o valor de dedução de cada dependente e crie uma variável para armazenar
// esse valor;
// c. o cálculo do valor total das deduções é dado por contribuição previdenciária + dedução
// dos dependentes;
// d. pesquise e construa as regras necessárias para a Base de cálculo, como o modelo
// exemplificado abaixo. Observação: os valores no exemplo são fictícios, seu programa deve
// conter os valores reais.
// Faixa Base de Cálculo
// (R$)
// Alíquota
// (%)
// Parcela a
// Deduzir do IR
// (R$)
// 1 até 100,00 Isento -
// 2 De 100,01 até
// 200,00
// 15% 16,00
// 3 acima de 200,00 25% 30,00
// Cálculo do imposto devido: (base de cálculo x alíquota) - parcela a deduzir
// e. exiba todos os dados lidos e calculados.

#include <stdio.h>
#include <string.h>

int main()
{
    // Declaração de variáveis
    char cpf[11], nome[50];  // Variáveis para armazenar o CPF e o nome do contribuinte
    int dependentes;          // Número de dependentes
    float rendimentoMensal,  // Rendimento mensal do contribuinte
          contribuicaoInss,  // Contribuição para o INSS
          deducao = 189.59,  // Deduções padrão por dependente
          totalDeducao,      // Valor total das deduções (INSS + dependentes)
          valorDeducao,      // Valor da dedução para os dependentes
          imposto,           // Valor do imposto a ser pago
          baseCalculo,       // Base de cálculo para o imposto (rendimento - deduções)
          faixa2 = 0.075,    // Alíquota da faixa 2 (7.5%)
          faixa3 = 0.15,     // Alíquota da faixa 3 (15%)
          faixa4 = 0.225,    // Alíquota da faixa 4 (22.5%)
          faixa5 = 0.275;    // Alíquota da faixa 5 (27.5%)

    // Entrada do CPF com validação para ter exatamente 11 caracteres
    do
    {
        printf("Digite seu CPF: \n");
        scanf("%s", &cpf);
    } while (strlen(cpf) != 11);  // Enquanto o CPF não tiver 11 caracteres, pede novamente

    // Entrada do nome
    printf("Digite seu nome: \n");
    scanf(" %[^\n]", nome);  // Lê o nome com espaços

    // Entrada do rendimento mensal
    printf("Digite seu rendimento mensal: \nR$");
    scanf("%f", &rendimentoMensal);

    // Entrada do valor da contribuição para o INSS
    printf("Digite o valor da sua contribuicao para o INSS: \nR$");
    scanf("%f", &contribuicaoInss);

    // Entrada do número de dependentes
    printf("Digite o numero de dependentes que voce possui: \n");
    scanf("%d", &dependentes);

    // Calcula o valor da dedução total dos dependentes
    valorDeducao = deducao * dependentes;

    // Calcula o total de deduções (INSS + deduções dos dependentes)
    totalDeducao = contribuicaoInss + valorDeducao;

    // Exibe os dados do contribuinte
    printf("Seu cpf eh %s\n", cpf);
    printf("Seu nome eh: %s\n", nome);
    printf("Seu rendimento bruto eh: R$%.2f\n", rendimentoMensal);
    printf("O valor que voce contribui ao INSS eh: R$%.2f\n", contribuicaoInss);
    printf("Numero de dependentes seu eh: %d\n", dependentes);
    printf("O valor da deducao total eh: R$%.2f\n", totalDeducao);

    // Calcula a base de cálculo para o imposto (rendimento - deduções)
    baseCalculo = rendimentoMensal - totalDeducao;

    // Verifica se o contribuinte está isento de impostos (baseCalculo <= 2112.00)
    if (baseCalculo <= 2112.00)
    {
        printf("Voce esta isento de impostos!\n");  // Caso esteja isento
    }
    // Verifica se o contribuinte está na faixa 2 (2112.01 até 2826.65)
    else if (baseCalculo >= 2112.01 && baseCalculo <= 2826.65)
    {
        // Cálculo do imposto (faixa 2)
        imposto = (baseCalculo * faixa2) - 158.40;

        // Exibe os dados dessa faixa
        printf("Sua base de calculo eh: R$%.2f", baseCalculo);
        printf("Aliquota usada eh: 7.5%%\n");
        printf("Parcela a deduzir eh: R$158,40\n");
        printf("Valor total do imposto devido: R$%.2f\n", imposto);
    }
    // Verifica se o contribuinte está na faixa 3 (2826.66 até 3751.05)
    else if (baseCalculo >= 2826.66 && baseCalculo <= 3751.05)
    {
        // Cálculo do imposto (faixa 3)
        imposto = (baseCalculo * faixa3) - 370.40;

        // Exibe os dados dessa faixa
        printf("Sua base de calculo eh: R$%.2f\n", baseCalculo);
        printf("Aliquota usada eh: 15%%\n");
        printf("Parcela a deduzir eh: R$370,40\n");
        printf("Valor total do imposto devido: R$%.2f\n", imposto);
    }
    // Verifica se o contribuinte está na faixa 4 (3751.06 até 4664.68)
    else if (baseCalculo >= 3751.06 && baseCalculo <= 4664.68)
    {
        // Cálculo do imposto (faixa 4)
        imposto = (baseCalculo * faixa4) - 651.73;

        // Exibe os dados dessa faixa
        printf("Sua base de calculo eh: R$%.2f\n", baseCalculo);
        printf("Aliquota usada eh: 22.5%%\n");
        printf("Parcela a deduzir eh: R$651,73\n");
        printf("Valor total do imposto devido: R$%.2f\n", imposto);
    }
    // Caso não se encaixe nas faixas anteriores, está na faixa 5 (acima de 4664.68)
    else
    {
        // Cálculo do imposto (faixa 5)
        imposto = (baseCalculo * faixa5) - 884.96;

        // Exibe os dados dessa faixa
        printf("Sua base de calculo eh: R$%.2f\n", baseCalculo);
        printf("Aliquota usada eh: 27.5%%\n");
        printf("Parcela a deduzir eh: R$884,96\n");
        printf("Valor total do imposto devido: R$%.2f\n", imposto);
    }

    return 0;  // Finaliza o programa
}

// (2,5 pontos) Parcelamento Sem Juros. (Olimpíada Brasileira de Informática – OBI2019 – Prog. Nível Júnior –
// Fase Nacional) Pedrinho está implementando o sistema de controle de pagamentos parcelados de uma
// grande empresa de cartão de crédito digital. Os clientes podem parcelar as compras sem juros no
// cartão, em até 18 vezes. Quando o valor V da compra é divisível pelo número P de parcelas que o
// cliente escolhe, todas as parcelas terão o mesmo valor. Por exemplo, se o cliente comprar um livro
// de V = 30 reais em P = 6 vezes, então as parcelas terão valores: 5, 5, 5, 5, 5 e 5. Mas se o valor da
// compra não for divisível pelo número de parcelas será preciso fazer um ajuste, pois a empresa quer
// que todas as parcelas tenham sempre um valor inteiro e somem no total, claro, o valor exato da
// compra. O que Pedrinho decidiu foi distribuir o resto da divisão de V por P igualmente entre as
// parcelas iniciais. Por exemplo, se a compra for de V = 45 e o número de parcelas for P = 7, então as
// parcelas terão valores: 7, 7, 7, 6, 6, 6 e 6. Quer dizer, como o resto da divisão de 45 por 7 é 3, então
// as 3 parcelas iniciais devem ter valor um real maior do que as 4 parcelas finais. Você precisa ajudar
// Pedrinho e escrever um programa que, dado o valor da compra e o número de parcelas, imprima os
// valores de cada parcela.
// Entrada
// A primeira entrada representa o valor (V) da compra. A segunda entrada indica o número de parcelas
// (P).
// Saída
// Seu programa deve imprimir P números, cada um contendo um inteiro representando o valor de uma
// parcela. O i-ésimo número deve conter o valor da i-ésima parcela, para 1 ≤ i ≤ P, de acordo com o
// que Pedrinho decidiu.
// Restrições
// • 10 ≤ V ≤ 1000
// • 1 ≤ P ≤ 18
// Exemplos de Entrada    Exemplos de Saída

// 30, 6                     5, 5, 5, 5, 5, 5
// 45, 7                     7, 7, 7, 6, 6, 6, 6

// Declaração da função que calcula e exibe o valor das parcelas
void valorParcelas(int valueCompra, int numParcelas);

int main()
{
    int parcelas, valorCompra;

    // Solicita ao usuário o valor da compra
    printf("Digite o valor da compra:\n");
    scanf("%d", &valorCompra);

    // Solicita ao usuário o número de parcelas desejadas
    printf("Digite o numero de parcelas: \n");
    scanf("%d", &parcelas);

    // Chama a função que calcula e exibe as parcelas
    valorParcelas(valorCompra, parcelas);
}

// Função que calcula o valor de cada parcela
void valorParcelas(int valueCompra, int numParcelas)
{
    int valueBase, resto, i;

    // Calcula o valor base de cada parcela (parte inteira da divisão)
    valueBase = valueCompra / numParcelas;

    // Calcula o valor que sobra (resto da divisão), que será distribuído entre as primeiras parcelas
    resto = valueCompra % numParcelas;

    // Loop para imprimir o valor de cada parcela
    for (i = 0; i < numParcelas; i++)
    {
        if (i < resto)
        {
            // As primeiras 'resto' parcelas recebem +1 no valor base para distribuir o valor total igualmente
            printf("%d ", valueBase + 1);
        }
        else
        {
            // As demais parcelas recebem apenas o valor base
            printf("%d ", valueBase);
        }
    }
}

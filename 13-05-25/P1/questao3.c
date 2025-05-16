// (2,5 pontos) Exercício de História. (Maratona PUC Goiás #1) Após uma aula muito boa de história –
// sucedendo uma aula muito ruim de matemática – alguns alunos de uma determinada escola estão
// com dúvidas em um simples problema. A professora pediu que eles informassem o valor numérico
// (por simplicidade deve ser em decimal e em algarismos arábicos) do século de um determinado ano,
// mas como poucos alunos estavam acertando ela decidiu pediu sua ajuda para criar um programa que
// fizesse exatamente isso a fins educativos.
// Para quem não se lembra desta aula de história, o século 1, por exemplo, compreende os anos entre
// 1 e 100, o século 2 os anos entre 101 e 200, o século 3 os anos entre 201 e 300 e assim por diante.
// Entrada
// A entrada consiste em vários casos de teste e é terminada pelo valor 0. Cada caso de teste contém
// um único inteiro N (1 ≤ N ≤ 3000), que corresponde ao valor de algum ano que deve ser processado.
// Saída
// Para cada caso de teste, imprima uma única linha contendo o valor do século do ano
// correspondente.
// Exemplo de Entrada Exemplo de Saída
// 1                     1
// 999                   10
// 2000                  20
// 2001                  21

// Declaração da função que calcula o século a partir de um ano
int seculoAno(int ano);

int main()
{
    // Variável para controlar se o programa continua ou encerra,
    // ano para armazenar a entrada do usuário, seculo para armazenar o resultado
    int encerra = 1, ano, seculo;

    // Estrutura de repetição que continua enquanto 'encerra' for diferente de 0
    do
    {
        // Solicita que o usuário digite um ano
        printf("Digite um ano para saber o seculo: \n");
        scanf("%d", &ano); // Lê o valor digitado e armazena em 'ano'

        // Chama a função seculoAno passando o ano digitado e armazena o retorno em 'seculo'
        seculo = seculoAno(ano);

        // Mostra o século correspondente ao ano informado
        printf("O seculo de %d eh: %d\n", ano, seculo);

        // Pergunta ao usuário se deseja encerrar ou continuar
        printf("Para encerrar programa digite (0) ou 1 para continuar:\n");
        scanf("%d", &encerra); // Lê a resposta e atualiza a variável 'encerra'

    } while (encerra != 0); // Continua o loop se 'encerra' for diferente de 0

    // Mensagem de encerramento
    printf("Programa encerrado!");

    return 0; // Indica que o programa terminou com sucesso
}

// Função que calcula o século com base no ano fornecido
int seculoAno(int ano)
{
    int seculo;

    // Se o ano for múltiplo de 100, o século é o ano dividido por 100
    if (ano % 100 == 0)
    {
        seculo = ano / 100;
    }
    else
    {
        // Se não for múltiplo de 100, adiciona 1 ao resultado da divisão
        seculo = ano / 100 + 1;
    }

    return seculo; // Retorna o século calculado
}

//  Joãozinho quer
// calcular e mostrar a quantidade de litros de combustível gastos em uma viagem, ao utilizar um
// automóvel que faz 12 KM/L. Para isso, ele gostaria que você o auxiliasse através de um simples
// programa. Para efetuar o cálculo, deve-se fornecer o tempo gasto na viagem (em horas) e a
// velocidade média durante a mesma (em km/h). Assim, pode-se obter distância percorrida e, em
// seguida, calcular quantos litros seriam necessários. Mostre o valor com 3 casas decimais após o
// ponto.
// Entrada
// O arquivo de entrada contém dois inteiros. O primeiro é o tempo gasto na viagem (em horas) e o
// segundo é a velocidade média durante a mesma (em km/h).
// Saída
// Imprima a quantidade de litros necessária para realizar a viagem, com três dígitos após o ponto
// decimal
// Exemplo de Entrada          Exemplo de Saída
// 10, 85                      70.833
// 2, 92                       15.333
// 22, 67                      122.833

// Declaração da função que calcula a quantidade de combustível necessário
float qtdCombustivel(int tempoGasto, int velocidadeMedia);

int main()
{
    // Variável para armazenar o resultado (litros necessários)
    float litrosNecessarios;

    // Variáveis para tempo de viagem (em horas) e velocidade média (em km/h)
    int tempo, velocidade;

    // Solicita ao usuário que digite o tempo e a velocidade média
    printf("Ola Joaozinho, digite o tempo gasto na viagem (em horas) e a velocidade media que voce percorreu o percurso (em km):\n");
    scanf("%d %d", &tempo, &velocidade); // Lê os dois valores digitados

    // Chama a função que calcula o combustível necessário, passando tempo e velocidade
    litrosNecessarios = qtdCombustivel(tempo, velocidade);

    // Mostra o resultado com 3 casas decimais
    printf("A quantidade de litros necessarios para realizar a viagem sera de: %.3f\n", litrosNecessarios);
}

// Função que calcula a quantidade de combustível com base no tempo e na velocidade
float qtdCombustivel(int tempoGasto, int velocidadeMedia)
{
    // Calcula a distância percorrida
    float distancia = tempoGasto * velocidadeMedia;

    // Considerando que o carro faz 12 km por litro, retorna a quantidade de litros necessários
    return distancia / 12.0;
}

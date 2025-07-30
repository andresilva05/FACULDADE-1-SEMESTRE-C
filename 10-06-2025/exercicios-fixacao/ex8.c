#include <stdio.h>
#include <string.h>

#define LINHA 5
#define COLUNA 5
#define CIDADE 5

// Função que imprime os percursos com distância <= 250 km
void verificaDistancia(float distancia[LINHA][COLUNA], char cidades[CIDADE][20]);

// Função que calcula e imprime o consumo estimado para cada percurso
void calculaConsumo(float distancia[LINHA][COLUNA], char cidades[CIDADE][20], float kmPorLitro);

// Função que encontra e imprime o menor e o maior percurso
void mostraMaiorEMenorPercurso(float distancia[LINHA][COLUNA], char cidades[CIDADE][20]);

int main()
{
    char cidades[CIDADE][20];       // Vetor para armazenar os nomes das cidades
    float distancia[LINHA][COLUNA]; // Matriz para armazenar as distâncias entre as cidades
    float kmLitro;                  // Consumo do veículo (km por litro)
    int sair = 1;                   // Controle do loop do programa
    int i, j;

    printf("Abaixo digite o nome de 5 cidades\n");

    do
    {
        // Leitura dos nomes das cidades com fgets e remoção do '\n'
        for (i = 0; i < CIDADE; i++)
        {
            printf("Digite o nome da [%d] cidade: ", i + 1);
            fgets(cidades[i], 20, stdin);
            // Remove o '\n' que o fgets pode deixar no final da string
            cidades[i][strcspn(cidades[i], "\n")] = '\0';
        }

        // Preenchimento da matriz de distâncias
        for (i = 0; i < LINHA; i++)
        {
            for (j = 0; j < COLUNA; j++)
            {
                // Se for a mesma cidade, distância é zero automaticamente
                if (strcmp(cidades[i], cidades[j]) == 0)
                {
                    distancia[i][j] = 0;
                }
                else
                {
                    // Para evitar entrada duplicada, pede distância só para metade superior da matriz
                    if (i != j && i < j)
                    {
                        printf("Digite a distancia de %s ate %s: ", cidades[i], cidades[j]);
                        scanf("%f", &distancia[i][j]);
                        // Espelha o valor na posição simétrica para completar a matriz
                        distancia[j][i] = distancia[i][j];
                    }
                }
            }
        }

        // Leitura do consumo do veículo em km por litro
        printf("\nDigite quantos km seu automovel faz por litro: ");
        scanf("%f", &kmLitro);
        getchar(); // Limpa o '\n' do buffer antes do próximo fgets

        // Chamada das funções para mostrar resultados
        verificaDistancia(distancia, cidades);
        calculaConsumo(distancia, cidades, kmLitro);
        mostraMaiorEMenorPercurso(distancia, cidades);

        // Pergunta para o usuário se deseja continuar ou sair
        printf("\nDigite 0 para sair ou 1 para reiniciar o programa: ");
        scanf("%d", &sair);
        getchar(); // Limpa buffer antes do próximo fgets

    } while (sair != 0);

    return 0;
}

// Função que mostra os percursos cuja distância é menor ou igual a 250 km
void verificaDistancia(float distancia[LINHA][COLUNA], char cidades[CIDADE][20])
{
    int i, j;
    printf("\nPercursos com distância até 250 km:\n");
    for (i = 0; i < LINHA; i++)
    {
        for (j = i + 1; j < COLUNA; j++) // Começa de i+1 para evitar repetição e diagonal
        {
            if (distancia[i][j] <= 250)
            {
                printf("De %s até %s: %.2f km\n", cidades[i], cidades[j], distancia[i][j]);
            }
        }
    }
}

// Função que calcula e mostra o consumo de combustível para cada percurso
void calculaConsumo(float distancia[LINHA][COLUNA], char cidades[CIDADE][20], float kmPorLitro)
{
    int i, j;
    float consumo;
    printf("\nConsumo estimado de combustível para cada percurso:\n");
    for (i = 0; i < LINHA; i++)
    {
        for (j = i + 1; j < COLUNA; j++) // Mesma lógica para evitar repetição
        {
            consumo = distancia[i][j] / kmPorLitro;
            printf("De %s até %s: %.2f km e Consumo estimado: %.2f litros\n",
                   cidades[i], cidades[j], distancia[i][j], consumo);
        }
    }
}

// Função que encontra e mostra o menor e o maior percurso entre cidades diferentes
void mostraMaiorEMenorPercurso(float distancia[LINHA][COLUNA], char cidades[CIDADE][20])
{
    int i, j;
    int indiceMaiorI = 0, indiceMaiorJ = 1;
    int indiceMenorI = 0, indiceMenorJ = 1;
    float maiorPercurso = distancia[0][1];
    float menorPercurso = distancia[0][1];

    for (i = 0; i < LINHA; i++)
    {
        for (j = i + 1; j < COLUNA; j++)
        {
            if (distancia[i][j] > maiorPercurso)
            {
                maiorPercurso = distancia[i][j];
                indiceMaiorI = i;
                indiceMaiorJ = j;
            }
            if (distancia[i][j] < menorPercurso)
            {
                menorPercurso = distancia[i][j];
                indiceMenorI = i;
                indiceMenorJ = j;
            }
        }
    }

    printf("\nMaior percurso: %s até %s e %.2f km\n", cidades[indiceMaiorI], cidades[indiceMaiorJ], maiorPercurso);
    printf("Menor percurso: %s até %s e %.2f km\n", cidades[indiceMenorI], cidades[indiceMenorJ], menorPercurso);
}

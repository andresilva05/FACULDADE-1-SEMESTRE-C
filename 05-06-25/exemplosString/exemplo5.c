#include <stdio.h>
#include <string.h> // Para strcspn e strcpy

// Constantes
#define MAX_NOME_ALUNO 101      // 100 caracteres + \0

// Protótipos das funções
void limparBufferEntrada(void);

int main() {
    // Variáveis da disciplina e turma
    int quantidadeAlunos;

    // Variáveis para leitura dos alunos
    char nomeAlunoAtual[MAX_NOME_ALUNO];
    float notaUm;
 
    // Validação da quantidade de alunos
    do {
        printf("Digite a quantidade total de alunos na turma (deve ser maior que 0): ");
        scanf("%d", &quantidadeAlunos);
        limparBufferEntrada(); // Limpar o buffer após scanf
        if (quantidadeAlunos <= 0) {
            printf("Numero de alunos invalido. Por favor, insira um valor maior que 0.\n");
        }
    } while (quantidadeAlunos <= 0);

    // Loop para processar cada aluno
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("\n--- Dados do Aluno %d ---\n", i+1);
        printf("Nome completo do aluno: ");
        gets(nomeAlunoAtual);
     
        do {
            printf("Digite a primeira nota do aluno %s (entre 0 e 10): ", nomeAlunoAtual);
            scanf("%f", &notaUm);
            limparBufferEntrada();
            if (notaUm < 0 || notaUm > 10) {
                printf("Nota invalida! A nota deve estar entre 0 e 10.\n");
            }
        } while (notaUm < 0 || notaUm > 10);
    }
      return 0; // Indica que o programa terminou com sucesso
}

// Função para limpar o buffer de entrada (consome caracteres até '\n')
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta o caractere
    }
}
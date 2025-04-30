// 2. Exemplo Médio: Validar Senha
// Aqui, o programa vai pedir uma senha e só continuará quando o usuário inserir a senha correta. O loop vai continuar pedindo até que a senha seja válida.

#include <stdio.h>
#include <string.h>

int main() {
    char senha[20];

    // Senha correta
    const char senhaCorreta[] = "segredo123";

    do {
        printf("Digite a senha: ");
        scanf("%s", senha);  // Lê a senha

        // Verifica se a senha está correta
        if (strcmp(senha, senhaCorreta) != 0) {
            printf("Senha incorreta! Tente novamente.\n");
        }
    } while (strcmp(senha, senhaCorreta) != 0);

    printf("Senha correta! Acesso liberado.\n");
    return 0;
}

// Explicação:
// Esse exemplo usa o do...while para garantir que a senha seja pedida pelo menos uma vez, e se o usuário errar, o programa repete o pedido até ele acertar. Aqui, usamos a função strcmp para comparar a senha fornecida com a correta. 
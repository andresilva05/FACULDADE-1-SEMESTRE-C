// 📌 O que são Sub-rotinas (Funções)?
// São blocos de código que realizam uma tarefa específica e podem ser "chamados" sempre que precisar.

// Vantagens:

// Organiza melhor o código (modularização)

// Evita repetição

// Facilita a manutenção

// ✅ Tipos de Funções
// Função sem retorno (void)
// Não devolve nenhum valor para quem a chamou.

// Exemplo:

void saudacao() {
    printf("Olá!\n");
}

int main() {
    saudacao(); // chama a função
    return 0;
}

// Função com retorno (int, float, char, etc.)
// Retorna um valor específico.

// Exemplo:

int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = soma(3, 4); // resultado recebe 7
    printf("Resultado: %d\n", resultado);
    return 0;
}


// 🔁 Passagem de Parâmetros (por valor)
// A função recebe uma cópia dos valores.

// Alterações não afetam as variáveis originais do main.

// Exemplo: menor de dois números


int menor(int a, int b) {
    if (a < b) return a;
    else return b;
}

int main() {
    int x = 10, y = 5;
    printf("Menor: %d\n", menor(x, y)); // Saída: Menor: 5
    return 0;
}

// 🌍 Variáveis Locais vs Globais
// Local: criada dentro da função. Só existe ali.

// Global: criada fora de qualquer função. Pode ser usada em todo o programa.

int global = 10; // global

void mostrar() {
    int local = 5; // local
    printf("Global: %d, Local: %d\n", global, local);
}

// 🔧 Estrutura de uma Função

tipo_de_retorno nomeFuncao(parâmetros) {
    // variáveis locais
    // instruções
    return valor; // se tiver retorno
}

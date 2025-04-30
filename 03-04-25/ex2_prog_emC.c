

#include <stdio.h> // Biblioteca padrão para entrada e saída (printf, scanf)

int main()
{
    float num, frac; // Declara duas variáveis do tipo float para armazenar o número e sua parte fracionária
    int inteiro;     // Declara uma variável inteira para armazenar a parte inteira do número

    // Pede ao usuário para digitar um número
    printf("Digite um número: ");
    scanf("%f", &num); // Lê o número digitado e armazena na variável num

    inteiro = num;        // Atribui a parte inteira do número para a variável inteiro (conversão implícita de float para int)
    frac = num - inteiro; // Calcula a parte fracionária subtraindo a parte inteira do número total

    // Exibe o resultado na tela
    printf("A parte fracionaria de %f e' %f ", num, frac);

    return 0; // Retorna 0 indicando que o programa terminou corretamente
}

// Explicação Simples

// Imagina que você tem 3.75 chocolates 🍫.

// 1️⃣ O programa pergunta: "Qual número você quer?"

// Você digita 3.75

// 2️⃣ Ele separa o número em duas partes:

// Parte inteira → 3 ✅

// Parte decimal (fracionária) → 0.75 ✅

// 3️⃣ Ele faz isso assim:

// Guarda o número inteiro 3 dentro de uma "caixinha" chamada inteiro.

// Depois, ele faz a conta:

// 3.75 - 3 = 0.75
// Ou seja, ele pega o número total e tira a parte inteira, sobrando só o decimal.

// 4️⃣ No final, ele mostra na tela:

// A parte fracionaria de 3.750000 e' 0.750000
// 🛠 Testando com Outros Números
// 📌 Se você digitar 7.25, ele vai calcular:

// Parte inteira: 7

// Parte fracionária: 0.25

// 📌 Se você digitar 10.99, ele vai calcular:

// Parte inteira: 10

// Parte fracionária: 0.99
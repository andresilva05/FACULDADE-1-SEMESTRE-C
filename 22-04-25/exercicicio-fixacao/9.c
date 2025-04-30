// Exercício 9. Criar um programa em C que, a partir da idade e peso do paciente informado pelo
// usuário, calcule a dosagem de determinado medicamento e imprima a receita informando quantas
// gotas do medicamento o paciente deve tomar por dose. Considere que o medicamento em questão
// possui 500 mg por ml, e que cada ml corresponde a 20 gotas.
//  Adultos ou adolescentes desde 12 anos, inclusive, se tiverem peso igual ou acima de 60
// quilos devem tomar 1000 mg; com peso abaixo de 60 quilos devem tomar 875 mg.
//  Para crianças e adolescentes abaixo de 12 anos a dosagem é calculada pelo peso
// corpóreo conforme a tabela a seguir:
//  Use funções para os cálculos e conversões.

// Peso              	Dosagem
// 5 kg a 9 kg	         125 mg
// 9.1 kg a 16 kg	     250 mg
// 16.1 kg a 24 kg	     375 mg
// 24.1 kg a 30 kg	     500 mg
// Acima de 30 kg	     750 mg

// Definindo as dosagens conforme a faixa de peso infantil
int DOSE_5_A_9_KG = 125;
int DOSE_9_1_A_16_KG = 250;
int DOSE_16_1_A_24_KG = 375;
int DOSE_24_1_A_30_KG = 500;
int DOSE_ACIMA_30_KG = 750;

// Definindo dosagens para adultos e adolescentes >= 12 anos
int DOSE_ADULTO_PESO_MAIOR_IGUAL_60 = 1000;
int DOSE_ADULTO_PESO_MENOR_60 = 875;

// Protótipos das funções criadas
float calculaDosagem(int idade, float peso);
float converteGotas(float dosagemMg);

// Função para pedir as informações do usuário
// OBS: Usa ponteiros para modificar diretamente as variáveis idade e peso no main
void pedeInformacao(int *idade, float *peso)
{
    printf("Digite sua idade: \n");
    scanf("%d", idade);
    printf("Digite seu peso: \n");
    scanf("%f", peso);
}

int main()
{
    float peso, gotas, dosagemMg;
    int idade, encerra = 1;

    printf("Abaixo, irei lhe informar a quantidade de gotas que devera tomar do medicamento de acordo com sua idade e peso.\n\n");

    do
    {
        pedeInformacao(&idade, &peso); // Chamada da função para obter dados do usuário

        dosagemMg = calculaDosagem(idade, peso); // Cálculo da dosagem de acordo com idade e peso
        gotas = converteGotas(dosagemMg);         // Conversão da dosagem para número de gotas

        printf("Tendo %d anos e pesando %.2fkg, a dosagem do medicamento em mg eh: %dmg\n", idade, peso, (int)dosagemMg);
        printf("Voce tera que tomar %.2f gotas do medicamento.\n", gotas);

        printf("Digite 1 para continuar e 0 para encerrar programa!\n");
        scanf("%d", &encerra); // Opção de continuar ou encerrar o programa
    } while (encerra != 0);

    printf("Programa Encerrado!");
}

// Função que calcula a dosagem em mg com base na idade e peso do paciente
float calculaDosagem(int idade, float peso)
{
    int dosagem;

    if (idade >= 12) // Adultos ou adolescentes
    {
        if (peso >= 60)
        {
            dosagem = DOSE_ADULTO_PESO_MAIOR_IGUAL_60;
        }
        else
        {
            dosagem = DOSE_ADULTO_PESO_MENOR_60;
        }
    }
    else // Crianças e adolescentes abaixo de 12 anos
    {
        if (peso >= 5 && peso <= 9)
        {
            dosagem = DOSE_5_A_9_KG;
        }
        else if (peso > 9 && peso <= 16)
        {
            dosagem = DOSE_9_1_A_16_KG;
        }
        else if (peso > 16 && peso <= 24)
        {
            dosagem = DOSE_16_1_A_24_KG;
        }
        else if (peso > 24 && peso <= 30)
        {
            dosagem = DOSE_24_1_A_30_KG;
        }
        else if (peso > 30)
        {
            dosagem = DOSE_ACIMA_30_KG;
        }
    }

    return dosagem;
}

// Função que converte a dosagem em mg para quantidade de gotas
float converteGotas(float dosagemMg)
{
    float ml, gotas;

    ml = dosagemMg / 500; // Cada 500 mg corresponde a 1 ml
    gotas = ml * 20;      // Cada 1 ml tem 20 gotas

    return gotas;
}


// Comentário para o professor:
//
// Consegui fazer o exercício, mas precisei buscar informações e orientação do ChatGPT, 
// principalmente para entender o uso de ponteiros na função pedeInformacao(), sem que o mesmo me desse código.
// Tive dificuldade inicial para passar idade e peso para o main de forma correta sem usar ponteiros.
// Após esses ajustes, entendi melhor a lógica de passar valores por referência e a importância 
// de separar funções para deixar o código mais organizado.


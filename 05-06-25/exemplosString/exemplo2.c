#include <stdio.h>
int main()
{
    char frase[40], mensagem[40] = "Digite uma frase: ";
    printf("%s", mensagem);
    scanf("%s", frase);
    printf("A frase digitada foi: %s \n", frase);
    return 0;
}

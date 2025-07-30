#include <stdio.h>
#include <string.h>

#define TAM 100

int main(){
   char texto[TAM];
   char l1, l2;

   printf("digite um texto: ");
   gets(texto);

   printf("digite uma letra: ");
   scanf(" %c",&l1);

   printf("digite outra letra: ");
   scanf(" %c",&l2);
 
   for(int i=0; i<TAM; i++)
     if( texto[i] == l1) 
        texto[i] = l2;

   printf("%s", texto);
   return(0);
}
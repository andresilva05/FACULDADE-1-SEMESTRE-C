#include <stdio.h>
#include <string.h>
#include "data.c"
#include "utils.c"
#include "datatype.h"

int main(){
    ListaDeContatos agenda;
    for(int i = 0;i<TAM_AGENDA;i++){
        printf("\n Entre com o nome: ");
        // fgets(agenda.contato[i].nome, TAM_NOME, stdin); // Lê a linha inteira
        // Remove o '\n' que o fgets pode deixar no final
        // agenda.contato[i].nome[strcspn(agenda.contato[i].nome, "\n")] = '\0'; 
        // ou... use o gets
        gets(agenda.contato[i].nome);
        printf("\n Entre com a data de nascimento: ");
        agenda.contato[i].dataDeNascimento = lerData();
        limparBufferEntrada();       
        printf("\n Entre com o email: ");
        gets(agenda.contato[i].email);
       //  limparBufferEntrada();
    }
    
    // Exibe os elementos da agenda
    printf("\n\n Agenda");
    for(int i = 0;i<TAM_AGENDA;i++){
        printf("\n (%d) Nome: %s, ", i+1, agenda.contato[i].nome);
        printf("Data de nascimento: ");
        imprimirData(agenda.contato[i].dataDeNascimento);
        printf(" Email: %s ", agenda.contato[i].email);
    }

}


#ifndef SORTEIO_H
#define SORTEIO_H

#define TAM 16

// Declaração das funções utilizadas no código
void menu();
int gerarNumeroAleatorio();
void SelectionSort(int numeros[]);             // Função para ordenar o vetor (Selection Sort)
void exibirVetor(int vetor[]);                 // Função para exibir o vetor na tela
int PesqSeq(int numeros[], int numeroUsuario); // Função para busca sequencial
int PesqBin(int numeros[], int numeroUsuario); // Função para busca binária
void armazenaNumeroAleatorio(int vetor[]);     // Função para gerar e armazenar números aleatórios no vetor

#endif

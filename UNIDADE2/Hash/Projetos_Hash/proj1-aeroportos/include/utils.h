#ifndef UTILS_H
#define UTILS_H
#include "aeroporto.h"

void menu();
int e_primo(int);
int primo(int); //Retorna o maior primo menor ou igual a n
int pertinencia(int, int*, int);
int num_chave(const char*); //Retorna o valor numérico associado ao código (chave)
void inserirOrdenado(int, Aeroporto*, Aeroporto); //Inserir elemento de forma ordenada em um vetor
int buscaBinaria(int, Aeroporto*, const char*);

#endif
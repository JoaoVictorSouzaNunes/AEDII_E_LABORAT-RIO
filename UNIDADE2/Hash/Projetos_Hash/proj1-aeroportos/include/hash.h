#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "lista.h"

typedef struct {
    Lista **tabela;
    int tamanho;
    int ocupacao;
    int qtd;
} HashTable;


HashTable* criarHashTable(int);
int hashFunction(const char*, int); //Método da divisão
void inserirHash(HashTable*, Aeroporto);
No* buscarHash(HashTable*, const char*);
void removerHash(HashTable*, const char*);
void exibirTabela(HashTable*);

#endif
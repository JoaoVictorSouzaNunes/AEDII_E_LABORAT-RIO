#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "lista.h"

typedef struct {
    Lista **tabela;
    int tamanho;
    int ocupacao;
    int qtd;
} HashTable;


HashTable* criarHashTable(int tamanho);
int hashFunction(const char *codigo, int tamanho);
void inserirHash(HashTable *ht, Aeroporto aeroporto);
No* buscarHash(HashTable *ht, const char *codigo);
void removerHash(HashTable *ht, const char *codigo);
void exibirTabela(HashTable *ht);

#endif // HASHTABLE_H
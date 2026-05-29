// Hash com tratamento de colisão por encadeamento
#include <stdlib.h>
#include "hashFunction.c"
typedef struct no {
    Aluno A;
    struct no *prox;
} No;
typedef struct HashTable {
    No *tabela[100];
} HashTable;
void initHashTable(HashTable *ht) {
    for (int i = 0; i < 100; i++) {
        ht->tabela[i] = NULL;
    }
}
void inserir(HashTable *ht, Aluno A) {
    int index = hashFunction(A);
    No *novo = (No *)malloc(sizeof(No));
    novo->A = A;
    novo->prox = ht->tabela[index];
    ht->tabela[index] = novo;
    printf("%d\n", index);
}

#include <stdio.h>
#include <stdlib.h>
#include "../include/hashtable.h"

HashTable* criarHashTable(int tamanho) {
    HashTable *ht = (HashTable*) malloc(sizeof(HashTable));
    ht->tamanho = tamanho;
    ht->ocupacao = 0;
    ht->qtd = 0;
    ht->tabela = (Lista**) malloc(tamanho * sizeof(Lista*));
    for (int i = 0; i < tamanho; i++) {
        ht->tabela[i] = NULL;
    }
    return ht;
}


//método da divisão
int hashFunction(const char *codigo, int tamanho) {
    int hash = 0;
    for (int i = 0; codigo[i] != '\0'; i++) {
        hash = hash + codigo[i];
    }
    hash = hash % tamanho;
    return hash;
}

void inserirHash(HashTable *ht, Aeroporto aeroporto) {
    int index = hashFunction(aeroporto.codigo, ht->tamanho);
    if (ht->tabela[index] == NULL) {
        ht->tabela[index] = criarLista();
        ht->ocupacao++;
    }
    inserirLista(ht->tabela[index], aeroporto);
    ht->qtd++;
}

No* buscarHash(HashTable *ht, const char *codigo) {
    int index = hashFunction(codigo, ht->tamanho);
    if (ht->tabela[index] != NULL) {
        return buscarLista(*ht->tabela[index], codigo);
    }
    return NULL;
}

void removerHash(HashTable *ht, const char *codigo) {
    int index = hashFunction(codigo, ht->tamanho);
    removerLista(ht->tabela[index], codigo);
    if(ht->tabela[index] != NULL && listaVazia(*ht->tabela[index])) {
        free(ht->tabela[index]);
        ht->tabela[index] = NULL;
        ht->ocupacao--;
    }
    ht->qtd--;
}

void exibirTabela(HashTable *ht) {
    for (int i = 0; i < ht->tamanho; i++) {
        printf("[%d]", i);
        if(ht->tabela[i] != NULL) {
            exibirLista(*ht->tabela[i]);
        } else {
            printf("\n");
        }
    }
}


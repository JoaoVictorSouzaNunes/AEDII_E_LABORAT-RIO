#include "aluno.c"
#include "hashFunction.c"
#include <stdlib.h>
typedef struct hashTable {
    Aluno *tabela;
} HashTable;
void initHashtable(HashTable *ht) {
    ht->tabela = malloc(100 * sizeof(Aluno));
    for (int i = 0; i < 100; i++) {
        ht->tabela[i].matricula = -1;
    }
}
void inserir(HashTable *ht, Aluno A) {
    int x = hashFunction(A);
    int o = x;
    while (ht->tabela[x].matricula != -1) {
        x = (x + 1) % 100;
        if (x == o) {
            return;
        }
    }
    ht->tabela[x] = A;
}

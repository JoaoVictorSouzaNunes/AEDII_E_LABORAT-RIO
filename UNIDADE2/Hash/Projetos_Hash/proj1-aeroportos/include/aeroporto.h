#ifndef AEROPORTO_H
#define AEROPORTO_H

#include <stdio.h>
#include "hashtable.h"

HashTable* lerArquivo(FILE *file, HashTable *ht);
void buscarAeroporto(HashTable *ht);
void status(HashTable *ht);
void removerAeroporto(HashTable *ht);

#endif


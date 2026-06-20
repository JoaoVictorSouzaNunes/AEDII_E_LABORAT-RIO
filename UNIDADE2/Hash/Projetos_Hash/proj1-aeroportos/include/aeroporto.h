#ifndef AEROPORTO_H
#define AEROPORTO_H

#include <stdio.h>
#include "hash.h"

HashTable* lerArquivo(FILE*, HashTable*);
void buscarAeroporto(HashTable*);
void status(HashTable*);
void removerAeroporto(HashTable*);

#endif


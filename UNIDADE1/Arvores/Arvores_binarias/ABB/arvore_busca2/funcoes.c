#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    }
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

No *inserirTodos(No *raiz, int *valores, int n) {
    for(int i=0; i<n; i++) {
        raiz=inserir(raiz, valores[i]);
    }
    return raiz;

}

int nivel(No *raiz, int valor, int atual) {
    if(raiz==NULL) { return -1;}
    if(raiz->valor==valor) { return atual; }
    int nivelesq=nivel(raiz->esq, valor, atual+1);
    if(nivelesq!=-1) { return nivelesq; }
    return nivel(raiz->dir, valor, atual+1);
}

No *buscar(No *raiz, int valor) {
    if(raiz==NULL) return raiz;
    else if(raiz->valor==valor) return raiz;
    else {
        if(valor>raiz->valor) {
            return buscar(raiz->dir, valor);
        } else {
            return buscar(raiz->esq, valor);
        }
    }
}


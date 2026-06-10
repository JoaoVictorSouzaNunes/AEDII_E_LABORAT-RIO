#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista* criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

int listaVazia(Lista lista) {
    return lista.inicio == NULL;
}

void inserirLista(Lista *plista, Aeroporto aeroporto) { //inserir no inicio da lista
    No *novo = (No*) malloc(sizeof(No));
    novo->aeroporto = aeroporto;
    novo->prox = plista->inicio;
    plista->inicio = novo;
    plista->tam++;
}

No* buscarLista(Lista lista, const char *codigo) {
    No *aux = lista.inicio;
    while(aux != NULL && strcmp(aux->aeroporto.codigo, codigo) != 0) {
        aux = aux->prox;
    }
    return aux;
}

void removerLista(Lista *plista, const char *codigo) {
    No *aux, *remove = NULL;
    if(!listaVazia(*plista)) {
        if(strcmp(plista->inicio->aeroporto.codigo, codigo) == 0) {
            remove = plista->inicio;
            plista->inicio = remove->prox;
            plista->tam--;
        } else {
            aux = plista->inicio;
            while(aux->prox != NULL && strcmp(aux->prox->aeroporto.codigo, codigo) != 0) {
                aux = aux->prox;
            }
            if(aux->prox != NULL) {
                remove = aux->prox;
                aux->prox = remove->prox;
                plista->tam--;
            }
        }
    }
    free(remove);
}

void exibirLista(Lista lista) {
    No *aux = lista.inicio;
    while(aux != NULL) {
        printf(" --> [%s]", aux->aeroporto.codigo);
        aux = aux->prox;
    }
    printf("\n");
}
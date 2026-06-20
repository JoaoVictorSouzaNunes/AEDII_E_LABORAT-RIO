#ifndef LISTA_H
#define LISTA_H

typedef struct {
    char codigo[4]; // Código IATA de 3 letras + '\0'
    char nome[100];
    char cidade[50];
    char pais[50];
} Aeroporto;

typedef struct no{
    Aeroporto aeroporto;
    struct no *prox;
}No;

typedef struct {
    No *inicio;
    int tam;
}Lista;

Lista* criarLista();
int listaVazia(Lista);
void inserirLista(Lista*, Aeroporto);
No* buscarLista(Lista, const char*);
No* removerLista(Lista*, const char*);
void exibirLista(Lista);

#endif
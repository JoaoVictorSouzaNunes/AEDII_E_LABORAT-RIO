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
int listaVazia(Lista lista);
void inserirLista(Lista *plista, Aeroporto aeroporto);
No* buscarLista(Lista lista, const char *codigo);
No* removerLista(Lista *plista, const char *codigo);
void exibirLista(Lista lista);

#endif // LISTA_H
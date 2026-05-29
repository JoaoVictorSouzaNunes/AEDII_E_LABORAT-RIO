#include "funcoes.c"

int main() {
    No *raiz=NULL;
    raiz=inserir(raiz, 50);
    raiz=inserir(raiz, 30);
    raiz=inserir(raiz, 80);
    raiz=inserir(raiz, 10);
    raiz=inserir(raiz, 40);
    raiz=inserir(raiz, 60);
    raiz=inserir(raiz, 90);
    pre_ordem(raiz);
    printf("Altura da raiz: %d\n", altura(raiz));
}

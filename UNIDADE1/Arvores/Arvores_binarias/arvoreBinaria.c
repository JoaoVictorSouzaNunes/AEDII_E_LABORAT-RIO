#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No *criarNo(int valor) {
    No *raiz=(No *)malloc(sizeof(No));
    raiz->esq=NULL;
    raiz->dir=NULL;
    raiz->valor=valor;
    return raiz;
}
void adicionarFilhos(No *pai, No *esq, No *dir) {
    pai->esq=esq;
    pai->dir=dir;
}


int main() {
    No *raiz=criarNo(50);
    No *f1=criarNo(30);
    No *f2=criarNo(80);
    No *f3=criarNo(10);
    No *f4=criarNo(40);
    No *f5=criarNo(60);
    No *f6=criarNo(90);
    adicionarFilhos(raiz, f1, f2);
    adicionarFilhos(f1, f3, f4);
    adicionarFilhos(f2, f5, f6);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No *criarNo(int valor)
{
    No *raiz = (No *)malloc(sizeof(No));
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->valor = valor;
    return raiz;
}

No *inserir(No *pai, int valor)
{
    if (pai == NULL)
        return criarNo(valor);
    if (valor > pai->valor)
    {
        pai->dir = inserir(pai->dir, valor);
    }
    else
    {
        pai->esq = inserir(pai->esq, valor);
    }
    return pai;
}

int maior(int a, int b)
{
    return a > b ? a : b;
}

int altura(No *raiz)
{
    if (raiz == NULL)
        return -1;
    int hEsq = altura(raiz->esq);
    int hDir = altura(raiz->dir);
    return maior(hEsq, hDir) + 1;
}

void pre_ordem(No *pai)
{
    if (pai == NULL)
        return;
    printf("%d\n", pai->valor);
    pre_ordem(pai->esq);
    pre_ordem(pai->dir);
}

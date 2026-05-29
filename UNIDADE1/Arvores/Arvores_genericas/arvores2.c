#include <stdlib.h>
#define MAX 10
typedef struct no {
    int valor;
    int nfilhos;
    struct no *filhos[MAX];
} No;
No *criarNo(int);
No *addfilho(No*, No*);
void freeTree(No*);
void visualiza01(No*);
void visualiza02(No*);
int main() {
    No *raiz=criarNO(1), *todos[5]={criarNo(3), criarNo(2), criarNo(5), criarNo(4), criarNo(5)};
    addfilho(raiz, todos[0]), addfilho(raiz, todos[1]), addfilho(raiz, todos[2]), addfilho(todos[0], todos[3]), addfilho(todos[0], todos[4]);

    visualiza01(raiz);
    printf("\n");
    visualiza02(raiz);
    return 0;
}
No *criarNo(int valor) {
    No *r=malloc(sizeof(No));
    r->valor=valor;
    r->nfilhos=0;
    return r;
}
No *addfilho(No *pai, No *filho) {
    if(pai->nfilhos<MAX) {
        pai->filhos[pai->nfilhos++]=filho; //a variavel nfilhos é incrementada APÓS a atribuicao
        return pai;
    } else {
        return NULL;
    }
}
void freeTree(No *raiz) {
    if(!raiz) return;
    for(int i=0; i<raiz->nfilhos; i++) {
        freeTree(raiz->filhos[i]);
    }
    free(raiz);
}
void visualiza01(No *raiz) {
    if(raiz==NULL) { return; }
    for(int i=0; i<raiz->nfilhos; i++) {
        visualiza01(raiz->filhos[i]);
    }
    printf("%d ", raiz->valor);
}
void visualiza02(No *raiz) {
    if(raiz==NULL) { return; }
    printf("%d ", raiz->valor);
    for(int i=0; i<raiz->nfilhos; i++) {
        visualiza02(raiz->filhos[i]);
    }
}

#include <stdlib.h>
typedef struct no {
    int valor;
    int nfilhos;
    struct no *filhos[10];
} No;

int main() {
    No *raiz=malloc(sizeof(No));
    raiz->valor=1;
    raiz->nfilhos=3;

    No *filho1=malloc(sizeof(No));
    filho1->valor=3;
    filho1->nfilhos=2;

    No *filho2=malloc(sizeof(No));
    filho2->valor=2;
    filho2->nfilhos=0;

    No *filho3=malloc(sizeof(No));
    filho3->valor=5;
    filho3->nfilhos=0;

    No *neto1=malloc(sizeof(No));
    neto1->valor=4;
    neto1->nfilhos=0;

    No *neto2=malloc(sizeof(No));
    neto2->valor=5;
    neto2->nfilhos=0;

    raiz->filhos[0]=filho1;
    raiz->filhos[1]=filho2;
    raiz->filhos[2]=filho3;

    filho1->filhos[0]=neto1;
    filho1->filhos[1]=neto2;

    return 0;
}

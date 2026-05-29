#include "funcoes.c"

int main() {
    No *raiz=NULL;
    int valores[] = {50, 30, 80, 10, 40, 60, 90};
    raiz=inserirTodos(raiz, valores, 7);

    int valorBusca = 40;
    No *resultado = buscar(raiz, valorBusca);
    if(resultado!=NULL) {
        printf("Valor %d encontrado no nível %d\n", valorBusca, nivel(raiz, valorBusca, 0));
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }
    return 0;
}
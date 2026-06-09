#include <stdio.h>
#include <math.h>
#include "utils.h"

void menu() {
    printf("=========== SISTEMA ===========\n");
    printf("1. Buscar Aeroporto\n");
    printf("2. Exibir Tabela\n");
    printf("3. Status\n");
    printf("4. Remover Aeroporto\n");
    printf("0. Sair\n");
}


int e_primo(int n) {
    int raiz = sqrt(n);
    for(int i=2; i<=raiz; i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

//Retorna o maior primo menor ou igual a n
int primo(int n) {
    int m=1;
    for(int i=2; i<=n; i++) {
        if(e_primo(i)&&i>m) {
            m=i;
        }
    }
    return m;
}

int pertinencia(int n, int *f, int valor) {
    for(int i=0; i<n; i++) {
        if(f[i] == valor) {
            return 1;
        }
    }
    return 0;
}

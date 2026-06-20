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
    for(int i = 2; i <= raiz; i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int primo(int n) {
    int m = 1;
    for(int i = 2; i <= n; i++) {
        if(e_primo(i)&&i>m) {
            m = i;
        }
    }
    return m;
}

int pertinencia(int n, int *f, int valor) {
    for(int i = 0; i < n; i++) {
        if(f[i] == valor) {
            return 1;
        }
    }
    return 0;
}

int num_chave(const char *codigo) {
    int chave=0;
    for(int i=0; codigo[i]!='\0'; i++) {
        chave+=codigo[i];
    }
    return chave;
}

void inserirOrdenado(int n, Aeroporto *v, Aeroporto aeroporto) {
    int i;
    for(i=n-1; i>0&&num_chave(aeroporto.codigo)<num_chave(v[i].codigo); i--) {
        v[i+1]=v[i];
    }
    v[i+1]=aeroporto;
}

int buscaBinaria(int n, Aeroporto *v, const char *codigo) {
    int meio, inicio=0;
    int fim=n-1;
    int m=num_chave(v[meio].codigo);
    int x=num_chave(codigo);
    while(inicio<=fim) {
        meio=(inicio+fim)/2;
        if(m==x) {
            return meio;
        } else {
            if(m>x) {
                fim=meio-1;
            } else {
                inicio=meio+1;
            }
        }
    }
    return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aeroporto.h"
#include "utils.h"

int main() {

    FILE *file = fopen("./data/testes.txt", "r");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int i, j, n=20;
    char teste[n][4];
    for(i=0; i<n; i++) {
        fscanf(file, "%s\n", teste[i]);
        teste[i][3] = '\0';
    }

    fclose(file);

    file = fopen("./data/aeroportos.txt", "r");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    HashTable *tabela = criarHashTable(31);
    lerArquivo(file, tabela);

    Aeroporto *vetor = (Aeroporto*) malloc((tabela->qtd) * sizeof(Aeroporto));
    Aeroporto aeroporto;
    while(fscanf(file, "%[^;];%[^;];%[^;];%[^;\n]\n", aeroporto.codigo, aeroporto.nome, aeroporto.cidade, aeroporto.pais) == 4) {
        inserirOrdenado(tabela->qtd, vetor, aeroporto);
    }

    fclose(file);

    clock_t t, t_medio1=0, t_medio2=0;
    for(i=0; i<n; i++) {
        t=clock();
        for(j=0; j<10000000; j++) {
            buscaBinaria(tabela->qtd, vetor, teste[i]);
        }
        t=clock()-t;
        t_medio1+=t;
        printf("Tempo da busca (bem sucedida) em vetor ordenado: %.12lf segundos\n", ((double)t)/(j*CLOCKS_PER_SEC));

        t=clock();
        for(j=0; j<10000000; j++) {
            buscarHash(tabela, teste[i]);
        }
        t=clock()-t;
        t_medio2+=t;
        printf("Tempo da busca (bem sucedida) em hash com lista encadeada: %.12lf segundos\n\n", ((double)t)/(j*CLOCKS_PER_SEC));
    }

    printf("\nTempo medio da busca em vetor ordenado: %.12lf segundos\n", ((double)t_medio1)/(j*CLOCKS_PER_SEC));
    printf("Tempo medio da busca em hash com lista encadeada: %.12lf segundos\n", ((double)t_medio2)/(j*CLOCKS_PER_SEC));
    t_medio2=(t_medio1-t_medio2);
    printf("A hash e %.1lf%% mais eficiente", ((double)t_medio2)/t_medio1*100);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "utils.h"

int main() {
    FILE *file = fopen("./data/testes.txt", "r");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //37/2 == 18 e 2*37 == 74
    int n1=18, n2=74, n=20;
    char teste[n][4];
    int h, num_ocupados, colisoes[n2];
    float media_colisoes;

    for(int i=0; i<n2; i++) {
        fscanf(file, "%s\n", teste[i]);
        teste[i][3] = '\0';
    }
    fclose(file);
    for(int i=n1; i<=n2; i++) {
        if(e_primo(i)) {
            memset(colisoes, -1, sizeof(int)*i);
            media_colisoes=0;
            num_ocupados=0;

            printf("Tamanho da tabela: %d\n", i);
            for(int j=0; j<n; j++) {
                h = hashFunction(teste[j], i);
                colisoes[h]++;
            }

            for(int j=0; j<i; j++) {
                printf("Index: %d\n", j);
                if(colisoes[j] == -1) {
                    printf("  Vazio\n");
                } else {
                    printf("  Colisoes: %d\n", colisoes[j]);
                    media_colisoes += colisoes[j];
                    num_ocupados++;
                }
            }
            printf("Total de colisoes: %.0f\n", media_colisoes);
            media_colisoes /= num_ocupados;
            printf("Media de colisoes (por endereco): %.2f\n\n", media_colisoes);
        }
    }
    
    return 0;
}
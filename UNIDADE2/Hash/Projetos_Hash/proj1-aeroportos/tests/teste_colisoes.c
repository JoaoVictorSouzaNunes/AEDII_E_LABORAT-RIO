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
    float ocupacao, media_colisoes;

    for(int i=0; i<n; i++) {
        fscanf(file, "%s\n", teste[i]);
        teste[i][3] = '\0';
    }
    fclose(file);

    file=fopen("./data/input.txt", "w");
    for(int i=n1; i<=n2; i++) {
        if(e_primo(i)) {
            memset(colisoes, -1, sizeof(int)*i);
            media_colisoes=0;
            num_ocupados=0;
            ocupacao=0;

            fprintf(file, "Tamanho da tabela: %d\n", i);
            for(int j=0; j<n; j++) {
                h = hashFunction(teste[j], i);
                colisoes[h]++;
            }

            for(int j=0; j<i; j++) {
                fprintf(file, "Index: %d\n", j);
                if(colisoes[j] == -1) {
                    fprintf(file, "  Vazio\n");
                } else {
                    fprintf(file, "  Colisoes: %d\n", colisoes[j]);
                    media_colisoes += colisoes[j];
                    num_ocupados++;
                    ocupacao++;
                }
            }
            fprintf(file, "Total de colisoes: %.0f\n", media_colisoes);
            media_colisoes /= num_ocupados;
            fprintf(file, "Media de colisoes (por endereco): %.2f\n\n", media_colisoes);
            ocupacao /= i;
            fprintf(file, "Ocupacao: %.2f%%\n\n", ocupacao*100.0);
        }
    }
    fclose(file);
    
    return 0;
}
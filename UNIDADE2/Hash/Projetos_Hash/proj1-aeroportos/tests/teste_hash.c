#include <stdio.h>
#include "hash.h"
#include "utils.h"

int main() {
    FILE *file = fopen("./data/testes.txt", "r");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int n=20;
    char teste[n][4];
    int tam, colisoes, h[n];
    float ocupacao;
    for(int i=0; i<n; i++) {
        fscanf(file, "%s\n", teste[i]);
        teste[i][3] = '\0';
    }
    fclose(file);
    for(int i=20; i<100; i+=20) {
        tam=primo(i);
        printf("Tamanho da tabela: %d\n", tam);
        ocupacao=0;
        colisoes=0;
        for(int j=0; j<n; j++) {
            h[j] = hashFunction(teste[j], tam);
            printf("%s --> index: %d\n", teste[j], h[j]);
            if(j==0||(!pertinencia(j-1, h, h[j]))) {
                ocupacao++;
            } else {
                colisoes++;
            }
        }
        ocupacao/=i;
        printf("Ocupacao: %.2f%%\n", ocupacao*100.0);
        printf("Colisoes: %d\n\n", colisoes);
    }
    return 0;
}
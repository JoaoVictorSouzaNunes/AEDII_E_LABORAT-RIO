#include <stdio.h>
#include "hash.h"
#include "utils.h"

int main() {
    FILE *file = fopen("./data/testes.txt", "r");
    
    char teste[20][4];
    int tam, h[20];
    float ocupacao;
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    for(int i=0; i<20; i++) {
        fscanf(file, "%s\n", teste[i]);
        teste[i][3] = '\0';
    }
    fclose(file);
    for(int i=20; i<100; i+=20) {
        tam=primo(i);
        printf("Tamanho da tabela: %d\n", tam);
        ocupacao=0;
        for(int j=0; j<20; j++) {
            h[j] = hashFunction(teste[j], tam);
            printf("%s --> index: %d\n", teste[j], h[j]);
            if(j==0||(!pertinencia(j-1, h, h[j]))) {
                ocupacao++;
            }
        }
        ocupacao/=i;
        printf("Ocupacao: %.2f%%\n\n", ocupacao*100.0);
    }
    return 0;
}
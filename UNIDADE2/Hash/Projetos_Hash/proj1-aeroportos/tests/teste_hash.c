#include <stdio.h>
#include "hash.h"
#include "utils.h"

int main() {
    FILE *file = fopen("./data/teste.txt", "r");
    char teste[20][3];
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    for (int i = 0; i < 20; i++) {
        fscanf(file, "%[^;] %[^\n]\n", teste[i]);
    }
    fclose(file);
    for(int i=0; i<20; i++) {
        for(int j=20; j<100; j=j+20) {
            printf("Tamanho da tabela: %d\n", j);
            int h=hashfunction(teste[i], j);
            printf("%s --> index: %d\n", teste[i], h);
        }
    }

    return 0;
}
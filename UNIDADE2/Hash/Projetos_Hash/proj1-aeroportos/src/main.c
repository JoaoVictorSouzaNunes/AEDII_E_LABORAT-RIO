#include <stdio.h>
#include "aeroporto.h"
#include "utils.h"

int main() {
    FILE *file = fopen("./data/aeroportos.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    HashTable *ht=criarHashTable(100);
    lerArquivo(file, ht);
    fclose(file);
    int op;
    do {
        menu();
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                buscarAeroporto(ht);
                break;
            case 2:
                exibirTabela(ht);
                break;
            case 3:
                status(ht);
                break;
            case 4:
                removerAeroporto(ht);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 0);
    return 0;
}
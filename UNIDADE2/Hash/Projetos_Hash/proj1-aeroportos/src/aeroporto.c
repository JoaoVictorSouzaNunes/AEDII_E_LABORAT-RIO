#include "aeroporto.h"

HashTable* lerArquivo(FILE *file, HashTable *ht) {
    Aeroporto aeroporto;
    while (fscanf(file, "%[^;];%[^;];%[^;];%[^;\n]\n", aeroporto.codigo, aeroporto.nome, aeroporto.cidade, aeroporto.pais) == 4) {
        inserirHash(ht, aeroporto);
    }
    return ht;
}

void buscarAeroporto(HashTable *ht) {
    char codigo[4];
    printf("Digite o codigo do aeroporto: ");
    scanf("%s", codigo);
    No *resultado = buscarHash(ht, codigo);
    if (resultado != NULL) {
        Aeroporto a = resultado->aeroporto;
        printf("Codigo: %s, Nome: %s, Cidade: %s, Pais: %s\n", a.codigo, a.nome, a.cidade, a.pais);
    } else {
        printf("Aeroporto nao encontrado.\n");
    }
}

void status(HashTable *ht) {
    printf("Tamanho da tabela: %d\n", ht->tamanho);
    printf("Numero de aeroportos: %d\n", ht->qtd);
    printf("Taxa de ocupacao: %d%%\n", ht->ocupacao*100/ht->tamanho);
    printf("Numero de colisoes: %d\n\n", ht->qtd - ht->ocupacao);
}

void removerAeroporto(HashTable *ht) {
    char codigo[4];
    printf("Digite o codigo do aeroporto a ser removido: ");
    scanf("%s", codigo);
    removerHash(ht, codigo);
}

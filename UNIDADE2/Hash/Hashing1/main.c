#include "hashtable2.c"
int main() {
    HashTable ht;
    initHashTable(&ht);
    Aluno A1 = {"João", 10, 'A'};
    Aluno A2 = {"Pedro", 20, 'A'};
    Aluno A3 = {"João", 30, 'B'};
    Aluno A4 = {"João", 30, 'C'};
    inserir(&ht, A1);
    inserir(&ht, A2);
    inserir(&ht, A3);
    inserir(&ht, A4);
    return 0;
}
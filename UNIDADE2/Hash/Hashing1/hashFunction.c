#include "aluno.c"
#include <stdio.h>
int hashFunction(Aluno A) {
    int hash = 0;
    for (int i = 0; A.nome[i] != '\0'; i++) {
        hash += A.nome[i];
    }
    return hash % 100;
}
void mostrarAluno(Aluno a) {
    printf("Nome: %s\nMatrícula: %d\nTurma: %c\n", a.nome, a.matricula, a.turma);
}
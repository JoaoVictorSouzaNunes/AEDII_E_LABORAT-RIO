#include<stdio.h>
#include "estrutura01.c"
#include "estrutura02.c"

int main(){
    int x1 = sizeof(struct estrutura01);
    int x2 = sizeof(struct estrutura02);
    printf("\nEstrutura 01: %d\nEstrutura 02: %d\n", x1, x2);
}

#include <stdio.h>

int main() {
    int a, b; //4 bytes --> 32 bits (0 e 1)
    a=1; //0000 0000 0000 0000 0000 0000 0000 0001
    printf("a = %d\n", a);
    b=a<<1; //0000 0000 0000 0000 0000 0000 0000 0010 = 2
    printf("Deslocamento de 1 bit a esquerda: b = %d\n", b);
    b=a<<2; //0000 0000 0000 0000 0000 0000 0000 0100 = 4
    printf("Deslocamento de 2 bits a esquerda: b = %d\n", b);
    a=10; //0000 0000 0000 0000 0000 0000 0000 1010
    printf("a = %d\n", a);
    b=a>>1; //0000 0000 0000 0000 0000 0000 0000 0101 = 5
    printf("Deslocamento de 1 bit a direita: b = %d\n", b);
    b=a>>2; //0000 0000 0000 0000 0000 0000 0000 0010 = 2
    printf("Deslocamento de 2 bits a direita: b = %d\n", b);
    return 0;
}
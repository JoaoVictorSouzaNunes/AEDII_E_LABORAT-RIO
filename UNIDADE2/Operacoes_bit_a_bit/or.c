#include <stdio.h>

int main() {
    int a, b, c;
    a=15; //0000 0000 0000 0000 0000 0000 0000 1111
    b=-120; //1111 1111 1111 1111 1111 1111 1000 1000
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    c=a||b;
    printf("OU logico entre a e b: c = %d ('verdadeiro')\n", c);
    c=a|b; //1111 1111 1111 1111 1111 1111 1000 1111 = -113
    printf("OU bit a bit (OR) entre a e b: c = %d\n", c);

    int n=0; //0000 0000 0000 0000 0000 0000 0000 0000
    int bit1, bit2;
    printf("Escolha dois bits (0 a 32) para ativar: ");
    scanf("%d %d", &bit1, &bit2);
    n=n|(1<<bit1); //Ex. bit-8 --> 0000 0000 0000 0000 0000 0001 0000 0000 = 256
    n=n|(1<<bit2); //Ex. bit -13 --> 0000 0000 0000 0000 0010 0001 0000 0000 = 8192
    printf("n = %d\n", n);
    return 0;

}
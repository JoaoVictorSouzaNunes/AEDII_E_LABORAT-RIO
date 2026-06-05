#include <stdio.h>

int main() {
    int a, b, c;
    a=30; //0000 0000 0000 0000 0000 0000 0001 1110
    b=19; //0000 0000 0000 0000 0000 0000 0001 0011
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    c=a&&b;
    printf("E logico entre a e b: c = %d ('verdadeiro')\n", c);
    c=a&b; //0000 0000 0000 0000 0000 0000 0001 0010 = 18
    printf("E bit a bit (AND) entre a e b: c = %d\n", c);

    a=73; //0000 0000 0000 0000 0000 0000 0100 1001
    b=a&(1<<3); //Testar o quarto bit de a: 0000 0000 0000 0000 0000 0000 0000 1000 = 8
    if(b!=0) {
        printf("O bit-3 de %d esta ligado (1)\n", a);
    } else {
        printf("O bit-3 de %d esta desligado (0)\n", a);
    }

    int n=97; //0000 0000 0000 0000 0000 0000 0110 0001
    printf("O numero %d e ", n);
    if(n&1) { //0000 0000 0000 0000 0000 0000 0000 0001 = 1
        printf("impar\n");
    } else { //0000 0000 0000 0000 0000 0000 0000 0000 = 0
        printf("par\n");
    }
    // Mais eficiente que usar o operador de resto (%)
    return 0;
}
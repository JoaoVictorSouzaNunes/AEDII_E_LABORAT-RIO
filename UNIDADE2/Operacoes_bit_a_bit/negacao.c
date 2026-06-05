#include <stdio.h>

int main() {
    int a, b; //o ultimo bit (mais significativo) indica o sinal do numero (0 para positivo e 1 para negativo)
    a=9; //0000 0000 0000 0000 0000 0000 0000 1001
    printf("a = %d\n", a);
    b=!a;
    printf("Negacao logica de a: b = %d ('falso')\n", b);
    b=!b;
    printf("Negacao logica de b: c = %d('verdadeiro')\n", b);
    b=~a; //1111 1111 1111 1111 1111 1111 1111 0110 = -10 (complemento de 1)
    printf("Negacao bit a bit (NOT) de a: b = %d\n", b);
    return 0;
}
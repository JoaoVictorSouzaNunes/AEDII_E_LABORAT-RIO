#include <stdio.h>

int main() {
    int a, b;
    a=15; //0000 0000 0000 0000 0000 0000 0000 1111
    b=23; //0000 0000 0000 0000 0000 0000 0001 0111
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    int c=a^b; //0000 0000 0000 0000 0000 0000 0001 1000 = 8
    printf("OU exclusivo bit a bit (XOR) entre a e b: c = %d\n", c);

     int n=100; //0000 0000 0000 0000 0000 0000 0110 0100
     int bit;
     printf("n=%d\n", n);
     printf("Escolha um bit a ser invertido (0 a 32): ");
    scanf("%d", &bit);
    n=n^(1<<bit); //Ex. bit-30 --> 0000 0000 0000 0000 0100 0000 0110 0100 = 1073741828
    printf("n=%d\n", n);
    return 0;
}
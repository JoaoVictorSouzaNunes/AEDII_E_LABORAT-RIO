#include <stdio.h>
#include <stdlib.h>
#define M 10
#define K 3

unsigned long long hashjb2(const char *content, unsigned long long seed) {
    unsigned long long hash = 5381;
    int c;
    while ((c = *content++))
        hash += c*33*seed;
    return hash;
}


int getBit(const unsigned char* bitset, unsigned long long pos) {
    return (bitset[pos/8] >> (pos%8)) & 1;
}


void setBit(unsigned char* bitset, unsigned long long pos) {
    bitset[pos/8] |= (1 << (pos%8));
}


void bloomAdd(unsigned char *bitset, const char *content) {
    for(int i=0; i<K; i++) {
        unsigned long long pos = hashjb2(content, i) % M;
        setBit(bitset, pos);
    }
}


void printBitSet(const unsigned char* bitset) {
    for(int i=M-1; i>=0; i--) {
        printf("%d", getBit(bitset, i));
    }
}


int main() {
    unsigned char *bitset = (unsigned char *)calloc(M/8+1, sizeof(unsigned char));
    bloomAdd(bitset, "hello");
    printBitSet(bitset);

    return 0;
}
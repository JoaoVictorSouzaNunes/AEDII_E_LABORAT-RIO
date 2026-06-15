#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib1(int);
int fib2(int, int, int);
int Fib(int);

int main() {
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    int x;

    printf("No tail:\n");
    start=clock();
    //codigo a ser cronometrado
    x=fib1(45);
    end=clock();
    cpu_time_used=((double) (end-start))/CLOCKS_PER_SEC;
    printf("f(%d) = %d\n", 45, x);
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    printf("Tail:\n");
    start=clock();
    //codigo a ser cronometrado (tempo muito curto)
    x=Fib(45);
    end=clock();
    cpu_time_used=((double) (end-start))/CLOCKS_PER_SEC;
    printf("f(%d) = %d\n", 45, x);
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
    return 0;
}

//fibonacci recursivo (simples; sem cauda)
int fib1(int n) {
    if(n<=1) {
        return n;
    } else {
        return fib1(n-1)+fib1(n-2);
    }
}

int fib2(int n, int aux, int acc) {
    if(n==0) {
        return aux;
    } else if(n==1) {
        return acc;
    } else {
        aux+=acc;
        return fib2(n-1, acc, aux);
    }
}

int Fib(int n) {
    return fib2(n, 0, 1);
}

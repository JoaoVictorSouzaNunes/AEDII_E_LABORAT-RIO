#include <stdio.h>
#include <time.h>

int fib(int);
int fib2(int, int, int);
int main() {
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    int x;

    start=clock();
    //codigo a ser cronometrado
    x=fib2(5, 1, 0);
    end=clock();
    cpu_time_used=((double) (end-start))/CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
    printf("%d", x);
    return 0;
}

//fibonacci recursivo (simples; sem cauda)
int fib(int n) {
    if(n<=1) {
        return n;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int fib2(int n, int aux, int acc) {
    aux+=acc;
    if(n==0) {
        return acc;
    } else {
        return fib2(n-1, aux, acc+aux);
    }
}

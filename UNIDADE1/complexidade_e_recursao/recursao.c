#include <stdio.h>

int e_bissexto(int n) {
    if(n<=3) {
        if(n==0) return 1;
        else return 0;
    }
    return e_bissexto(n-4);
}

int p(int x, int n) {
    if(n==0) {
        return x;
    }
    int p1=p(x, n-1);
    return p1*(x-n);
}

int p_cauda(int x, int n, int acc) {
    if(n<0) {
        return acc;
    }
    return p_cauda(x, n-1, acc*(x-n));
}
//p_caude(x, n, 1)


int fat(int n, int acc) {
    if(n==0) return acc;
    return fat(n-1, acc*n);
}

int f(int n, int a, int b) {
    if(n==0) return a;
    if(n==1) return b;
    return f(n-1, b, 2*b+3*a);
}
//f(n, 1, 2)

int prod(int a, int b) {
    if(b==1) return a;
    return a+prod(a, b-1);

}

int div(int a, int b) {
    if(a<b) return 0;
    return 1+div(a-b, b);
}

int fib(int n) {
    if(n<=1) {
        return n;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int fib_tail(int n, int aux, int acc) {
    aux+=acc;
    if(n==0) {
        return acc;
    } else {
        return fib_tail(n-1, aux, acc+aux);
    }
}

int Fib(int n) {
    return fib_tail(n, 1, 0);
}

int main() {
    int v=p_cauda(4, 3, 1);
    printf("%d", v);
}
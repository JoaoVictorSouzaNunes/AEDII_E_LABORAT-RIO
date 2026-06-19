# tempo.c
Neste arquivo, são implementadas duas versões recursivas (com e sem cauda) de uma função que retorna os números de fibonnaci.

## Observações
**time.h:** É uma biblioteca padrão da linguagem C que possui estruturas de dados, constantes e funções para gerenciamento/manipulação de tempo. No nosso programa, destacamos algumas das estruturas mais importantes usadas:

- clock_t: Tipo de dado que representa a contagem de tiques do relógio (*Clock ticks*), uma unidade de tempo que indica o número de ciclos de um relógio interno usado pelo sistema. O valor de um clock tick depende do sistema usado, é por isso que ele é melhor do que usar int ou long, por exemplo, garantindo portabilidade do programa.

- CLOCKS_PER_SEC: constante macro que define o número de tiques por segundos, ou seja, cada CLOCKS_PER_SEC ciclos correspondem aproximadamente a 1 segundo

- clock(): Função que retorna um valor do tipo clock_t, que indica o tempo de CPU decorrido desde o inicio da execução do seu programa

Na linha abaixo, end-start retorna o tempo de CPU destinado a execução da função de fibonnaci, este valor é convertido (cast) em um valor do tipo double (ponto flutuante/real) para que a divisão seja completa, e não inteira. O resultado do casting é por fim dividido pela macro do número de ciclos/s, para retornar esse tempo em segundos
```C
cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
```

# recursao.c
Neste arquivo, é implementada uma lista de funções implementadas usando recursão

## 1. Ano bissexto

Implemente um algoritmo recursivo que determine se um ano é bissexto.

## 2. Produtório

Apresente um algoritmo de recursão com e sem cauda que execute a seguinte expressão:

```math
p(x,n)=\prod_{k=0}^{n}(x-k)
```

## 3. Tail
Apresente versões recursivas de cauda para cada uma das expressões abaixo:
### (a)

```math
f(n)=n!
```

### (b)

```math
f(n)=2f(n-1)+3f(n-2), \qquad f(0)=1,\; f(1)=2
```

### (c)

```math
\sum_{k=1}^{M} k
```

## 4. Trigonometria

Calcule $\sin(80)$ considerando como caso base:

```math
\sin(x)=x-\frac{x^3}{6}
```

e as seguintes relações:

```math
\sin(x)=\sin\left(\frac{x}{3}\right)
\left(
\frac{3-\tan^2\left(\frac{x}{3}\right)}
     {1+\tan^2\left(\frac{x}{3}\right)}
\right)
```

```math
\tan(x)=\frac{\sin(x)}{\cos(x)}
```

```math
\cos(x)=1-\sin\left(\frac{x}{2}\right)
```

## 5. Algoritmos recursivos

Implemente uma versão recursiva dos algoritmos abaixo:

### (a)

Somas sucessivas para calcular o produto de dois números.

### (b)

Divisão inteira entre dois números através de subtrações sucessivas.

### (c)

Verificação se uma palavra é um palíndromo.

### (d)

Inversão de uma string.

### (e)

Geração de todos os números da megasena (6 números entre 1 e 60).

## 6. Fibonacci

Implemente as versões com e sem cauda (*tail recursion*) do algoritmo que calcula o número de Fibonacci.

# Referências
https://www.ime.usp.br/~pf/algoritmos/apend/time.h.html
https://youtu.be/iQQeHIcUB_8?si=0g9f7ap7vk-xveol
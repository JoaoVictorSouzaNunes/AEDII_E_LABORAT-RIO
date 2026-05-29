# tempo.c

# tail.c
    1. Implemente um algoritmo recursivo que determine se um ano é bissexto
    2. Apresente um algoritmo de recurs˜ao com e sem cauda executa a seguinte expressão:
        $$
        p(x,n)=\prod_{k=0}^{n}(x-k)
        $$
    3. Apresente versões recursivas de cauda para cada uma das expressões abaixo:

        (a)

        $$
        f(n)=n!
        $$

        (b)

        $$
        f(n)=2f(n-1)+3f(n-2), \quad f(0)=1,\ f(1)=2
        $$

        (c)

        $$
        \sum_{k=1}^{M} k
        $$
    4. Calcule o \( \sin(80) \) considerando como caso base o resultado que

        $$
        \sin(x)=x-\frac{x^3}{6}
        $$

        e que:

        $$
        \begin{cases}
        \sin(x)=\sin\left(\frac{x}{3}\right)\left(\frac{3-\tan^2\left(\frac{x}{3}\right)}{1+\tan^2\left(\frac{x}{3}\right)}\right) \\
        \\
        \tan(x)=\frac{\sin(x)}{\cos(x)} \\
        \\
        \cos(x)=1-\sin\left(\frac{x}{2}\right)
        \end{cases}
        $$
    5. Implemente uma versão recursiva dos algoritmos abaixo:

        (a) Somas sucessivas para calcular o produto de dois números.

        (b) Divisão inteira entre dois números através de subtrações sucessivas.

        (c) Verificação se uma palavra é um palíndromo.

        (d) Inversão de uma string.

        (e) Geração de todos os números da megasena (6 números entre 1 e 60).
    6. Implemente as versões com e sem calda (tail) do algoritmo que calcula o número de fibonacci
É necessário ter cuidado com a escolha da estrutura de dados para armazenar os dados,
pois isso pode afetar o desempenho do programa. Além disso, a ordem com que os
dados são apresentados influenciam no tamanho da estrutura de dados, o que pode
impactar na eficiência do programa.

# Alinhamento e preenchimento de estruturas
Muitas vezes, o tamanho de uma estrutura não é igual ao tamanho dos seus membros. Na realidade, a struct é PREENCHIDA com alguns bits extras (PAD) para satisfazer restrições de ALINHAMENTO da memória: O computador lê dados usando o tamanho da "palavra" do sistema. Quando um dado esta alinhado na memória, o seu endereço fica em uma posição que é multipla do tamanho da "palavra"
## Por que alinhar os dados?
O alinhamento impacta no desempenho e funcionamento correto do programa. Sem o alinhamento, mais acessos a memória podem ser necessários para recuperar um dado (por exemplo, a operação de seleção em um array) . Para alinhar os dados, pode ser necessário inserir alguns bits não nomeados entre os dados (preenchimento ou padding)
- int: Num sistema 32-bits, precisa estar alinhado (4 bytes)
- char: Não tem preferência de alinhamento, podendo ser colocado no meio ou final de uma palavra
## estrutura01.c
Sem alinhamento, o tamanho da estrutura deveria ser sizeof(Estrutura01)==1+4+1==6 bytes. Porem, o espaço real ocupado é de 4+4+4==12 bytes (3 "palavras"). Exemplo: (Sistema 32-bits)
```txt
   | Variavel |   -    |   -    |   -    |   -    |
0  |          |        |        |        |        |
4  |          |        |        |        |        |
8  |     b    |   x    |  PAD   |  PAD   |  PAD   |
12 |     a    |   x    |   x    |   x    |   x    |
16 |     c    |   x    |  PAD   |  PAD   |  PAD   |
20 |          |        |        |        |        |
...
```
## estrutura 02.c
Como caracteres não tem preferência de alinhamento, ambos podem ocupar a mesma palavra, diminuindo a quantidade de bits extras adicionados. Assim a estrutura fica com tamanho otimizado de 4+4==8 bytes (2 "palavras") Exemplo: (Sistema 32-bits)
```txt
   | Variavel |   -    |   -    |   -    |   -    |
0  |          |        |        |        |        |
4  |     a    |   x    |   x    |   x    |   x    |
8  |  b e c   |   x    |   x    |  PAD   |  PAD   |
12 |          |        |        |        |        |
16 |          |        |        |        |        |
20 |          |        |        |        |        |
...
```
Em geral, os membros da struct seguem o alinhamento do MAIOR membro. Por exemplo, se o maior membro for do tipo short int (sizeof(short)==2 bytes), então os dados se alinham de 2 em 2 bytes.


# Referências
https://youtu.be/COGGLrAJJGU
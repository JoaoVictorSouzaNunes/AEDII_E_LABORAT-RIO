O objetivo desta seção é implementar mini-projetos práticos de estruturas de dados, particularmente envolvendo tabela hashing (dispersão/emparelhamento). Cada um deles aborda diferentes conceitos de hash aplicados em contextos reais, salientando vantagens e otimizações resultantes do uso da estrutura.

# Proj1
Nessa estrutura, a Tabela Hash foi implementada com um tratamento de colisões por encadeamento exterior, ou seja, cada posição da tabela armazena o endereço  de uma lista encadeada que armazena todos os elementos cujo endereço-base se encontra naquela posição da tabela.
## Estrutura da HashTable
Definida em hash.h, esta estrutura armazena:
-O tamanho da tabela (definido na sua criação);
-O número de posições usadas
-A quantidade de elementos armazenados;
-Um ponteiro para um ponteiro de uma estrutura Lista (Lista**), visto que este campo da estrutura deve armazenar um endereço para a tabela em si (um vetor dinâmico). Por questão de desempenho, evitando gasto excessivo de memória, este vetor irá armazenar apenas o endereço para a estrutura do tipo Lista.
Exemplo:
```text
                    HashTable ht
        ┌───────────────────────────┐
        │          tabela           │────────────────┐
        ├───────────────────────────┤                │
        │          tamanho          │                │
        ├───────────────────────────┤                │
        │         ocupacao          │                │
        ├───────────────────────────┤                │
        │            qtd            │                │
        └───────────────────────────┘                ▼

                                           ┌──────────┐  0
                                           │   NULL   │
                                           ├──────────┤  1
                                           │   NULL   │
                                           ├──────────┤  2
                                           │   NULL   │
                                           ├──────────┤  3
                                           │   NULL   │
                                           ├──────────┤  4
                                           │   NULL   │
                                           ├──────────┤
                                           │    .     │
                                           │    .     │
                                           │    .     │
                                           ├──────────┤
                                           │   NULL   │
                                           ├──────────┤
                                           │   NULL   │   tamanho-1
                                           └──────────┘
```
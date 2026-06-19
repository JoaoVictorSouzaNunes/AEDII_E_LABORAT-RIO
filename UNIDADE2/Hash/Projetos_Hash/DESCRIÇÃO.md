O objetivo desta seção é implementar mini-projetos práticos de estruturas de dados, particularmente envolvendo tabela hashing (dispersão/emparelhamento). Cada um deles aborda diferentes conceitos de hash aplicados em contextos reais, salientando vantagens e otimizações resultantes do uso da estrutura.

# Proj1
Nessa projeto, a Tabela Hash foi implementada com um tratamento de colisões por encadeamento exterior, ou seja, cada posição da tabela armazena o endereço  de uma lista encadeada que armazena todos os elementos cujo endereço-base se encontra naquela posição da tabela.

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

## Dimensão/tamanho da tabela
Experimentalmente, temos alguns resultados sobre a escolha do tamanho de uma tabela hashing que melhoram sua eficiência, reduzindo o número de colisões, como:

- Escolher um número primo não próximo de 2
- Escolher um número primo que não possua divisores primos pequenos (<20)

A escolha do tamanho é feita então com base nesses resultados e nos valores obtidos em *tests*, principalmente *teste_hash.c* e *teste_colisoes.c*

## Função Hash
A função hash escolhida foi a mais simples e direta, chamado de "Método da divisão" ou "Metódo da congluência linear", consiste em determinar a função hash calculando o resto da divisão (*%*) entre o valor-chave k e o tamanho da tabela m, mapeando o elemento para alguma posição dentro da tabela
```math
h(k)=k\%m
```

## Observações
Para incluir os arquivos de cabeçalho em *include* nos codigos-fontes em *src*, a forma mais correta seria, por exemplo:
```C
#include "../include/hash.h"
```
onde $../$ indica que os cabeçalhos estão no diretório pai do diretório onde estão os arquivos *.c*. Mas, na realidade, não precisamos nos preocupar com essa troca de diretórios no programa se a compilação for feita de forma automatica pelo Makefile, por exemplo:
```text
gcc main.c -Wall -Wextra -Iinclude -o main
```
onde $-Wall$ e $-Wextra$ são flags que habilitam todos os avisos do compilador e avisos adicionais, $-o$ permite nomear o arquivo executavel (*main.exe*) e $-Iinclude$ adiciona o diretório *include* a lista de diretórios pesquisados na busca por arquivos definido por *#include* no programa. Todas essas flags são executadas quando a compilação é feita usando o arquivo makefile, assim, a inclusão dos cabeçalhos pode ser feita da forma normal, por exemplo:
```C
#include "hash.h"
```

Ademais, na leitura dos arquivos de texto (txt) em *data* é usada a função fscanf(), que lê dados formatados dos arquivos, retornando o número de valores lidos com sucesso ou EOF (End-Of-Life) ao chegar no final do arquivo. No entanto, é preciso ter cuidado no formato do texto lido, pois não funcionaria por exemplo:
```C
fscanf(file, "%s;%s;%s;%s\n", aeroporto.codigo, aeroporto.nome, aeroporto.cidade, aeroporto.pais)
```
Visto que *%s* lê ate encontrar o primeiro espaço ou quebra de linha (*\n*), não parando ao encontrar ";". Para evitar isso, usamos o formatador *%[^]* que termina a leitura assim que encontrar o caracter especificado apos ^
```C
fscanf(file, "%[^;];%[^;];%[^;];%[^;\n]\n", aeroporto.codigo, aeroporto.nome, aeroporto.cidade, aeroporto.pais)
```

# Referências
https://youtu.be/o0TXB3QPOWY?si=r9p73D8GFVvgJTh_

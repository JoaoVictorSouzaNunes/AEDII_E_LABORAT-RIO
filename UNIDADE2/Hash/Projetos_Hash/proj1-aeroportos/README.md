# Sistema de Consulta de Aeroportos

Projeto desenvolvido em linguagem C para prática de Estruturas de Dados, com foco em implementação de Tabela Hash com Encadeamento Exterior.

---

# Objetivo

O sistema realiza armazenamento e consulta de aeroportos utilizando uma tabela hash com tratamento de colisões por encadeamento externo, garantindo:

- inserções eficientes;
- buscas rápidas;
- organização dinâmica dos dados;
- tratamento adequado de colisões.

---

# Contexto

Sistemas de aviação precisam acessar rapidamente informações de aeroportos através de códigos únicos IATA, como:

- GRU
- GIG
- JFK
- CDG

Como múltiplos códigos podem gerar o mesmo índice na tabela hash, o sistema utiliza listas encadeadas para armazenar colisões no mesmo compartimento da tabela.

---

# Estrutura do Projeto

```text
proj1-aeroportos/
│
├── README.md
├── Makefile
│
├── data/
│   ├── aeroportos.txt
│   └── testes.txt
│
├── include/
│   ├── aeroporto.h
│   ├── hash.h
│   ├── lista.h
│   └── utils.h
│
├── src/
│   ├── main.c
│   ├── aeroporto.c
│   ├── hash.c
│   ├── lista.c
│   └── utils.c
│
├── docs/
│   ├── relatorio.md
│   └── analise_desempenho.md
│
└── tests/
    ├── teste_hash.c
    ├── teste_busca.c
    └── teste_colisoes.c
```

---

# Funcionalidades

- Carregamento de aeroportos via arquivo
- Inserção na tabela hash
- Tratamento de colisões com encadeamento externo
- Busca de aeroportos
- Remoção lógica
- Exibição da tabela
- Estatísticas da hash
- Testes de colisão

---

# Estrutura do Aeroporto

```c
typedef struct {
    char codigo[4];
    char nome[100];
    char cidade[50];
    char pais[50];
} Aeroporto;
```

---

Cada posição da tabela aponta para o início de uma lista encadeada.

---

# Funcionamento do Encadeamento Externo

Quando ocorre colisão:

```text
GRU -> índice 5
GIG -> índice 5
```

Os aeroportos são armazenados em uma lista encadeada:

```text
tabela[5]
   ↓
[GRU] -> [GIG] -> NULL
```

---

# Formato do Arquivo de Dados

O arquivo `aeroportos.txt` utiliza o seguinte padrão:

```text
CODIGO;NOME;CIDADE;PAIS
```

Exemplo:

```text
GRU;Aeroporto Internacional de Guarulhos;São Paulo;Brasil
```

---

# Compilação

## Linux / WSL / MSYS2

```bash
make
```

## Windows com MinGW

```bash
mingw32-make
```

---

# Executar

## Linux / WSL / MSYS2

```bash
make run
```

## Windows com MinGW

```bash
mingw32-make run
```

---

# Exemplo de Uso

```text
=========== SISTEMA ===========
1 - Buscar aeroporto
2 - Exibir tabela
3 - Estatísticas
4 - Remover aeroporto
0 - Sair
```

---

# Objetivos de Estrutura de Dados

Este projeto trabalha:

- Tabelas Hash
- Encadeamento externo
- Funções de dispersão
- Listas encadeadas
- Busca em listas
- Modularização
- Manipulação de arquivos
- Strings em C

---

# Tratamento de Colisões

O projeto utiliza encadeamento externo para tratar colisões.

Cada posição da tabela hash armazena uma lista encadeada contendo todos os elementos que geraram o mesmo índice.

---

# Estrutura Esperada da Tabela

Exemplo:

```text
[0] -> NULL
[1] -> [JFK] -> NULL
[2] -> [GRU] -> [GIG] -> NULL
[3] -> [CDG] -> NULL
```
---
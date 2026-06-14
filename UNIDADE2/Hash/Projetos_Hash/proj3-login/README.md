# Login Hash

## Sistema de Gerenciamento de Usuários utilizando Tabela Hash com Sondagem Linear

## Aplicação Utilizada

**Sistema de Login de Usuários**

---

# 1. Descrição

O Login Hash é um sistema desenvolvido na linguagem C para gerenciamento de contas de usuários.

O projeto simula funcionalidades comuns encontradas em plataformas digitais, como:

* cadastro de usuários;
* autenticação (login);
* consulta de contas;
* alteração de senha;
* remoção de usuários.

O principal objetivo é estudar a estrutura de dados **Tabela Hash com tratamento de colisões por Sondagem Linear**, analisando seu comportamento sob diferentes níveis de ocupação.

---

# 2. Problema

Plataformas digitais podem possuir milhares de usuários cadastrados.

Durante o processo de autenticação é necessário localizar rapidamente um usuário a partir de seu username.

Sem uma estrutura adequada, o sistema precisaria percorrer todos os registros cadastrados.

Exemplo:

```text
joao123
maria456
pedro789
ana321
...
```

Utilizando uma tabela hash, a localização dos usuários torna-se significativamente mais eficiente.

---

# 3. Objetivos

## Objetivo Geral

Implementar um sistema de login utilizando tabela hash com tratamento de colisões por sondagem linear.

## Objetivos Específicos

* Implementar uma função hash para strings;
* Implementar inserção em tabela hash;
* Implementar busca em tabela hash;
* Implementar remoção lógica;
* Implementar autenticação de usuários;
* Implementar estatísticas de desempenho;
* Avaliar colisões e fator de carga.

---

# 4. Estrutura de Dados Utilizada

A estrutura principal do projeto é uma tabela hash implementada sobre um vetor.

Cada posição da tabela pode assumir três estados:

| Estado   | Significado                   |
| -------- | ----------------------------- |
| VAZIO    | Posição nunca utilizada       |
| OCUPADO  | Registro válido               |
| REMOVIDO | Registro removido logicamente |

Quando ocorre colisão, utiliza-se **Sondagem Linear**.

Exemplo:

```text
hash("joao123") % 11 = 5

[5] ocupado
↓
[6] ocupado
↓
[7] livre
```

O elemento é inserido na posição 7.

---

# 5. Funcionalidades

## Cadastrar Usuário

Insere um novo usuário na tabela hash.

Exemplo:

```text
CADASTRAR joao123 senha123 joao@email.com
```

Restrições:

* o username deve ser único;
* não é permitido cadastrar usuários duplicados.

---

## Login

Realiza autenticação de usuários.

Exemplo:

```text
LOGIN joao123 senha123
```

Saídas possíveis:

```text
LOGIN REALIZADO
```

ou

```text
USUARIO OU SENHA INVALIDOS
```

---

## Consultar Usuário

Exibe as informações cadastradas de um usuário.

Exemplo:

```text
CONSULTAR joao123
```

---

## Alterar Senha

Atualiza a senha de um usuário existente.

Exemplo:

```text
ALTERAR_SENHA joao123 novaSenha
```

---

## Remover Usuário

Remove logicamente um usuário da tabela.

Exemplo:

```text
REMOVER joao123
```

A posição deve ser marcada como removida, preservando o funcionamento correto das buscas.

---

## Listar Usuários

Exibe todos os usuários armazenados na tabela.

Exemplo:

```text
LISTAR
```

---

## Estatísticas

Exibe informações que permitam analisar o comportamento da tabela hash durante a execução do sistema.

### Informações exibidas

#### Usuários cadastrados

Quantidade atual de usuários válidos armazenados na tabela.

#### Capacidade da tabela

Quantidade total de posições da tabela hash.

#### Posições ocupadas

Quantidade de posições contendo registros válidos.

#### Posições livres

Quantidade de posições ainda disponíveis.

#### Fator de carga

Razão entre usuários cadastrados e capacidade da tabela.

#### Colisões totais

Quantidade total de colisões ocorridas durante as inserções.

#### Inserções realizadas

Quantidade total de operações de inserção executadas.

#### Média de colisões por inserção

Média de colisões ocorridas por inserção.

#### Total de sondagens

Quantidade total de posições verificadas devido à sondagem linear.

#### Média de sondagens por operação

Quantidade média de posições verificadas em cada operação.

#### Maior cluster

Maior sequência contínua de posições ocupadas na tabela.

### Exemplo de saída

```text
Usuarios cadastrados: 152

Capacidade da tabela: 211

Posições ocupadas: 152

Posições livres: 59

Fator de carga: 0.7204

Colisões totais: 37

Inserções realizadas: 152

Média de colisões por inserção: 0.2434

Total de sondagens: 194

Média de sondagens por operação: 1.2763

Maior cluster: 8 posições
```

---

# 6. Estruturas Principais

## Usuário

```c
typedef struct {
    char username[30];
    char senha[30];
    char email[80];

    int estado;
} Usuario;
```

Estados possíveis:

```c
#define VAZIO 0
#define OCUPADO 1
#define REMOVIDO 2
```

---

# 7. Estrutura do Projeto

```text
login_hash/
│
├── include/
│   ├── hash.h
│   ├── usuario.h
│   └── sistema.h
│
├── src/
│   ├── main.c
│   ├── hash.c
│   ├── usuario.c
│   └── sistema.c
│
├── data/
│   ├── usuarios.txt
│   └── comandos.txt
│
├── tests/
│   ├── teste_hash.c
│   ├── teste_login.c
│   ├── teste_remocao.c
│   └── teste_colisoes.c
│
├── docs/
│   └── relatorio.md
│
├── README.md
└── Makefile
```

---

# 8. Arquivo de Entrada

Exemplo de comandos:

```text
CADASTRAR joao123 senha123 joao@email.com
CADASTRAR maria456 abc123 maria@email.com

LOGIN joao123 senha123

CONSULTAR maria456

ALTERAR_SENHA joao123 novaSenha

REMOVER maria456

ESTATISTICAS
```

---

# 9. Compilação

Utilizando GCC:

```bash
gcc src/*.c -Iinclude -o login_hash
```

Ou utilizando Makefile:

```bash
make
```

---

# 10. Execução

```bash
./login_hash
```

---

# Conceitos de Estruturas de Dados Trabalhados

* Tabela Hash
* Sondagem Linear
* Funções Hash
* Tratamento de Colisões
* Remoção Lógica
* Fator de Carga
* Clusterização Primária
* Modularização em C
* Avaliação Experimental de Desempenho

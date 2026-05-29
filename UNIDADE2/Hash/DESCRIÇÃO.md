# Tabela Hash sem Tratamento de Colisão

## Objetivo

Implementar uma tabela hash simples sem tratamento de colisões.

Este projeto demonstra a forma mais básica de hashing,
onde cada chave é mapeada diretamente para uma posição da tabela.

A implementação assume:
- ausência de colisões;
- tamanho fixo da tabela;
- chaves únicas.

---

## Aplicação

### Sistema de Controle de Sensores

Um sistema embarcado de monitoramento industrial
precisa armazenar leituras de sensores em posições fixas da memória.

Cada sensor possui:
- ID numérico;
- tipo;
- valor da última leitura.

Como a quantidade de sensores é limitada e seus IDs são previamente definidos,
cada sensor pode ser armazenado diretamente em uma posição específica da tabela.

O objetivo é permitir:
- acesso extremamente rápido;
- baixo custo computacional;
- simplicidade estrutural.

---

## Conceitos praticados

- hashing básico;
- acesso direto;
- indexação em vetores;
- busca em tempo constante;
- mapeamento direto de memória.

---

## Operações

- registrar sensor;
- atualizar leitura;
- buscar sensor;
- remover sensor;
- mostrar tabela.

---

## Função Hash


## Exemplo

Tamanho da tabela:
10

ID do sensor:
23

Hash:
23 % 10 = 3

Sensor armazenado em:
table[3]

---

## Saída esperada

[0] VAZIO
[1] Sensor Temperatura
[2] VAZIO
[3] Sensor Pressão
[4] VAZIO

---

## Compilação

gcc main.c hash.c -o app

---

## Execução

./app
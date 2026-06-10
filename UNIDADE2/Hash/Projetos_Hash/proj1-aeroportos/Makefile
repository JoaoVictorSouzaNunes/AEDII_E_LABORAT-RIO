# ==============================
# CONFIGURACOES DO COMPILADOR
# ==============================

CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

# ==============================
# DIRETORIOS
# ==============================

SRC_DIR = src
TEST_DIR = tests

# ==============================
# ARQUIVOS PRINCIPAIS
# ==============================

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/hash.c \
	  $(SRC_DIR)/lista.c \
      $(SRC_DIR)/aeroporto.c \
      $(SRC_DIR)/utils.c

# ==============================
# EXECUTAVEL PRINCIPAL
# ==============================

TARGET = hash

# ==============================
# COMPILACAO PRINCIPAL
# ==============================

all:
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

# ==============================
# EXECUTAR O PROGRAMA
# ==============================

run: all
	./$(TARGET)

# ==============================
# TESTE DA HASH
# ==============================

teste_hash:
	$(CC) $(TEST_DIR)/teste_hash.c \
	$(SRC_DIR)/lista.c \
	$(SRC_DIR)/hash.c \
	$(SRC_DIR)/utils.c \
	$(CFLAGS) -o teste_hash

# ==============================
# TESTE DE BUSCA
# ==============================

teste_busca:
	$(CC) $(TEST_DIR)/teste_busca.c \
	$(SRC_DIR)/lista.c \
	$(SRC_DIR)/hash.c \
	$(SRC_DIR)/aeroporto.c \
	$(SRC_DIR)/utils.c \
	$(CFLAGS) -o teste_busca

# ==============================
# TESTE DE COLISOES
# ==============================

teste_colisoes:
	$(CC) $(TEST_DIR)/teste_colisoes.c \
	$(SRC_DIR)/lista.c \
	$(SRC_DIR)/hash.c \
	$(SRC_DIR)/utils.c \
	$(CFLAGS) -o teste_colisoes

# ==============================
# LIMPEZA DOS EXECUTAVEIS
# ==============================

clean:
	rm -f $(TARGET)
	rm -f teste_hash
	rm -f teste_busca
	rm -f teste_colisoes

# ==============================
# AJUDA
# ==============================

help:
	@echo "Comandos disponiveis:"
	@echo " make                -> Compila o programa principal"
	@echo " make run            -> Compila e executa"
	@echo " make teste_hash     -> Compila teste da hash"
	@echo " make teste_busca    -> Compila teste de busca"
	@echo " make teste_colisoes -> Compila teste de colisoes"
	@echo " make clean          -> Remove executaveis"